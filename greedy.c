#include "max_salary.h"

int is_better(int bsf, int c){
	int l1 = digit_num(bsf);
	int l2 = digit_num(c);
	if (l1 == 1 && l2 == 1){
		if(bsf > c){
			return bsf;
		}else{
			return c;
		}
	}else{
		int a = bsf;
		int b = c;
		int m [l1];
		int n [l2];
		int count = 0;
		if(l1 == 1){
			m[0] = bsf;
		}else{	
			for(int i = l1; i > 0; i --){
				m[count] = a / ((int)pow(10, i - 1));
				a = a % ((int)pow(10, i - 1));
				count ++;
			}
			count = 0;
		}
		if(l2 == 1){
			n[0] = c;
		}else{
			for(int i = l2; i > 0; i --){
				n[count] = b / ((int)pow(10, i - 1));
				b = b % ((int)pow(10, i - 1));
				count ++;
			}
		}
		int k = 0;
		if(l1 > l2){
			k = l2;
		}
		else{
			k = l1;
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
		if(l1 > l2){
			for(int j = l2; j < l1; j ++){
				if(m[j] > n[l2 - 1]){
					return bsf;
				}else if(m[j] == n[l2 - 1])
					continue;
				else
					return c;
			}
		}else{
			for(int j = l1; j < l2; j ++){
				if(n[j] > m[l1 - 1])
					return c;
				else if(n[j] == m[l1 - 1])
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
