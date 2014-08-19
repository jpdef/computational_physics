#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


double secant(double x_1, double x_2, double (*func)(double));
double x_tanh(double x);
int main(int argc, char **argv){
    printf("Secant method\n");
    printf("Root = %.12f\n", secant(1,2.2,x_tanh) );
    return 0;
}

double secant(double x_1, double x_2, double (*func)(double)){
    double f_x_1 = (*func)(x_1);
    double f_x_2 = (*func)(x_2);
    double x_3 = x_2 - f_x_2*((x_2-x_1)/(f_x_2- f_x_1));
    printf("%.3f\n", x_3);
    if(fabs((*func)(x_3) - (double) 0.0) < (1/pow(10.0,12))){return x_3;}
    secant(x_3,x_2,(*func));
}

double x_tanh(double x){
       return x- tanh(2.0*x);
}