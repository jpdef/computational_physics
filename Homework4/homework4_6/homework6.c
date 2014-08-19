
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./Integration/integration.h"
#define PI 3.14159265358979323846

void linear_fit(int N,double* y, double* x, double* err);
double chi_calc(int N,double a_0,double a_1,double* x,double* y, double* err);
double quality_calc(int dof, double chi_sq,double (*half_gamma)(double));
double half_gamma(double y);

int main(int argc, char **argv){
	FILE* f = fopen("data.txt","r");
	double temp[600];
	double x[200];
	double y[200];
	double err[200];
	int count =0.0;

	while(fscanf(f,"%lf",&temp[count])!=EOF){
       count +=1;
	}

    for(int i =0;i<600;i++){
    	int colum_num = i%3;
    	if(colum_num==0){x[i/3]=temp[i];}
       	if(colum_num==1){y[i/3]=temp[i];}
    	if(colum_num==2){err[i/3]=temp[i];}
    }
	for(int i =0;i<200;i++){
		//printf("%lf\t%lf\t%lf\n",x[i],y[i],err[i] );
 
    }
    linear_fit(200,y,x,err);
	fclose(f);

}


void linear_fit(int N,double* y, double* x, double* err){
	double U[3];//may need to change for more general
	double v[2];

	for(int i =0;i<3;i++){ // 00 01=01 11
		for(int j = 0;j<N;j++){
			U[i] += pow(x[j],i)/pow(err[j],2); //x_i ^alpha+beta
	     }
	}

	for(int i = 0;i<2;i++){
		for(int j = 0;j<N;j++){
			v[i] += y[j]*pow(x[j],i)/pow(err[j],2);
	    }
	}
    
	double delta = U[0]*U[2] - pow(U[1],2);
	double a_0 = (U[2]*v[0] - U[1]*v[1])/delta;
	double a_1 = (-U[1]*v[0] + U[0]*v[1])/delta;
	double sigma_a_0 = sqrt(U[2]/delta);
	double sigma_a_1 = sqrt(U[0]/delta);
	
	printf("a_0 = %f +/- %f , a_1=%f +/- %f\n",a_0,sigma_a_0,a_1,sigma_a_1);
	printf("Chi Square = %f\n", chi_calc(N,a_0,a_1,x,y,err));
	printf("There are N=%d total variables and two constraints a_0 and a_1\n",N);
    printf("therefore there are N-2=%d degrees of freedom ",N-2);
    printf("so chi_squared/dof =%f\n",chi_calc(N,a_0,a_1,x,y,err)/(N-2.0));
    printf("Quality = %f \n", quality_calc(N-2,chi_calc(N,a_0,a_1,x,y,err),half_gamma));

}

double chi_calc(int N,double a_0,double a_1,double* x,double* y, double* err){
	double chi_sq;
	for (int i = 0; i < N; ++i)
	{
		chi_sq += pow((y[i]-a_0-a_1*x[i])/err[i],2);
	}
	return chi_sq;

}

double quality_calc(int dof, double chi_sq,double (*half_gamma)(double)){
       return 1.0-(1.0/tgamma((double)(dof/2.0)))*simp(0.0, chi_sq/2.0, half_gamma,10);

}
double half_gamma(double y){
       return pow(y,(198/2.0-1.0))*exp(-y);
}