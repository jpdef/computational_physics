#include <stdio.h>
#include <math.h>

#ifndef _ROOT_FIND_H_INCLUDE_
#define _ROOT_FIND_H_INCLUDE_
double bisection(double (*func)(double), double x_l , double x_r,double digits_precision);
double newt_raph(double (*func)(double),double x_n_1, double x_n);
double secant(double x_1, double x_2, double (*func)(double));
#endif