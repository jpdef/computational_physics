#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846


struct pair {
      double x_value;
      double w_value;
};

struct pair N_2[2] ={
     {0.7071068,0.8862269},
     {-0.7071068,0.8862269},
};

struct pair N_3[3] ={
    {1.2247449,0.2954090},
    {0.0000000,1.1816359},
    {-1.2247449,0.2954090},
};

struct pair N_4[4] ={
	{ 1.6506801,0.0813128},
    {0.5246476,0.8049141},
    {-0.5246476,0.8049141},
    { -1.6506801,0.0813128}
};

double approximation(struct pair *N, double (*func)(double),int limit);
double x_2 (double x);
double x_4 (double x);
double x_6 (double x);
double exp_fn(double x);
//====================================HOMEWORK7==========================================







int main(int argc, char **argv){
	double(*fn_array[3])(double) = {x_2,x_4,x_6};
	struct pair* pair_array[3]={N_2,N_3,N_4};
	printf("%-10s%-10s%-10s%-10s\n", "N","x^2","x^4","x^6");
	for (int i = 0; i < 3; ++i){
		printf("%-10d", i+2 );
		for(int j=0 ;j<3; j++){
            printf("%-10.4f",approximation(pair_array[i],fn_array[j],i+2));
        } 
        printf("\n");

	}
	printf("Part B I - %f\n",approximation(N_4,exp_fn,4));
    return 0;
}

double approximation(struct pair *N, double (*func)(double),int limit){
	 double sum = 0.0;
	 for(int i = 0 ; i < limit;i++){
    	sum  = sum + N[i].w_value*(*func)(N[i].x_value);
    }
    return sum;

}

double x_2 (double x){
	return pow(x,2.0);
}
double x_4 (double x){
	return pow(x,4.0);
}
double x_6 (double x){
	return pow(x,6.0);
}
double exp_fn(double x){
	double denom = 1+exp(x);
	return 1.0/denom;
}

//==========================================================================================