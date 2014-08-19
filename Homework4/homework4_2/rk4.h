#include <stdio.h>
#include <math.h>

#ifndef _RK4_H_INCLUDE_
#define _RK4_H_INCLUDE_

typedef struct odeobj* ODE;
void runge_kutta_4_update(ODE ode,double h);
ODE new_ODE(int q);

void setq(ODE ode, int i, double value);
void setk_1(ODE ode, int i, double value);
void setk_2(ODE ode, int i, double value);
void setk_3(ODE ode, int i, double value);
void setk_4(ODE ode, int i, double value);
void set_func(ODE ode,void (*func)(double*,double*));

double getq(ODE ode, int i);
double getk_1(ODE ode, int i);
double getk_2(ODE ode, int i);
double getk_3(ODE ode, int i);
double getk_4(ODE ode, int i);

#endif
