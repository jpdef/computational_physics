#include <stdio.h>
#include <math.h>
double double_sum_up(int p);
double double_sum_down(int p);
float float_sum_up(int p);
float float_sum_down(int p);

int main(int argc, char **argv){
    double total_difference_up = 0.0;
    double total_difference_down =0.0;
    printf("Difference between float and double in sums\n");
    for (int p=2; p<=7;p++){
        printf("N=10^%d : Difference in up sum = %.5e, Difference in down sum = %.5e \n",p, (double_sum_up(p)-float_sum_up(p)),(double_sum_down(p)-float_sum_down(p)));
        total_difference_up= total_difference_up+ double_sum_up(p) - (double)float_sum_up(p);
        total_difference_down = total_difference_down + double_sum_down(p) - (double)float_sum_down(p);
    }
     if(total_difference_up>total_difference_down){
      printf("Down is more accurate\n");
     }else{
      printf("Up is more accurate\n");
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

float float_sum_up(int p){
      float N = powf(10.0,(float)p);
      float sum = 0.0;
       for (float i = 1.0; i<=N;i++){
          if(1/i>0){
          sum = sum + 1/i;
        }
      } 
      return sum;
}

float float_sum_down(int p){
      float N = powf(10.0,(float)p);
      float sum = 0.0;
      for (float i = N; i>=1.0;i--){
          if(1/i > 0){
          sum = sum + 1/i;
          }
      } 
      return sum;
}

