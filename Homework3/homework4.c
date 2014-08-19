#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool bracketed(double y_l, double y_r);
double* bisection(double (*func)(double), double x_l , double x_r);
double poly_function(double x);
double newt_raph(double (*func)(double),double x_n_1, double x_n,int n);

//Do intial guesses need to be found 
int main(int argc, char **argv){
    double* bisect_array_1 = bisection(poly_function,0,2);


    printf("Bisection\n");
    printf("Root 1 %.4f \n",bisect_array_1[0]);

     
    printf("Newton-Raphlson Polishing\n");
    printf("Root 1 %.14f \n",newt_raph(poly_function,bisect_array_1[2],bisect_array_1[1],0));




    free(bisect_array_1);

    return 0;
}

double* bisection(double (*func)(double), double x_l , double x_r){
    double *bisect_array = (double*)malloc(3*sizeof(double));
    //make sure x's always bracket root
    if(bracketed((*func)(x_l), (*func)(x_r))){
        double x_n = (x_r + x_l)/2.0;
        //return when four digits or precision are recieved
        if(fabs(x_r - x_l) < (1/pow(10.0,4.0))){
            bisect_array[0] = x_n;
            bisect_array[1] = x_r;
            bisect_array[2] = x_l;
            return bisect_array;
        }
        //reccur
        if(bracketed( (*func)(x_l), (*func)(x_n) )){
            bisection((*func), x_l, x_n);
        }else{
            bisection((*func), x_n, x_r);
        }

    }else{
        printf("Something went wrong no longer bracketed\n");
        return NULL;
    }


}

double newt_raph(double (*func)(double),double x_n_1, double x_n,int n){
    double f_prime = ((*func)(x_n) - (*func)(x_n_1))/(x_n - x_n_1);
    double f_x_n = (*func)(x_n);
    x_n_1 = x_n - (f_x_n)/(f_prime);
    if(fabs((*func)(x_n_1) - 0.0) < (1/pow(10.0,14.0))){return x_n_1;}
    printf("n = %d Root Approx = %1.12e\n",n,x_n_1);
    n += 1;
    newt_raph(*func,x_n_1,x_n,n);

}
//checks if on evaluation on both sides has opposite sign
bool bracketed(double y_l, double y_r){
    bool case_1 = false;
    bool case_2 = false;
    if(y_l < 0.0 && y_r > 0.0){
       case_1 = true;
    }
    if(y_l >0.0 &&  y_r <0.0){
       case_2 = true;
    }

    if (case_1 || case_2){
        return true;
    }else{
        return false;
    }
    
}

double poly_function(double x){
    return (pow(x,2.0) - 2);
}

