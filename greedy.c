#include "max_salary.h"

int is_better(int bsf, int c){
	int length1 = digit_num(bsf);
	int length2 = digit_num(c);
	if (length1 == 1 && length2 == 1){
		if(bsf > c){
			return bsf;
		}else{
			return c;
		}
	}else{
		int a = bsf;
		int b = c;
		int m [length1];
		int n [length2];
		int count = 0;
		if(length1 == 1){
			m[0] = bsf;
		}else{	
			for(int i = length1; i > 0; i --){
				m[count] = a / ((int)pow(10, i - 1));
				a = a % ((int)pow(10, i - 1));
				count ++;
			}
			count = 0;
		}
		if(length2 == 1){
			n[0] = c;
		}else{
			for(int i = length2; i > 0; i --){
				n[count] = b / ((int)pow(10, i - 1));
				b = b % ((int)pow(10, i - 1));
				count ++;
			}
		}
		int k = 0;
		if(length1 > length2){
			k = length2;
		}
		else{
			k = length1;
		}
		for(int i = 0; i < k; i ++){
			if(m[i] > n[i]){
				return bsf;
			}else if(m[i] < n[i]){
				return c;
			}else{
				continue;
			}
		}
		if(length1 > length2){
			for(int j = length2; j < length1; j ++){
				if(m[j] > n[length2 - 1]){
					return bsf;
				}else if(m[j] == n[length2 - 1])
					continue;
				else
					return c;
			}
		}else{
			for(int j = length1; j < length2; j ++){
				if(n[j] > m[length1 - 1])
					return c;
				else if(n[j] == m[length1 - 1])
					continue;
				else
					return bsf;
			}
		}
	}
	return 0;
	
}

int digit_num(int n){
	if(n == 0){
		return 1;
	}else{
		int k = floor(log10(abs(n))) + 1;
		return k;
	}
}

int greedy(int a[], int size, int n){
	int b [n];
	int number = 0;
	for(int j = 0; j < n; j ++){
		b[j] = a[j];
		number += digit_num(a[j]);
	}
	int max = 0;
	int result = 0;
	int index = 0;
	while(n > 0){
		for(int i = 0; i < n; i ++){
			if(is_better(b[i], max) == b[i]){
				index = i;
				max = b[i];	
			}
		}
		result += b[index] * (int)pow(10, number - digit_num(b[index]));
		number -= digit_num(b[index]);
		b[index] = b[size - 1];
		b[size - 1] = 0;
		size --;
		n --;
		max = 0;
	}
	return result;
}
