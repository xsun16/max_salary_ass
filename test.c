#include "max_salary.h"

int main(){
	srand(time(NULL));
	while(1){
		int a[4];
		printf("The number list is: ");
		for(int i = 0; i < 4; i ++){
			a[i] = rand() % 100;
			printf("%d ", a[i]);
		}
		printf("\n");
		int r1 = 0;
		int n = 4;
		heap_permutation(a, n, n, &r1);
    		int r2 = greedy(a, n, n);
		    		
   		if (r1 == r2){
     			printf("OK\n");
			printf("The maximum salary is %d\n", r2);
		}
    		else{
      			printf("Wrong answer: correct=%d, got instead=%d\n", r1, r2);
	  		exit(0);
		}
	}

}
