#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapsort.h"
#define PI 3.14159265358979323846

int right_child(int index);
int left_child(int index);
void build_heap(double* heap,int size);
void max_heapify(double* heap,int i,int size);
void num_ops();
int operations = 0.0;

void heapsort(double* heap, int size){
	build_heap(heap,size);
	for(int i = size-1; i>1;i--){
        double temp = heap[i];
        heap[i] = heap[1] ;
        heap[1] = temp;
        size = size -1;
        max_heapify(heap,1,size);

	}

}

void build_heap(double* heap,int size){
	for(int i = (size/2); i>=1; i--){
		max_heapify(heap,i,size);
	}
}
void max_heapify(double* heap,int i,int size){
	int largest;
	int left = left_child(i);
	int right = right_child(i);
	operations += 1;
	if(left < size &&  heap[left] > heap[i]){
		largest = left;
	}else{
		largest = i;
	}
	if(right < size &&  heap[right] > heap[largest]){
		largest = right;
	}
	if(largest != i){
		double temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		max_heapify(heap,largest,size);
	}

}


int left_child(int index){
    return 2*index;
}
int right_child(int index){
	return 2*index +1;
}

void num_ops(){
	printf("%d\n",operations );
}

bool bracketed(double big,double small,double value){
	if (value > small && value < big){
		return true;
	}else{
		return false;
	}

}