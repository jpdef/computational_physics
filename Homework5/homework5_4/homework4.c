#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define PI 3.14159265358979323846

double long_polynomial(double* x);

    int main(int argc, char **argv){
	double b,a,avg,avg_sq,err,exact,nsigma;
    double* x = calloc(10,sizeof(double *));
	int i, num_points;
	printf("Number of points: ");
	scanf("%d",&num_points);
    exact = 25.833333333;
    b = 1.0;
    a =0.0;
    avg = 0.0;
    avg_sq = 0.0;
    srand(time(NULL));
    for(int i = 0;i<num_points;i++){
        for(int j=0;j<9;j++){
            x[j]= (a + (b-a)*rand()/(RAND_MAX+1));
        }
    	avg += long_polynomial(x);
    	avg_sq += pow(long_polynomial(x),2);
    	printf("%d \t %.5f \t %.5f\n",i,avg,avg_sq);
    }
    avg /= num_points;
    avg_sq /= num_points;
    //printf("%.5f %5f \n",avg,avg_sq);
    err = sqrt((avg_sq - pow(avg,2))/(num_points-1));
    printf("Integral = %.5f +/- %.5f  ",(b-a)*avg,(b-a)*err );
  return 0;
}


double long_polynomial(double* x){
    double sum =0.0;
    for(int i=0; i<9;i++){
        sum += x[i];
    }
    //printf("%f\n",sum );
    return pow(sum,2);
}