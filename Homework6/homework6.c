#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char **argv){
    double exponent = 0.0;
    double mantissa = 0.0;
    for(int i = 50000;i >=1;i--){
        exponent += log10(i);
    }
    mantissa = pow(10,exponent - floor(exponent));
    exponent = floor(exponent);
    printf("50,000 ! = %.5f  x  10^%d\n",mantissa,(int)exponent);
}
