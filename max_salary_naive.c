#include "max_salary.h"
#include <math.h>

int * best_arr;

void print_array(int *arr, int size){
  	for (int i=0; i<size; i++){
    		printf("%d ",arr[i]);
  	}
  	printf("\n");
}
 
void heap_permutation(int a[], int size, int n, int *arr) { 
    	if (size == 1) { 
        	int value = 0;
		int counter = 0;
		for(int i = 0; i < n; i ++){
			counter += digit_num(a[i]);
		}
		for(int i = 0; i < n; i ++){
			value += a[i] * (int)pow(10, counter - digit_num(a[i]));
			counter -= digit_num(a[i]);
		}
		if(value > *arr){
	       		*arr = value;
		}
		return;	
    	} 
  
    	for (int i=0; i<size; i++) { 
        	heap_permutation(a,size-1,n, arr); 
  		if (size%2==1) {
            		SWAP(a[0], a[size-1]); 
		}
		else{
            		SWAP(a[i], a[size-1]);
	    	}			
    	} 
} 
