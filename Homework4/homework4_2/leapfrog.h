#include <stdio.h>
#include <math.h>

#ifndef _LEAPFROG_H_INCLUDE_
#define _LEAPFROG_H_INCLUDE_
void position_verlet(double* q,double (*force)(double), double h );
#endif