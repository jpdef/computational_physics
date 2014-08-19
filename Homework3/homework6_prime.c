//=================================================================================
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rk4.h"
#define PI 3.14159265358979323846



double p_dot(double x);
double x_dot(double p);
void derivatives(double* q,double* k);
bool full_period(double i_d, double value);
double calculate_period(double x, double t, double previous, double h );

int main(int argc, char **argv){
 double intial_displacement =  atof(argv[1]);
 double mass = 1.0;
 double intial_momentum = 0.0;
 double intervals = 1000;
 double h = intial_displacement/intervals;
 int i = 1;
 bool past_zero = false;

 ODE ode_harmonic;
 ode_harmonic = new_ODE(2);
 setq(ode_harmonic,0,intial_displacement);
 setq(ode_harmonic,1,intial_momentum);
 set_func(ode_harmonic,derivatives);
 

printf("Time \t x \t p\n");
 while( !past_zero || full_period(intial_displacement, getq(ode_harmonic,0)) ){
     double previous = getq(ode_harmonic,0);
     runge_kutta_4_update(ode_harmonic,h);
     printf("%f \t %f \t %f\n",(double)i*h, getq(ode_harmonic,0), getq(ode_harmonic,1) );
     if(getq(ode_harmonic,0) < 0 && !past_zero ){
        past_zero=true; 
       // printf(" Period = %.8f\n",calculate_period(getq(ode_harmonic,0),i*h,previous,h));
        //break; 
    }
     i+=1;
     //printf("%.4f\n",pow(getq(ode_harmonic,0),4)/4 + pow(ode_harmonic->p_n,2)/2 ); 
     // is energy conserved?
 }  
 return 0;
}

void derivatives(double* q,double* k){
    //takes points to evaluate the derivative sends it to k value
    k[0] = x_dot(q[1]);
    k[1] = p_dot(q[0]);
}

//differential functions
double x_dot(double p){
    return  p;
}

double p_dot(double x){
    return -1.0*pow(x,3);
}

double calculate_period(double x, double t, double previous, double h ){
    return 4* (t- ((x-previous)/2)) ; 
    // linear approximation of first zero point multiplied by four to get full period
}

bool full_period(double intial_displacement, double value){
      return (fabs(intial_displacement - value) > (1/pow(10,3)));
}
//=================================================================================
