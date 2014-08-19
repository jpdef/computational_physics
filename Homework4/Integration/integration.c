
#include <math.h>
#include "integration.h"
#include <stdlib.h>
#include <stdbool.h>


double** intialize_array(int size_n);
void free_array(double** integral_array,int size_n);
int size_k(int size_n);
double I_to_k(double I_n, double I_half, double k);
bool check_precision(double** integral_array,int i,double precision,bool v);


double simp(double a, double b, double (*func)(double),double n){
  double h=(b-a)/n;
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

double zoid(double a, double b, double (*func)(double),double n){
  double h=(b-a)/n;
  double T_N = 0.0; //end return value
  for(double i =1.0; i<n;i++){//gurantees n function evaluations
    T_N = T_N + (*func)(a+i*h);
    //printf("f(%f) = %f\n",a+i*h,(*func)(a+i*h)); debug print statement
  }
  T_N = h*(T_N + ((*func)(a) + (*func)(b))/2);
  return T_N;
}

double romb(double a, double b,  double(*func)(double), double precision){
  double array_size = 11 ;
  double** integral_array = intialize_array(array_size + 1);
  for(int i =0; i<array_size;i++){
    double n = pow(2,(double)i);
    for(int j=0; j<=i;j++){
       //printf("[%d,%d], \n",i,j );
       if(j==0){integral_array[i][j]= zoid(a,b,(*func),n);}
       if(j>=1){
        //integral_array[i][j] = 1.1;
        integral_array[i][j]= I_to_k(integral_array[i][j-1],integral_array[i-1][j-1],(double)j);
      }
    }
    if(check_precision(integral_array,i,precision,false)){
       double value = integral_array[i][i];
       free_array(integral_array,array_size);
       return value;
    }
  }
  return 0.0;

}

double** intialize_array(int size_n){
    double** integral_array = (double** )malloc(size_n*sizeof(double *));
    for(int i=0;i<size_n;i++){
      integral_array[i] = calloc(size_k(i), sizeof(double *));
    }
    return integral_array;

}

void free_array(double** integral_array,int size_n){
     for(int i =0; i<size_n ;i++){
      free(integral_array[i]);
     }
     free(integral_array);
     return;
}

int size_k(int size_n){
      return  pow(2,(double)(size_n));
}

double I_to_k(double I_n, double I_half, double k){
  return (pow(4.0,k)*I_n - I_half)/(pow(4.0,k) -1);
}

bool check_precision(double** integral_array,int i,double precision,bool v){
    if(i!=0){
        double diff = fabs((integral_array[i-1][i-1]-integral_array[i][i]));
        if(v){ printf(" %5.3e",diff ); }
      if(diff < precision){
         return true;
      }else{
        return false;
      }
    }
     if(v){ printf("%10s","N/A"); }
     return false;
}
