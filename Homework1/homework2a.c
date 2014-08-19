#include <stdio.h>
#include <math.h>
int int_power(int a, int b);
int main(int argc, char **argv){
    int j = 1;
    for(int i =1; i<=1000; i++){
       j=2*j;
       printf("2^%d = %d\n",i,j);
       if(j < 0){
       	  printf("Integer Overflow occured, now try numbers inbetween 2^%d and 2^%d\n",i-1,i);
       	  int value_before = int_power(2,(i-2));  // go to value before upper limiit
       	  int k = value_before;
       	  int g = 0;
       	  while (k>0){
       	  	k = k+1;
       	  	g = g+1;
       	  }
       	  printf("The last availible integer is %d\n",g -1 +value_before);
       	  break;
       }
    }
}

int int_power(int a, int b){
	int base =a;
	for (int i =1; i<=b;i++){
		 a=a*base;
	}
	return a;
}
