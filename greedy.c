#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max_salary.h"
int power(int m, int n){
    	int res = 1;
    	for (int i = 0; i < n; ++i) {
        	res *= m;
    	}
    	return res;
}


int count_digit(int num){
    	int count;
    	for(count=0;num>=1;count++){
        	num = num / 10;
    	}
    	return count;
}

void print_array(int *arr, int size){
    	for (int i=0; i<size; i++){
        	printf("%d ",arr[i]);
    	}
    	printf("\n");
}

char * int_to_string(int num){
    	int len = count_digit(num);
    	char * str = malloc(len);
    	sprintf(str, "%d", num);
    	return str;
}


int is_better(int best_so_far, int current){
    	int len_so_far = count_digit(best_so_far);
    	char * str_so_far = int_to_string(best_so_far);
    	int len_current = count_digit(current);
    	char * str_current = int_to_string(current);
    	int index = 0;
    	while (1) {
        	if(index == len_so_far || index == len_current) break;
        		if(str_so_far[index] > str_current[index]) {
            			return 1;
        		} else if(str_so_far[index] < str_current[index]){
            			return 0;
        		}
        		index ++;
    	}
    	if (len_so_far > len_current) {
        	return is_better(best_so_far - current * power(10, len_so_far - len_current), current);
    	} else if(len_so_far < len_current){
        	return is_better(best_so_far, current - best_so_far * power(10, len_current - len_so_far));
    	} else {
        	return 1;
    	}
}

int judge_in(int num, int * arr, int size){
    	for (int i = 0; i < size; ++i) {
        	if(num == arr[i]) {
            		return 1;
        	}
    	}
    	return 0;
}

char * get_max_salary(int * arr, int size) {
    	int index;
    	int total_len = 0;
    	for (int index = 0; index < size; ++index) {
        	total_len += count_digit(arr[index]);
    	}
    	char * result = malloc(total_len);
    	int * sub_list = malloc(sizeof(int) * size);
    	for (int i = 0; i < size; ++i) {
        	sub_list[i] = -1;
    	}
    	int current = -1;
    	int current_index = -1;

    	for (int j = 0; j < size; ++j) {
        	current = arr[j];
        	current_index = j;
        	for (int k = 0; k < size; ++k) {
            		if (judge_in(k, sub_list, size) || k == j) {
                	continue;
            	}
            	int flag = is_better(current, arr[k]);
            	if (flag != 1 || judge_in(current_index, sub_list, size)){
                	current = arr[k];
                	current_index = k;
            	}
        	}
        	strcat(result, int_to_string(current));
        	sub_list[current_index] = current_index;
    	}
    	return result;
}

/*
void main() {
    //225 766 625 84
    //    int a[] = {225, 766, 625, 84};
    //        int n = sizeof a/sizeof a[0];
    //            char * m = get_max_salary(a, n);
    //                printf("%s\n", m);
    //                }
*/
