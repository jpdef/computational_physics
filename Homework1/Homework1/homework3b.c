#include <stdio.h>
#include <math.h>
double double_sum_up(int p);
double double_sum_down(int p);


int main(int argc, char **argv){
    printf("Double precision sums:\n");
    for (int p=2; p<=7;p++){
      printf("For 10^%d sum up is %.8e, sum down is %.8e \n",p,double_sum_up(p),double_sum_down(p));
    }


}
double double_sum_up(int p){
      double N= pow(10.0,(double)p);
      double sum = 0.0;
      for (double i = 1.0; i<=N;i++){
          sum = sum + 1/i;
      } 
      return sum;
}

double double_sum_down(int p){
      double N = pow(10.0,(double)p);
      double sum = 0.0;
      for (double i = N; i>=1.0;i--){
          sum = sum + 1/i;
      } 
      return sum;
}



