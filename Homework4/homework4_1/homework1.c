#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./Integration/integration.h"
#include "./Root_Find/root_find.h"
#define PI 3.14159265358979323846


double gaussian(double x);
double gaussian_integral(double a);
double linear(double x);

int main(int argc, char **argv){
	double precision_a = 1.0;
	double precision_I = 1.0;
	double dp = 1;
	double step_size =1;
	double previous_I = 0;
    double previous_a = 0;

	printf("|%7s|\t |%7s|\t |%7s|\t|%7s|\n"
        ,"a","integral","precision of a","precision of I");
	while (precision_a > (1/pow(10,5)) || precision_I > (1/pow(10,5))){
		double a = bisection(gaussian_integral,0 , PI, dp);
        double I = simp(-a,a,gaussian,step_size);
        precision_I = fabs(I - previous_I);
        precision_a = fabs(a -previous_a);
        dp+=1;
        step_size = 5*step_size;
        previous_I = I;
        previous_a = a;
        printf("%.7f\t %.7f\t %.7f\t \t%.7f\n", a,I,precision_a,precision_I);
	}
}  

double gaussian(double x){
  return (1/sqrt(2.0*PI))*1/(exp(pow(x,2)/2));
}

double linear(double x){
	return cos(x);
}

double gaussian_integral(double a){
     return simp(-a,a,gaussian,100) - .5;
}