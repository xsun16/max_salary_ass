#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
void heap_permutation(int a[], int size, int n) ;
int is_better(int best_so_far, int current);
char * get_max_salary(int * arr, int size);
int count_digit(int num);
char * int_to_string(int num);
int judge_in(int num, int * arr, int size);
char * int_to_string(int num);
void print_array_char(char ** arr, int size);
char * int_arr_to_char_arr(int * a, int size);
int get_total(int num);
char* get_max_native_(int * arr, int n);

#endif
