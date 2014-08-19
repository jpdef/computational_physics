#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rk4.h"
#define PI 3.14159265358979323846

void derivate(double* q,double* k);

int main(int argc, char **argv){
    ODE ode = new_ODE(1);
    int n = 100;
    double h = PI/(4* (double)n);
    setq(ode,0,1.0);
    setq(ode,0,0.0);
    set_func(ode, derivate);
    for (int i = 0; i < n; ++i){
        runge_kutta_4_update(ode, h);
        printf("%f \t %1.12e\n",(double)i*h, getq(ode,0));
    }
     printf("Value = %1.12e Error = %1.12e h^4 = %1.12e\n",getq(ode,0), 1- getq(ode,0), pow(h,4.0) );
 return 0;
}

//y is a function of x


void derivate(double* q, double* k){
    k[0] = 1.0 + pow(q[0],2);
}

