
#define THETA 1.35120719195966

void position_verlet(double* q,double (*force)(double), double h ){
	q[0] = q[0] + THETA*(h/2.0)*q[1];
	q[1] = q[1] + THETA*h*(force)(q[0]);
    //printf("test %.15f\n",(force)(q[0]));
	//printf("xps = %.12f pps = %.12f \n theta=%f\n",q[0],q[1],THETA);
    q[0] = q[0] + (1.0-THETA)*(h/2.0)*q[1];
    q[1] = q[1] + (1.0-2.0*THETA)*h*(force)(q[0]);
    q[0] = q[0] + (1-THETA)*(h/2.0)*q[1];
    q[1] = q[1] + THETA*h*(force)(q[0]);
    q[0] = q[0] + THETA*(h/2.0)*q[1];

}