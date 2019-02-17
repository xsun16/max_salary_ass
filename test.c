
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "max_salary.h"
#include "greedy_max.h"
#include "max_salary_naive.c"
#include "greedy_max_fun.c"

void print_array(int *arr, int size){
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void short_test (int *num, int n){
    print_array(num, n);
    char * result1 = get_max_native(num, n);
    char * result2 = get_max_salary(num, n);
    printf("Number of Max: result1=%s, result2=%s\n", result1, result2);
}

void stress_test(int N, int M){
    static char charset[] = "123456789";
    srand(time(NULL));   // Initialization, should only be called once.

    while (1) {
        int n = rand() % N + 1;      
        int m = rand() % M + 1;


        
        int *source = malloc(m);
        for (int i=0; i<m; i++){
            char *text = malloc(n+1);
            int j = 0;
            for (j=0; j<n; j++){
                int pos = rand() % (int)(sizeof(charset) -1);
                text[j] = charset[pos];
            }
            text[j] = '\0';
            source[i] = atoi(text);
            free(text);
        }
        print_array(source, m);

        char * result1 = get_max_native(source, m);
        printf("get result 1: %s\n", result1);
        char * result2 = get_max_salary(source, m);
        printf("get result 2: %s\n", result2);
        if (strcmp(result1, result2) == 0)
            printf("OK\n");
        else {
            printf("Wrong answer: correct=%s, got instead=%s\n", result1, result2);
            exit(0);
        }
        free(source);
    }
}

int get_size (char * str) {
    int count = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if(',' == str[i]) {
            count ++ ;
        }
    }
    return count;
}

int main(int argc, char **argv ){
    if (argc < 2){
        printf("To run: test <1> <number of list (ex: {1,2,3,4})> \n");
        return 0;
    }

    int mode = atoi(argv[1]);

    if (mode == 1){
        if (argc < 4){
            printf("To run: test <2> <num> <size> \n");
            return 0;
        }
        int N = atoi(argv[2]);
        int M = atoi(argv[3]);
        stress_test(N, M);
        return 0;
    }
    char * source = argv[1];
    int * result = malloc(sizeof(int) * argc - 2);
    for (int i = 2; i < argc; ++i) {
        result[i-2] = atoi(argv[i]);
    }

    short_test(result, argc-2);

    return 0;

}

