#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double** intialize_array(int size_n);
void expand_array(double** integral_array, int size_n);
void free_array(double** integral_array, int size_n);
int size_k(int size_n);

int main(int argc, char **argv){
    double** integral_array = intialize_array(16);
    for(int i =0 ; i<4 ;i++){
      for(int j=0; j < size_k(i); j++){
            if(j==0){integral_array[i][j]=1.0;} 
            if(j==1){integral_array[i][j]=2.0;} 
            if(j>1){
              integral_array[i][j]=integral_array[i][j-1] + integral_array[i][j-2];
            }
      }

    }

      for(int i =0 ; i<10 ;i++){
         for(int j=0; j < 10; j++){
            if(integral_array[i][j]==0){
              break;
            }
             printf("%f ",integral_array[i][j]);

      }
      printf("\n");

    }
   // for (int i = 0; i < 1000; ++i)
    //{
     // printf("%d\n", i );
    //}
    free_array(integral_array,16);
    return 0;
}

double** intialize_array(int size_n){
    double** integral_array = (double** )malloc(size_n*sizeof(double *));
    for(int i=0;i<size_n;i++){
      integral_array[i] = calloc(size_k(i), sizeof(double *));
    }
    return integral_array;

}

void expand_array(double** integral_array,int size_n){
  printf("Make array length %d place array %d \n",size_n,size_n-1 );
  double** temp = (double** )realloc(integral_array, (size_n)*sizeof(double *));
  if(temp == NULL){printf("shit\n");}
  integral_array=temp;
  integral_array[size_n-1] = (double* )calloc(10, sizeof(double *));//go to new added index
  printf("success\n");
}

int size_k(int size_n){
      return  pow(2,(double)(size_n));
}

void free_array(double** integral_array,int size_n){
     for(int i =0; i<size_n ;i++){
      free(integral_array[i]);
     }
     free(integral_array);
     return;
}