//=================================================================================
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define PI 3.14159265358979323846

struct ode{
    double k_1[2]; // holds info for x at index 0 and p  atindex 1
    double k_2[2];
    double k_3[2];
    double k_4[2];
    double x_n;
    double p_n;
};

void runge_kutta_4_update(struct ode* ode,double h, double mass, 
    double (*func_x)(double,double),double (*func_p)(double));
double p_dot(double x);
double x_dot(double p,double mass);
void free_ode(struct ode* ode);
bool full_period(double i_d, double value);


int main(int argc, char **argv){
 double intial_displacement =  atof(argv[1]);
 double mass = 1.0;
 double intial_momentum = 0.0;
 double intervals = 100;
 struct ode* ode_harmonic = malloc(sizeof(struct ode));
 ode_harmonic->x_n = intial_displacement;
 ode_harmonic->p_n = intial_momentum;
 double h = intial_displacement/intervals;
 int i = 1;
 bool past_zero = false;
 printf("Time \t x \t p\n");
 while( !past_zero || full_period(intial_displacement,ode_harmonic->x_n) ){
     runge_kutta_4_update(ode_harmonic,h,mass,x_dot,p_dot);
     printf("%f \t %f \t %f\n",(double)i*h,ode_harmonic->x_n,ode_harmonic->p_n );
     if(ode_harmonic->x_n < 0 ){past_zero=true;}
     i+=1;
     //printf("%.4f\n",pow(ode_harmonic->x_n,4)/4 + pow(ode_harmonic->p_n,2)/2 ); 
     // is energy conserved?
 }  
 free(ode_harmonic);
 return 0;
}

void runge_kutta_4_update(struct ode* ode,double h, double mass, 
    double (*func_x)(double,double), double (*func_p)(double)){
    //Update k_1
    ode->k_1[0] = (*func_x)(ode->p_n,mass);
    ode->k_1[1] = (*func_p)(ode->x_n);
    
    //Update k_2
    ode->k_2[0] = (*func_x)(ode->p_n + (h/2)*ode->k_1[1],mass);
    ode->k_2[1] = (*func_p)(ode->x_n + (h/2)*ode->k_1[0]);
    
    //Update k_3
    ode->k_3[0] = (*func_x)(ode->p_n + (h/2)*ode->k_2[1],mass);
    ode->k_3[1] = (*func_p)(ode->x_n + (h/2)*ode->k_2[0]);

    //Update k_4
    ode->k_4[0] = (*func_x)(ode->p_n + h*ode->k_3[1],mass);
    ode->k_4[1] = (*func_p)(ode->x_n + h*ode->k_3[0]);

    //Update parameters
    ode->x_n = ode->x_n +(h/6)*(ode->k_1[0] + 2*(ode->k_2[0] + ode->k_3[0])
     + ode->k_4[0]);
    ode->p_n = ode->p_n +(h/6)*(ode->k_1[1] + 2*(ode->k_2[1] + ode->k_3[1])
     + ode->k_4[1]);
    //printf("y_n = %f  k_1 = %f k_2 = %f\n",ode->y_n,ode->k_1, ode->k_2 );

}
//differential functions
double x_dot(double p,double mass){
    return  p/mass;
}

double p_dot(double x){
    return -1.0*pow(x,3);
}

bool full_period(double intial_displacement, double value){
      return (fabs(intial_displacement - value) > (1/pow(10,3)));
}
//=================================================================================
