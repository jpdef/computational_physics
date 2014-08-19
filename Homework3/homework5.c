#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define PI 3.14159265358979323846

typedef struct Ode{
    double k_1;
    double k_2;
    double y_n;
}Ode;

void update_ode(Ode* ode,double h, double (*func)(double));
double f(double y);

int main(int argc, char **argv){
    Ode* ode = malloc(sizeof(Ode));
    ode->y_n = 0.0;
    ode->k_1 = 0.0;
    ode->k_2 = 0.0;
    int n = 100;
    double h = PI/(4* (double)n);
    for (int i = 0; i < n; ++i)
    {
        update_ode(ode,h,f);
        //printf("%f \t %f\n",(double)i*h,ode->y_n);

    }
    printf("Value = %f Error = %f h^2 = %f\n",ode->y_n, 1- ode->y_n, pow(h,2.0) );
    free(ode);
 return 0;
}

void update_ode(Ode* ode,double h, double (*func)(double)){
    ode->k_1 = (*func)(ode->y_n);
    ode->k_2 = (*func)(ode->y_n + (h/2)*ode->k_1);
    ode->y_n = ode->y_n + h*ode->k_2;
    //printf("y_n = %f  k_1 = %f k_2 = %f\n",ode->y_n,ode->k_1, ode->k_2 );

}
//y is a function of x
double f(double y){
    return 1.0+ pow(y,2.0);
}
