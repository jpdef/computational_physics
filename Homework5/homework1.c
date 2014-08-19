#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define PI 3.14159265358979323846

void gen_rand(double* rand_array,int N);
int main(int argc, char **argv){
    int N = 12;
    double* rand_array = calloc(N,sizeof(double *));
    srand(time(NULL));
    for(int i = 1; i<7;i++){
        double X_m = 0.0;
        for(int j =0; j< 10000; j++){
            gen_rand(rand_array,N);
            double sum = 0.0;
            for(int k=0;k<N;k++){
                sum+= (rand_array[k]-0.5);
            }
            X_m += pow(sum,i);
        }
        X_m = X_m/1000.0;
        printf("<X^%d>=%f\n",i,X_m);
    }
    
    return 0;

}

void gen_rand(double* rand_array,int N){
    for(int i = 0; i<N ;i++){
        double R =(rand()/(RAND_MAX+1.0));
        rand_array[i] = R;
    }

}

