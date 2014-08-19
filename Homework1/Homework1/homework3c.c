#include <stdio.h>
#include <math.h>
double double_sum_up(int p);
double double_sum_down(int p);

int main(int argc, char **argv){
    for (int p=2; p<=7;p++){
    //printf("For 10^%d, the sum up = %.15e and sum down is %.15e\n",p,sum_up(p),sum_down(p)); 
      printf("For 10^%d\n",p);
      printf("Difference between sum up and sum down with double precision= %.5e\n", double_sum_up(p)-double_sum_down(p));
    }
 }
double double_sum_up(int p){
      double N= pow(10,p);
      double sum = 0.0;
      for (double i = 1.0; i<=N;i++){
          sum = sum + 1/i;
      } 
      return sum;
}

double double_sum_down(int p){
      double N = pow(10,p);
      double sum = 0.0;
      for (double i = N; i>=1.0;i--){
          sum = sum + 1/i;
      } 
      return sum;
}


