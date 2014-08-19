#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){
    float j = 1.0;
    double g = 1.0;
    
    printf("Running float underflow test\n");
    //Loop through find value that causes float to have value 0.0
    for(int i =1; i<= 10000; i++){
       if(j != 0.0){
       j=j/2;
       if(i<3 || i>146){
       printf("2^%d = %1.5e\n",i,j);
       }else if(i==3){
        printf("......\n");
       }
      }else{
       printf("Float underflow happens at value 2^%d\n",i-1);
       break;
      }
    }
     
    printf("\n \nRunning double underflow test\n") ;
    //Loop through find value that causes double to have value 0.0
    for(int i =1 ; i<=10000;i++){
      if(g != 0.0){
        g = g/2;
         if(i<3 || i>1072){
           printf("2^%d = %1.5e\n",i,g);
       }else if(i==3){
           printf("......\n");
       }
      }else{
        printf("Double underflow happens at value 2^%d\n",i-1);
        break;
      }
    }
}

