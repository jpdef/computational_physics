#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


//make substution u = x^1/2
double mid_point(double a, double b, double (*func)(double),double n);
double integrand(double x);
int main(int argc, char **argv){
	printf("%-10s%-10s %-10s\n","n","M_n","M_n-1 - M_n");
  double old_I = 0;
	for (int i = 0; i < 10; ++i)
    {
		double interval = pow(2,(double)i);
    double diff = fabs(old_I - mid_point(0.0,1.0,integrand,interval));
		printf("%-9.0f %-9.4f %-9.5f \n",interval,mid_point(0.0,1.0,integrand,interval),diff);
    if(diff < 1.0/pow(10,4) ){printf("Precision reached\n"); break;}
    old_I = mid_point(0.0,1.0,integrand,interval);
	}


    return 0;
}

double mid_point(double a, double b, double (*func)(double),double n){
  double h=(b-a)/n;
  double T_N = 0.0; //end return value
  for(double i =1.0; i<=n;i++){//gurantees n function evaluations
    T_N = T_N + (*func)(a+0.5*i*h);
     //printf("f(%f) = %f\n",a+0.5*i*h,(*func)(a+0.5*i*h)); //debug print statement
  }
  T_N = h*(T_N);// + (*func)(a+0.5*h)+ (*func)(b-0.5*h));
  return T_N;
}

double integrand(double x){
	return 2*(sin(pow(x,2.0))/(pow(x,2.0)));
}