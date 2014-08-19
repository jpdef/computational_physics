#include<math.h>
#include<stdio.h>

int smaller_float(float float_epsilon,int count);
int smaller_double(double double_epsilon,int count);
int main(int argc, char **argv){
    printf("Testing float precision:\n");
    printf("Most precision with float is %d digits\n",smaller_float(1.0,0)-1);
    printf("Testing double precision:\n");
    printf("Most precision with double is %d digits \n",smaller_double(1.0,0)-1);
    return 0;
}

int smaller_float(float float_epsilon,int count){
        float_epsilon = float_epsilon/10;
        count = count + 1;
        float temp = 1- float_epsilon;
        float small = 1 - temp;
        printf("%d: Epsilon = %1.10e\n",count,small);
        if(small == 0.0){
           return count;
        }else if(count>10000){
           printf("To many recurrance calls");
           return 0;
        }else{
         smaller_float(float_epsilon,count);
        }
}


int smaller_double(double double_epsilon,int count){
        double_epsilon = double_epsilon/10;
        count = count + 1;
        double temp = 1- double_epsilon;
        double small = 1 - temp;
        printf("%d: Epsilon = %1.10e\n",count,small);
        if(small == 0.0){
           return count;
        }else if(count>10000){
           printf("To many recurrance calls");
           return 0;
        }else{
         smaller_double(double_epsilon,count);
        }
}
