#include <stdio.h>
#include <math.h>
double* bessel_compute(double x);
void print_values(double *bessel_array,int a,int b,int c,int d,double x);
int main(int argc, char **argv){
    double* b_1 =bessel_compute(.1);
    double* b_2 =bessel_compute(1);
    double* b_3 =bessel_compute(10);
    print_values(b_1,3,5,8,12,.1);
    print_values(b_2,3,5,8,12,1);    
    print_values(b_3,3,5,8,12,10);
    free(b_1);
    free(b_2);
    free(b_3);
    return 0;

}

double* bessel_compute(double x){
    double *bessel_array;
    int limit = 51;
    bessel_array = malloc(52*sizeof(double));
    bessel_array[51] = 1.0;
    bessel_array[50] = 1.0;
    for(int i = limit;i>=2;i--){
    	int l = (i -1) ;
    	bessel_array[l-1] = ((2.0*(double)l + 1)*bessel_array[l])/x - bessel_array[l+1] ;
    	}
    double j_0 = sin(x)/x;
    double ratio = j_0/bessel_array[0];
    for(int i=0;i<=limit;i++){
         bessel_array[i] = bessel_array[i]*ratio;
      }
      return bessel_array;
}

void print_values(double *bessel_array,int a,int b,int c,int d,double x){
      printf("j_%d(%.1f) = %.4e\n",a,x,bessel_array[a]);      
      printf("j_%d(%.1f) = %.4e\n",b,x,bessel_array[b]);
      printf("j_%d(%.1f) = %.4e\n",c,x,bessel_array[c]);
      printf("j_%d(%.1f) = %.4e\n",d,x,bessel_array[d]);
      printf("\n");
}
