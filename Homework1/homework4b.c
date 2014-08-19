#include <stdio.h>
#include <math.h>


double golden_mean(double phi,int count,int limit);
int main(int argc, char **argv){
    double phi_0 = 1.0;
    int count = 0.0;
    for(int i = 1; i<=50;i++){
       if(i<=3 || i >47){
       printf("Phi^%d = %.8e\n",i,golden_mean(phi_0,count,i));
       if(i==3){printf(".....\n....\n");}
     }
    }
    return 0;
}

double golden_mean(double phi,int count,int limit){
   double phi_1 = (sqrt(5.0)-1)/2;
//   printf("phi_1 = %f",phi_1);
   if(count>= limit){
     return phi;
   }else{
     phi = phi *phi_1;
     count = count +1;
     golden_mean(phi,count,limit);
   }
}
