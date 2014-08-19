#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool bracketed(double y_l, double y_r);
double bisection(double (*func)(double), double x_l , double x_r);
double poly_function(double x);

//Do intial guesses need to be found 
int main(int argc, char **argv){
    printf("Root 1 %.4f \n",bisection(poly_function,0,1));
    printf("Root 2 %.4f\n", bisection(poly_function,-3,-2));
    printf("Root 3 %.4f\n", bisection(poly_function,1,2));
    return 0;
}

double bisection(double (*func)(double), double x_l , double x_r){
    //make sure x's always bracket root
    if(bracketed((*func)(x_l), (*func)(x_r))){
        //return when four digits or precision are recieved
        if(fabs(x_r - x_l) < (1/pow(10.0,4.0))){return (x_l + x_r)/2.0; }
        double x_n = (x_r + x_l)/2.0;
        //reccur
        if(bracketed( (*func)(x_l), (*func)(x_n) )){
            bisection((*func), x_l, x_n);
        }else{
            bisection((*func), x_n, x_r);
        }

    }else{
        printf("Something went wrong no longer bracketed\n");
        return 0.0;
    }


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
    return (pow(x,3.0) - 5*x + 3);
}

