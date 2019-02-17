CC = gcc
CFLAGS = -Wall -std=c99

all:test

greedy.o: greedy.c max_salary.h
	$(CC) $(CFLAGS) -c greedy.c

max_salary_naive.o: max_salary_naive.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_naive.c

test.o: test.c max_salary.h
	$(CC) $(CFLAGS) -c test.c

test: greedy.o max_salary_naive.o test.o
	$(CC) $(CFLAGS) -o test greedy.o max_salary_naive.o test.o

clean:
	rm *.0 test

