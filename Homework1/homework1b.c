#include <stdio.h>
#include <math.h>

int main(int argc,char **argv){
	double nineteen_billion = 19.0*pow(10.0,9.0);
	double phi = sqrt(5.0)/2.0 -.5;
	printf("Nineteen billion  = %1.1e\n",nineteen_billion);
	printf("The value of the golden mean is= %1.8e \n",phi);
}
