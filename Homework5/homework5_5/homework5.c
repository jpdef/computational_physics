#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define PI 3.14159265358979323846

int main(int argc, char **argv){
	int N=1000;
    double avg =0.0;
    double var =0.0;
    srand(time(NULL));
    for(int t =10; t<100; t++){
    for (int i = 0; i < N; ++i){
        double x = 0.0;
        for (int j = 0; j< t; ++j){
            if(0.5 <= 1.0*rand()/(RAND_MAX+1)){
                x+=1;
            }else{
                x-=1;
            }
        }
        avg += x;
        var += pow(x,2);
    }
    printf("%d %f %f\n",t,avg/N,var/(double)N );
    avg =0.0;
    var = 0.0;
  }
  return 0;
}

