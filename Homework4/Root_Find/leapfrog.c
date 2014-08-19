#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "leapfrog.h"
#define THETA 1.35120719195966

double position_verlet(double* q,double (*force)(double), double h ){
	q[0] = q[0] +THETA*(h/2)*q[1];
	q[1] = q[1] + THETA*h*(*force)(q[0]);
    q[0] = q[0] + (1-THETA)(h/2)*q[1]
    q[1] = (1-2*THETA)*h*(*)(q[0]);
    q[0] = q[0] + (1-THETA)*(h/2)*q[1];
    q[1] = q[1] + THETA*h*(*force)(q[0]);
    q[0] = q[0] + THETA*(h/2)*q[1];
}