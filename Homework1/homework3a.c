
#include<stdio.h>
#include<math.h>
float sum_up(int p);
float sum_down(int p);

int main(int argc, char argv){
    for (int p=2; p<=7;p++){
    printf("For 10^%d, the sum up = %.8e and sum down is %.8e\n",p,sum_up(p),sum_down(p)); 
    }
}
float sum_up(int p){
      float N = 10^p;
      float sum = 0.0;
      for (float i = 1.0; i<=N;i++){
          sum = sum + 1/i;
      } 
      return sum;
}

float sum_down(int p){
      float N = 10^p;
      float sum = 0.0;
      for (float i = N; i>=1.0;i--){
          sum = sum + 1/i;
      } 
      return sum;
}
