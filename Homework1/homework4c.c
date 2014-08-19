#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* double_golden_mean(double phi_0,double phi_1,int limit);
void double_print_array(double *phi_array,int limit);
float* float_golden_mean(float phi_0,float phi_1,int limit);
void float_print_array(float *phi_array,int limit);

int main(int argc, char **argv){
    double phi_0_d = 1.0;
    double phi_1_d = (sqrt(5.0)-1)/2;
    float phi_0_f = 1.0;
    float phi_1_f = (sqrt(5.0)-1)/2;
    double* phi_array_double = double_golden_mean(phi_0_d,phi_1_d,50);
    float* phi_array_float = float_golden_mean(phi_0_f,phi_1_f,50);
    printf("Single precision:\n");
    float_print_array(phi_array_float,50);
    printf("Double precision:\n");
    double_print_array(phi_array_double,50);
    free(phi_array_double);
    free(phi_array_float);
    return 0;
}

double* double_golden_mean(double phi_0,double phi_1,int limit){
       double* phi_array;
       phi_array = malloc((limit+1)*sizeof(double));
       phi_array[0] = phi_0;
       phi_array[1] = phi_1;
       for (int i=2;i <=limit;i++){
        phi_array[i] = phi_array[i-2] - phi_array[i-1];
       }

       return phi_array;
}

float* float_golden_mean(float phi_0,float phi_1,int limit){
       float* phi_array;
       phi_array = malloc((limit+1)*sizeof(float));
       phi_array[0] = phi_0;
       phi_array[1] = phi_1;
       for (int i=2;i <=limit;i++){
        phi_array[i] = phi_array[i-2] - phi_array[i-1];
       }

       return phi_array;
}

void double_print_array(double *phi_array,int limit){
      for(int i=0;i<=limit;i++){
        if(i<=3 || i >47){
         printf("Phi^%d = %1.4e \n",i,phi_array[i]);
        if(i==3){printf(".....\n....\n");}

       }
      }
      printf("\n");
}

void float_print_array(float *phi_array,int limit){
      for(int i=0;i<=limit;i++){
        if(i<=3 || i >47){
         printf("Phi^%d = %1.4e \n",i,phi_array[i]);
        if(i==3){printf(".....\n....\n");}

       }
      }
      printf("\n");
}