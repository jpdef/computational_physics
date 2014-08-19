#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "leapfrog.h"
#include "rk4.h"
#define PI 3.14159265358979323846
#define PERIOD 7.41633414

double force(double x);
void derivatives(double* x, double* y);

int main(int argc, char **argv){
    FILE *f = fopen("output.txt","w");

    //intialize PERFL variables
    double* q = calloc(2, sizeof(double));
    q[0] = 1.0;
    q[1] = 0.0;
    //intialize rk4 variables
    ODE rk4 = new_ODE(2);
    setq(rk4,0,1.0);
    setq(rk4,1,0.0);
    set_func(rk4, derivatives);
    
    double h = .02*PERIOD;
    double step_limit;
    double energy_rk,energy_lf,max_dev_lf,max_dev_rk ;
    energy_rk = energy_lf =  max_dev_lf = max_dev_rk = 0.0;
    
    printf("How many periods: ");
    scanf("%lf",&step_limit);
    step_limit = step_limit*50;

    fprintf(f,"t/T \t E_L \t E_K  \n");
    for (int i = 0;i<=step_limit;i++){
        runge_kutta_4_update(rk4, h);
        energy_rk = pow(getq(rk4,0),4)/4.0 + pow(getq(rk4,1),2)/2.0;
        position_verlet(q,force,h);
        energy_lf= pow(q[0],4)/4.0 + pow(q[1],2)/2.0;
        double dev_lf =fabs(energy_lf-0.25);
        double dev_rk =fabs(energy_rk-0.25);
        if(dev_rk > max_dev_rk){max_dev_rk=dev_rk;}
        if(dev_lf > max_dev_lf){max_dev_lf=dev_lf;}
        fprintf(f,"%f \t %.12f \t %.12f \n",(i*h),dev_lf,dev_rk);

    }
    printf("Maximum deviation for PEFRL = %f\n",max_dev_lf);
    printf("Maximum deviation for runge-kutta = %f\n",max_dev_rk) ;
    return 0;

}
void derivatives(double* y, double* x){
    x[0] = y[1]; //x dot
    x[1] = -pow(y[0],3); // p dot
}


double force(double x){
    return -1.0*pow(x,3);
}

