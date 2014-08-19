#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define PI 3.14159265358979323846

void gen_rand(double* rand_array,int N);
int main(int argc, char **argv){
    int N = 10000;
	double* rand_array = calloc(N,sizeof(double *));
	double* x_array = calloc(N,sizeof(double*));
	gen_rand(rand_array,N);
	for(int i=0;i<N;i++){
		x_array[i] = tan(PI*rand_array[i]);
	}
	
	int inbetween_one = 0;
	for(int i=0;i<N;i++){
		if(fabs(x_array[i]) < 1){inbetween_one+=1;}
	}
	double N_D = (double)N;
	double i_o_D = (double)inbetween_one;
	printf("%f\n", i_o_D/N_D);

    free(rand_array);
    free(x_array);
    return 0;

}
void gen_rand(double* rand_array,int N){
    for(int i = 0; i<N ;i++){
        double R =1.0*(rand()/(RAND_MAX+1.0));
        rand_array[i] = R;
    }

}