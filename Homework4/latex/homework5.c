
void bisection(double value, double* heap,int hi,int lo);
int main(int argc, char **argv){
	int order;
	printf("How many random numbers: 10^");
	scanf("%d",&order);
	int size =(int)pow(10,order);
	double* heap = calloc(size,sizeof(double*));
	srand(time(NULL));
	for(int i = 1; i<size ;i++){
	    double R =(rand()/(RAND_MAX+1.0));
	    heap[i] = R;
	    //printf("%f\n",R);
	}

    heapsort(heap,size);
	for(int i = 1; i<6 ;i++){
		printf("%f \n",heap[i] );
	}
	printf(".........\n");
	for(int i = size-7; i<size-1 ;i++){
		printf("%f \n",heap[i] );
	}
    bisection(.7,heap,size,0);
    printf("Number of operations: ");
    num_ops();
	return 0;
}

void bisection(double value, double* heap,int hi,int lo){
	int middle = (hi+lo)/2;
	if (middle == hi || middle == lo){
		printf("Found it between elements %d %d\n These have values %f %f\n",lo,hi, heap[lo],heap[hi]); 
		return;
	}
	if(heap[middle]<value){
		//printf("Go into %d to %d\n", middle,hi );
		bisection(value,heap,hi,middle);
	}else{
		//printf("Go into %d to %d\n", lo,middle );
		bisection(value,heap,middle,lo);
	}
     
}