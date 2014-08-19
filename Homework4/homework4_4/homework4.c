#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "rk4.h"
#define PI 3.14159265358979323846

double potential(double x);
void differential_func(double* parameters, double* result,double x);

int main(int argc, char **argv){
	double intial_amplitude= 0.0;
	double intial_amp_velocity =1.0;
	double h[4] = {0.2,.1,.05,.025};
    ODE wave_eq = new_ODE(2);
    set_func(wave_eq,differential_func);
    for(int k = 0; k<4;k++){
       printf("Step size equals %f\n",h[k] );
       printf("-----------------------------------------------------\n");
       double position = 0.0;
       setq(wave_eq,0,intial_amplitude);
       setq(wave_eq,1,intial_amp_velocity);
       for (int i = 0; i <= (int)(1.0/h[k]); ++i)
       {
    	printf("x = %f \t psi = %f psi_prime = %f \n",position,getq(wave_eq,0),getq(wave_eq,1) );
    	position+= h[k];
    	runge_kutta_4_update(wave_eq,h[k],position);
       }
       printf("\n \n");
    }
	return 0;
}

void differential_func(double* parameters, double* result,double x){
	result[0] = parameters[1];
	result[1] = -(pow(PI,2))*parameters[0];
}

double potential(double x){
	if(x>0 && x<1){
		return 0;
	}else{
		return INFINITY;
	}
}

