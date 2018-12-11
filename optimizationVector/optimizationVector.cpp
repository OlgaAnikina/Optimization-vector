// optimizationVector.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <omp.h>
using namespace std;


typedef struct {
	int len;
	double *data;
} my_vector;

long my_vector_len(my_vector *v) {
	return v->len;
}

void foo_bar(my_vector *v, double *res)
{
	int v_leng = my_vector_len(v);
	long i;
	*res = 1;
	double* ar = v->data;
#pragma simd
	for (i = 0; i < v_leng; i++) {
		*res *= ar[i];
	}
}

const int leng = 66666666;
double a[leng];
my_vector v = { leng, a };


int main()
{
	double res;
	for (int i = 0; i < leng; i++) 
		a[i] = rand();
	unsigned int start_time = clock();
	foo_bar(&v, &res);
	unsigned int end_time = clock();
	cout <<"End of time : " << end_time - start_time << endl;

	return 0;
}

