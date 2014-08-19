#include <stdio.h>
#include <math.h>

#ifndef _INTEGRATION_H_INCLUDE_
#define _INTEGRATION_H_INCLUDE_
double simp(double a, double b, double (*func)(double),double n);
double mid_point(double a, double b, double (*func)(double),double n);
double zoid(double a, double b, double (*func)(double),double n);
double romb(double a, double b,  double(*func)(double), double precision);


#endif