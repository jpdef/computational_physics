#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){
    float j = 1.0;
    double g = 1.0;
    
    printf("Running float overflow test\n");
    //Loop through find value that causes float to have value infintiy
    for(int i =1; i<= 10000; i++){
       if(j != INFINITY){
       j=2*j;
       if(i<3 || i>124){
       printf("2^%d = %1.5e\n",i,j);
       }else if(i==3){
        printf("......\n");
       }
      }else{
       printf("Float Overflow happens at value 2^%d\n",i-1);
       break;
      }
    }
     
    printf("\n \nRunning double overflow test\n") ;
    //Loop through find value that causes double to have value infintiy
    for(int i =1 ; i<=10000;i++){
      if(g != INFINITY){
        g = 2*g;
         if(i<3 || i>1020){
           printf("2^%d = %1.5e\n",i,g);
       }else if(i==3){
           printf("......\n");
       }
      }else{
        printf("Double Overflow happens at value 2^%d\n",i-1);
        break;
      }
    }
}

