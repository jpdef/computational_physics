#include <stdio.h>
#include <math.h>
double double_sum_up(int p);
double double_sum_down(int p);
float float_sum_up(int p);
float float_sum_down(int p);

int main(int argc, char **argv){
    for (int p=2; p<=7;p++){
    //printf("For 10^%d, the sum up = %.15e and sum down is %.15e\n",p,sum_up(p),sum_down(p)); 
      printf("For 10^%d\n",p);
      printf("Difference between sum up and sum down with double precision= %.5e\n", double_sum_up(p)-double_sum_down(p));
      printf("Difference between sum up and sum down with single precision= %.5e\n",float_sum_up(p)-float_sum_down(p));
    }
    printf("This shows double is more precise\nnow compare up and down methods of floats with their respective doubles\n");
    double total_difference_up = 0.0;
    double total_difference_down =0.0;
    for (int p=2; p<=7;p++){
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

