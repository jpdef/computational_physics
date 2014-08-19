//====================================HOMEWORK3==========================================
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//***Integration Methods****
double zoid(double a, double b, double (*func)(double),double n,double h);
double** romb(double a, double b,  double(*func)(double),int array_size, double precision);

//**Auxillary Functions
bool check_precision(double** integral_array,int i, double precision,bool v);
double I_to_k(double I_n, double I_half, double k);
int size_k(int size_n);

//***Integrands***
double gauss_fn(double x);
double one_over_x_squared(double x);

//***Array Functions**
void print_array(double** integral_array,double precision);
double** intialize_array(int size_n);
void free_array(double** integral_array, int size_n);



int main(int argc, char **argv){
    double precision = (1.0/pow(10.0,12.0));
    int array_size = 10;
    double** integral_array = romb(0.0,1.0,gauss_fn,array_size,precision);
    print_array(integral_array,precision);
    free_array(integral_array,array_size);
    return 0;
}

double** romb(double a, double b,  double(*func)(double),int array_size,double precision){
  double** integral_array = intialize_array(array_size+1);
  for(int i =0; i<array_size;i++){
    double n = pow(2,(double)i);
    double h = (b-a)/n;
    for(int j=0; j<=i;j++){
       //printf("[%d,%d], \n",i,j );
       if(j==0){integral_array[i][j]= zoid(a,b,(*func),n,h);}
       if(j>=1){
        //integral_array[i][j] = 1.1;
        integral_array[i][j]= I_to_k(integral_array[i][j-1],integral_array[i-1][j-1],(double)j);
      }
    }
    if(check_precision(integral_array,i,precision,false)){
      break;
    }
  }

  return integral_array;
}


double zoid(double a, double b, double (*func)(double),double n,double h){
  double T_N = 0.0; //end return value
  for(double i =1.0; i<n;i++){//gurantees n function evaluations
    T_N = T_N + (*func)(a+i*h);
    //printf("f(%f) = %f\n",a+i*h,(*func)(a+i*h));// debug print statement
  }
  T_N = h*(T_N + ((*func)(a) + (*func)(b))/2);
  return T_N;
}


double gauss_fn(double x){
  return 1/(exp(pow(x,2)/2));
}

double one_over_x_squared(double x){
  return (1/pow(x,2.0));
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

void print_array(double** integral_array,double precision){
  printf("%-10s%-12s%-22s%-22s%-22s%-22s%-22s\n","Intervals","Precision","k=1","k=2","k=3","k=4","k=5");
  for (int i = 0; i < 16; ++i)
  {
    if(integral_array[i][0] == 0 ){printf("\n"); break;}
    printf("n = %-2.0f %-1s",pow(2,i),"");
    check_precision(integral_array,i,precision, true);
    for (int j = 0; j <16; ++j)
    { 
      if(integral_array[i][j] == 0 ){break;}
      printf("%-1s %.11f ","",integral_array[i][j]);

    }
    printf("\n");
    //check_precision(integral_array,i,(1/pow(10,12)),true);
  }
}

//==========================================================================================