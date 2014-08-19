#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "leapfrog.h"
#include "rk4.h"
#define PI 3.14159265358979323846

double force(double x);
void derivatives(double* x, double* y);

int main(int argc, char **argv){
    double* q = calloc(4, sizeof(double));
    q_x[0] = 1.0;
    q_x[1] = 1.0;
    q_y[0] = 1.0;
    q_y[1] = 1.0;

    int n = 1000000;
    double h = .5;

    printf("t \t E_L \t E_K  \n");
    for (int i = 0;i<1000;i++){
        position_verlet(q_x,force_x,h);
        position_verlet(q_y,force_y,h);
        printf("%f %f\n",q_x[0] ,q_y[0]);
    }
    return 0;

}



double force_y(double y){
    return -1/(pow(y,2));
}

double force_x(double x){
    return -1/(pow(x,2));
}