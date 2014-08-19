//=================================================================================
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rk4.h"
#define PI 3.14159265358979323846

struct odeobj{
    double *k_1; 
    double *k_2;
    double *k_3;
    double *k_4;
    double *q_n;
    void (*function)(double*,double*);
    int q;
}odeobj;

typedef struct odeobj* ODE;


void runge_kutta_4_update(ODE ode,double h){
    //Update k_1
    double* derivates_eval = malloc((ode->q)*sizeof(double));
    for(int i = 0; i < ode->q ; i++){
        derivates_eval[i] = ode->q_n[i];
    }
    (ode->function)(derivates_eval,ode->k_1);
    
    //Update k_2
    for(int i = 0; i < ode->q ; i++){
        derivates_eval[i] = ode->q_n[i]+(h/2)*ode->k_1[i];
    }
    (ode->function)(derivates_eval,ode->k_2);

    
    //Update k_3
    for(int i = 0; i < ode->q ; i++){
        derivates_eval[i] = ode->q_n[i]+(h/2)*ode->k_2[i];
    }
    (ode->function)(derivates_eval,ode->k_3);

    //Update k_4
    for(int i = 0; i < ode->q ; i++){
        derivates_eval[i] = ode->q_n[i]+h*ode->k_3[i];
    }
    (ode->function)(derivates_eval,ode->k_4);

    //Update coordinates
    for(int i = 0; i < ode->q ; i++){
        ode->q_n[i] = ode->q_n[i] +(h/6)*(ode->k_1[i] + 2*(ode->k_2[i] + ode->k_3[i])
     + ode->k_4[i]);
    }
    free(derivates_eval);

}




void setq(ODE ode, int i,double value){
    ode->q_n[i] = value ;
}

void setk_1(ODE ode, int i,double value){
    ode->k_1[i] = value;
}
void setk_2(ODE ode, int i,double value){
     ode->k_2[i] = value;
}
void setk_3(ODE ode, int i, double value){
     ode->k_1[i] = value;
}
void setk_4(ODE ode, int i, double value){
    ode->k_1[i] = value;
}
void set_func(ODE ode, void (*func)(double*,double*)){
     ode->function = func;
}


double getq(ODE ode, int i){
    double q = ode->q_n[i];
    return q;
}

double getk_1(ODE ode, int i){
    return ode->k_1[i];
}
double getk_2(ODE ode, int i){
    return ode->k_2[i];
}
double getk_3(ODE ode, int i){
    return ode->k_1[i];
}
double getk_4(ODE ode, int i){
    return ode->k_1[i];
}


ODE new_ODE(int q){
     ODE ode = malloc(sizeof(odeobj));
     ode->q = q;
     ode->k_1 = calloc(q,sizeof(double *));
     ode->k_2 = calloc(q,sizeof(double *));
     ode->k_3 = calloc(q,sizeof(double *));
     ode->k_4 = calloc(q,sizeof(double *));
     ode->q_n = calloc(q,sizeof(double *));
     ode->function = NULL;
     return ode;
}


//=================================================================================
