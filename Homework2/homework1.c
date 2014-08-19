//====================================HOMEWORK1==========================================

#include <stdio.h>
#include <math.h>
double zoid(double a, double b, double (*func)(double),double n,double h);
double one_over_x_squared(double x);
double one_over_one_plus_x(double x);
void print_table(double a, double b, double (*func)(double) );
int main(int argc, char **argv){
    print_table(0.0,1.0,one_over_one_plus_x);
    return 0;
}

double zoid(double a, double b, double (*func)(double),double n,double h){
  double T_N = 0.0; //end return value
  for(double i =1.0; i<n;i++){//gurantees n function evaluations
    T_N = T_N + (*func)(a+i*h);
    //printf("f(%f) = %f\n",a+i*h,(*func)(a+i*h)); debug print statement
  }
  T_N = h*(T_N + ((*func)(a) + (*func)(b))/2);
  return T_N;
}

double one_over_x_squared(double x){
  return (1/pow(x,2.0));
}

double one_over_one_plus_x(double x){
  return(1/(1+x));
}
void print_table(double a, double b, double (*func)(double) ){
  printf("n \t h value: \t Integral value: \t Relative error:\n");
 for (double i = 1; i <= 5; ++i){
    double h = ((b-a)/pow(2,i));
    double I = zoid(a,b,*func, pow(2,i),h);
    double rel_err = (I - log((double) 2.0))/pow(h,2) ;
    printf("%d \t %1.2e \t %1.2e \t \t %1.2e\n", (int)pow(2,i) , h , I, rel_err );
  }
}
//==========================================================================================