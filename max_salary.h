#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
void heap_permutation(int a[], int size, int n, int *arr) ;
int is_better(int bsf, int c);
int digit_num(int n);
int greedy(int a[], int size, int n);

#endif
