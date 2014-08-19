


double force_y(double y,double r);
double force_x(double x,double r);
double energy(double r, double v_y, double v_x);
double angular_momentum(double r, double theta, double v_x, double v_y);

int main(int argc, char **argv){
    double* q_x = calloc(2, sizeof(double));
    double* q_y = calloc(2, sizeof(double));
    printf("Intial position in x : ");
    scanf("%lf",&q_x[0]);
    printf("Intial velocity in y : ");
    scanf("%lf",&q_y[1]);
    FILE *f = fopen("output.txt","w");
    FILE *f_1 = fopen("out3.txt","w");
    //q_x[0] = 1.0; // position
    q_x[1] = 0.0; // momentum 
    q_y[0] = 0.0;
    //q_y[1] = 1.0;

    int n = 10000;
    double h = (2*PI)/n;
    double int_E = energy(sqrt(pow(q_x[0],2) + pow(q_y[0],2)),q_x[1],q_y[1]);
    double int_L = angular_momentum(q_x[0],q_y[0],q_x[1],q_y[1]);
    fprintf(f,"x \t y \t R  \n");
    fprintf(f_1,"%s \t %s \t %s \t %s \t %s\n","Time","E","L","Deviation in E","Deviation in L");
    for (int i = 0;i<=n;i++){
        double radius = sqrt(pow(q_x[0],2) + pow(q_y[0],2));
        double theta = atan2(q_y[0],q_x[0]);
        double E = energy(radius,q_x[1],q_y[1]);
        double L = angular_momentum(q_x[0],q_y[0],q_x[1],q_y[1]);
        fprintf(f,"%f \t %f \t %f\n",q_x[0] ,q_y[0],radius);
        fprintf(f_1,"%.5e \t %.5e \t %.5e\t",i*h,E,L);
        fprintf(f_1,"%.6e \t %.16e\n",fabs(E-int_E), fabs(L-int_L));
        PERLF(q_x,force_x,h,radius);
        PERLF(q_y,force_y,h,radius);
        

    }
    fclose(f);
    return 0;

}

double energy(double r, double v_y, double v_x){
    return (pow(v_x,2)+pow(v_y,2))/2.0 - (1.0/r);
}
double angular_momentum(double x, double y, double v_x, double v_y){
    return x*v_y - y*v_x;
}

double force_y(double y,double r){
    return (-1*y)/(pow(r,3));
}

double force_x(double x,double r){
    return (-1*x)/(pow(r,3));
}