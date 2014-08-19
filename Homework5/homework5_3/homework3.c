#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define PI 3.14159265358979323846

double ln_x(double x);
int main(int argc, char **argv){
	double x,b,a,avg,avg_sq,err,exact,nsigma;
	int i, num_points;
	printf("Number of points: ");
	scanf("%d",&num_points);
    exact = .386294;
    b = 2.0;
    a =1.0;
    avg = 0.0;
    avg_sq = 0.0;
    srand(time(NULL));
    for(int i = 0;i<num_points;i++){
    	x= a + (b-a)*rand()/RAND_MAX;
    	avg += ln_x(x);
    	avg_sq += pow(ln_x(x),2);
    	printf("%.5f \t %.5f \t %.5f\n",x,avg,avg_sq);
    }
    avg /= num_points;
    avg_sq /= num_points;
    printf("%.5f %5f\n",avg,avg_sq);
    err = sqrt((avg_sq - pow(avg,2))/(num_points-1));
    printf("Integral = %.5f +/- %.5f  ",(b-a)*avg,(b-a)*err );
    nsigma = (avg-exact)/err;
    printf(" there for is %f standard deviations away from exact answer\n",nsigma );
  return 0;
}

double ln_x(double x){
	return log(x);
}