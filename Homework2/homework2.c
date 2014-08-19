//====================================HOMEWORK2==========================================


#include <stdio.h>
#include <math.h>
double simp(double a, double b, double (*func)(double),double n,double h);
double e_x_sin_x(double x);
double sin_x(double x);
void print_table(double a, double b, double (*func)(double) ,double precision);
int main(int argc, char **argv){
    //print_table(0.0,(3.14/2),sin_x);
    double precision = (1.0/pow(10.0,8.0));
    print_table(0.0,2.0,e_x_sin_x,precision);cp 
    return 0;
}

double simp(double a, double b, double (*func)(double),double n,double h){
  double T_N = 0.0; //end return value
  double T_N_odd = 0.0;
  double T_N_even = 0.0;
  for(double i =1.0; i<n;i=i+2){//gurantees n function evaluations
    T_N_odd = T_N_odd + (*func)(a+i*h);
    //printf("f(%f) = %f\n",a+i*h,(*func)(a+i*h)); //debug print statement
  }
  for(double i =2.0; i<n;i=i+2){//gurantees n function evaluations
    T_N_even = T_N_even + (*func)(a+i*h);
    //printf("f(%f) = %f\n",a+i*h,(*func)(a+i*h)); //debug print statement
  }

  T_N = (h/3.0)*(4.0*T_N_odd + 2.0*T_N_even + (*func)(a) + (*func)(b));
  return T_N;
}

double e_x_sin_x(double x){
  return exp(-x)*sin(x);
}
double sin_x(double x){
  return sin(x);
}

void print_table(double a, double b, double (*func)(double) , double precision){
  printf("n \t h value: \t Integral value: \t Relative error:\n");
  double old_I = 0.0;
 for (double i = 1; i <= 10; ++i){ // do not exceed 10
    double h = ((b-a)/pow(2,i));
    double I = simp(a,b,*func, pow(2,i),h);
    double rel_err = (I - old_I)/pow(h,4) ;
    printf("%d \t %1.2e \t %1.2e \t \t %1.2e\n", (int)pow(2,i) , h , I, rel_err );
    if( fabs(I - old_I) < precision){
       printf("precision reached \n");
       break;
    }
    old_I = I;

  }
}

//==========================================================================================