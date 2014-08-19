//====================================HOMEWORK5==========================================

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double simp(double a, double b, double (*func)(double,double),double n,double h,double theta_m);
void print_table(double a, double b, double (*func)(double,double) , double precision,double theta_m);
double ellipitcal_intgrand(double theta_m, double theta);// does not include constant
double binomial_approximation(double theta_m);

int main(int argc, char **argv){
    double precision = (1.0/pow(10.0,12.0));
    double theta_m_array[5] ={.1,.2,PI/4.0,PI/2.0,3.0*PI/4.0} ;   
    printf("Using simpson rule to calculate ellipitical integrals to 10^-12 precision\n");
    for(int i = 0 ; i <5;i++){
    	printf("----------theta_m = %.3f----------\n",theta_m_array[i]);
        print_table(0.0,PI/2.0,ellipitcal_intgrand,precision,theta_m_array[i]);
        printf("\n");
    } 
    return 0;
}

double simp(double a, double b, double (*func)(double,double),double n,double h, double theta_m){
  double T_N = 0.0; //end return value
  double T_N_odd = 0.0;
  double T_N_even = 0.0;
  for(double i =1.0; i<n;i=i+2){//gurantees n function evaluations
    T_N_odd = T_N_odd + (*func)(theta_m, a+i*h);
    //printf("f(%f) = %f\n",a+i*h,(*func)(a+i*h)); //debug print statement
  }
  for(double i =2.0; i<n;i=i+2){//gurantees n function evaluations
    T_N_even = T_N_even + (*func)(theta_m, a+i*h);
    //printf("f(%f) = %f\n",a+i*h,(*func)(a+i*h)); //debug print statement
  }

  T_N = (h/3.0)*(4.0*T_N_odd + 2.0*T_N_even + (*func)(theta_m,a) + (*func)(theta_m,b));
  return T_N;
}

 void print_table(double a, double b, double (*func)(double,double) , double precision,double theta_m){
    printf("n \t h value: \t Integral value: \t Relative error:\n");
    double old_I = 0.0;
    for (double i = 1; i <= 10; ++i){ // do not exceed 10
       double h = ((b-a)/pow(2,i));
       double I = (2.0/PI)*simp(a,b,*func, pow(2,i),h,theta_m);
       double rel_err = (I - old_I)/pow(h,4) ;
       printf("%d \t %1.2e \t %1.12e \t \t %1.2e\n", (int)pow(2,i) , h , I, rel_err );
       if( fabs(I - old_I) < precision){
          printf("precision reached \n");
          printf("Best Intergal Value = %1.12f\n", I );
          printf("Binomial Approximation = %1.12f\n", binomial_approximation(theta_m) );
          break;
       }
       old_I = I;

    }
} 

double ellipitcal_intgrand(double theta_m, double theta){ // does not include constant
	double psi = sin(theta/2.0)*sin(theta_m/2.0);
    double denom = 1.0 - pow((sin(theta_m/2.0)),2.0)*pow(psi,2.0);
    return 1/sqrt(denom); 
}

double binomial_approximation(double theta_m){
	return 1.0 + (1/4.0)*pow(sin(theta_m),2) + (9.0/64.0)*pow(sin(theta_m),4);
}

//==========================================================================================