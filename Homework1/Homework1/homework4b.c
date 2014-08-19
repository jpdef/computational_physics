#include <stdio.h>
#include <math.h>


double double_golden_mean(double phi,int count,int limit);
float float_golden_mean(float phi,int count,int limit);

int main(int argc, char **argv){
    double double_phi_0 = 1.0;
    float float_phi_0 = 1.0;
    int count = 0.0;
    
    printf("Single precision of the golden mean\n");
    for(int i = 1; i<=10;i++){
       printf("Phi^%d = %1.8e\n",i,float_golden_mean(float_phi_0,count,i));
    }

    printf("\nDouble precision of the golden mean\n");
    for(int i = 1; i<=10;i++){
       printf("Phi^%d = %1.8e\n",i,double_golden_mean(double_phi_0,count,i));
    }
   
    
    return 0;
}

double double_golden_mean(double phi,int count,int limit){
   double phi_1 = (sqrt(5.0)-1)/2;
//   printf("phi_1 = %f",phi_1);
   if(count>= limit){
     return phi;
   }else{
     phi = phi *phi_1;
     count = count +1;
     double_golden_mean(phi,count,limit);
   }
}



float float_golden_mean(float phi,int count,int limit){
   float phi_1 = (sqrt(5.0)-1)/2;
//   printf("phi_1 = %f",phi_1);
   if(count>= limit){
     return phi;
   }else{
     phi = phi *phi_1;
     count = count +1;
     float_golden_mean(phi,count,limit);
   }
}
