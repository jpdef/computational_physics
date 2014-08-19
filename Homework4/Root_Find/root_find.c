#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "root_find.h"

bool bracketed(double y_l, double y_r);

double bisection(double (*func)(double), double x_l , double x_r){
    //make sure x's always bracket root
    if( (*func)(x_l) == (double)0.0){return x_l;}
    if( (*func)(x_r) == (double)0.0){return x_r;}
    if(bracketed((*func)(x_l), (*func)(x_r))){
        //return when four digits or precision are recieved

        if(fabs(x_r - x_l) < (1/pow(10.0,4.0))){return (x_l + x_r)/2.0; }
        double x_n = (x_r + x_l)/2.0;
        //reccur
        if(bracketed( (*func)(x_l), (*func)(x_n) )){
            bisection((*func), x_l, x_n);
        }else{
            bisection((*func), x_n, x_r);
        }

    }else{
        printf("Something went wrong no longer bracketed\n");
        return 0.0;
    }

}


double newt_raph(double (*func)(double),double x_n_1, double x_n){
    double f_prime = ((*func)(x_n) - (*func)(x_n_1))/(x_n - x_n_1);
    double f_x_n = (*func)(x_n);
    x_n_1 = x_n - (f_x_n)/(f_prime);
    if(fabs((*func)(x_n_1) - 0.0) < (1/pow(10.0,14.0))){return x_n_1;}
    newt_raph(*func,x_n_1,x_n);
        return 9.0;

}


double secant(double x_1, double x_2, double (*func)(double)){
    double f_x_1 = (*func)(x_1);
    double f_x_2 = (*func)(x_2);
    double x_3 = x_2 - f_x_2*((x_2-x_1)/(f_x_2- f_x_1));
    printf("%.3f\n", x_3);
    if(fabs((*func)(x_3) - (double) 0.0) < (1/pow(10.0,12))){return x_3;}
    secant(x_3,x_2,(*func));
        return 9.0;

}


bool bracketed(double y_l, double y_r){
    bool case_1 = false;
    bool case_2 = false;
    if(y_l <= 0.0 && y_r >= 0.0){
       case_1 = true;
    }
    if(y_l >=0.0 &&  y_r <=0.0){
       case_2 = true;
    }

    if (case_1 || case_2){
        return true;
    }else{
        return false;
    }
    
}
