#include "max_salary.h"
#include <string.h>

int * best_arr;

void print_array(int *arr, int size){
  	for (int i=0; i<size; i++){
    		printf("%d ",arr[i]);
  	}
  	printf("\n");
}

int count_digit(int num){
    	int count;
    	for(count=0;num>=1;count++){
        	num = num / 10;
    	}
    	return count;
}

char * int_to_string(int num){
    	int len = count_digit(num);
    	char * str = malloc(len);
    	sprintf(str, "%d", num);
    	return str;
}

void print_array_char(char ** arr, int size){
    	for (int i=0; i<size; i++){
        	printf("%s\n",arr[i]);
    	}
//    printf("\n");
}

char * int_arr_to_char_arr(int * a, int size){
    	int total_size = 0;
    	for (int j = 0; j < size; ++j) {
        	total_size += count_digit(a[j]);
   	}
    	char * arr = malloc(total_size + 1);
    	for (int i = 0; i < total_size; ++i) {
        	for (int j = 0; j < size; ++j) {
            		for (int k = 0; k < count_digit(a[j]); ++k) {
                		arr[i] = int_to_string(a[j])[k];
                		i++;
            		}
        	}
    	}
    	arr[total_size] = '\0';
    	return arr;
}


// Generating permutation using Heap Algorithm 
void heap_permutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then do something with the obtained permutation   
    	if (size == 1) 
    	{ 
        	//TO DO - instead of printing, insert your code for evaluating the next candidate array
        	print_array(a, n);
		for (int i = 0; i < total; ++i) {
            		if((*ls)[i] == 0) {
                		(*ls)[i] = int_arr_to_char_arr(a, n);
                		break;
            		}
        	} 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heap_permutation(a,size-1,n); 
  
        // if size is odd, swap first and last element 
        if (size%2==1) {
            SWAP(a[0], a[size-1]); 
		}
        // If size is even, swap ith and last element 
        else{
            SWAP(a[i], a[size-1]);
		}			
    } 
} 

int get_total(int num){
    int total = 1;
    for (int i = 1; i < num+1; ++i) {
        total *= i;
    }
    return total;
}

char* get_max_native(int * arr, int n){
    int total = get_total(n);
    char ** ls = malloc(total * n * sizeof(char *));
    heap_permutation(arr, n, n, 0, &ls, total);
    print_array_char(ls, total);
    char * max = "";
    for (int i = 0; i < total; ++i) {
        if(strcmp(ls[i], max)>0) {
            max = ls[i];
        }
    }
    return max;
}
  
// Code to test permutations
/*
int main() { 
    int a[] = {1, 2, 3, 4}; 
    int n = sizeof a/sizeof a[0]; 
    heap_permutation(a, n, n); 
    return 0; 
} */
