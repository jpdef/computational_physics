#include <stdio.h>
#include <math.h>

double x_squared(double x);
double second_derivative(double x, double h);
int main(int argc, char **argv){
    double h = .01;
    double eval = 5.0;
    printf("The second derivative of x^3 evaluated at %.5e is %.5e\n",eval,second_derivative(eval,h));
    return 0;
}

double x_squared(double x){
  return pow(x,2.0);
}

double x_cubed(double x){
  return pow(x,3.0);
}

double second_derivative(double x, double h){
  return (x_cubed(x+h) + x_cubed(x-h) - 2*x_cubed(x))/(x_squared(h));
}