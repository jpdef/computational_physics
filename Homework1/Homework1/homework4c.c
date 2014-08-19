#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void float_golden_mean(float phi_0,float phi_1,int limit);
void double_golden_mean(double phi_0,double phi_1,int limit);
void print_array(double *phi_array,int limit);

int main(int argc, char **argv){
    //Single Precision
     printf("Single precision on golden mean:\n");
     float float_phi_0 = 1.0;
     float float_phi_1 = (sqrt(5.0)-1)/2;
     for(int i = 2; i<=10;i++){
        float_golden_mean(float_phi_0,float_phi_1,i);
     }

    //Double Precision
    printf("\nDouble precision on golden mean:\n");
    double double_phi_0 = 1.0;
    double double_phi_1 = (sqrt(5.0)-1)/2;
    for(int i = 2; i<=10;i++){
       double_golden_mean(double_phi_0,double_phi_1,i);
    }
    return 0;
}

void double_golden_mean(double phi_0,double phi_1,int limit){
       double* phi_array;
       phi_array = malloc((limit+1)*sizeof(double));
       phi_array[0] = phi_0;
       phi_array[1] = phi_1;
       for (int i=2;i <=limit;i++){
        phi_array[i] = phi_array[i-2] - phi_array[i-1];
       }
       printf("Phi^%d = %1.8e \n",limit,phi_array[limit]);
       //print_array(phi_array,limit);
       free(phi_array);
}


void float_golden_mean(float phi_0,float phi_1,int limit){
       float* phi_array;
       phi_array = malloc((limit+1)*sizeof(float));
       phi_array[0] = phi_0;
       phi_array[1] = phi_1;
       for (int i=2;i <=limit;i++){
        phi_array[i] = phi_array[i-2] - phi_array[i-1];
       }
       printf("Phi^%d = %1.8e \n",limit,phi_array[limit]);
       //print_array(phi_array,limit);
       free(phi_array);
}

void print_array(double *phi_array,int limit){
      for(int i=0;i<=limit;i++){
         printf("Phi^%d = %1.4e ",i,phi_array[i]);
      }
      printf("\n");
}
