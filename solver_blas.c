/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include <stdlib.h>
#include "cblas.h"
#include "utils.h"
#include <sys/resource.h>
#define BAD_ALLOC 12
/* 
 * Add your BLAS implementation here
 */
double *my_solver(int N, double *A, double *B)
{
	/* Computing the main parameters used for computation */

	/* First element of the computation using BLAS */

	/**
	 * The blass function dgemm_ is used to process the result of
	 * the following equation:
	 * C := alpha*op( A )*op( B ) + beta*C,
	 * 
	 *  cblas_dgemm(
	 * 		CblasRowMajor, 
	 * 		CblasNoTrans, 
	 * 		CblasNoTrans,
     *	  	m, 
	 * 		n, 
	 * 		k, 
	 * 		alpha, 
	 * 		A, 
	 * 		k, 
	 * 		B, 
	 * 		n, 
	 * 		beta, 
	 * 		C,
	 * 		n);
	 * 
	 **/
	printf("\n======A====\n");
	for (li = 0; li < N; li++)
	{
		for (ci = 0; ci < N; ci++)
		{
			printf("%lf ", A[li * N + ci]);
		}
		printf("\n");
	}

	printf("\n====B======\n");

	for (li = 0; li < N; li++)
	{
		for (ci = 0; ci < N; ci++)
		{
			printf("%lf ", B[li * N + ci]);
		}
		printf("\n");
	}

	
	double *B_At;
	double *A2;
	double *A2_B;
	double *R;
	size_t li;
	size_t ci;

	B_At = (double *)calloc(N * N, sizeof(double));
	if (B_At == NULL)
		exit(BAD_ALLOC);

	A2 = (double *)calloc(N * N, sizeof(double));
	if (A2 == NULL)
		exit(BAD_ALLOC);

	A2_B = (double *)calloc(N * N, sizeof(double));
	if (A2_B == NULL)
		exit(BAD_ALLOC);

	R = (double *)calloc(N * N, sizeof(double));
	if (R == NULL)
		exit(BAD_ALLOC);

	double alpha = 1.0;
	double beta = 0.0;

	/*  B * At */
	cblas_dgemm(
		CblasRowMajor,
		CblasNoTrans,
		CblasTrans,
		N,
		N,
		N,
		alpha,
		B,
		N,
		A,
		N,
		beta,
		B_At,
		N);
	printf("\n=====B_At=====\n");
	for (li = 0; li < N; li++)
	{
		for (ci = 0; ci < N; ci++)
		{
			printf("%lf ", B_At[li * N + ci]);
		}
		printf("\n");
	}

	/* A2 */
	cblas_dgemm(
		CblasRowMajor,
		CblasNoTrans,
		CblasNoTrans,
		N,
		N,
		N,
		alpha,
		A,
		N,
		A,
		N,
		beta,
		A2,
		N);
	printf("\n====A2======\n");
	for (li = 0; li < N; li++)
	{
		for (ci = 0; ci < N; ci++)
		{
			printf("%lf ", A2[li * N + ci]);
		}
		printf("\n");
	}

	/* A2 * B */
	cblas_dgemm(
		CblasRowMajor,
		CblasNoTrans,
		CblasTrans,
		N,
		N,
		N,
		alpha,
		A2,
		N,
		B,
		N,
		beta,
		A2_B,
		N);
	printf("\n=====A2_B=====\n");
	for (li = 0; li < N; li++)
	{
		for (ci = 0; ci < N; ci++)
		{
			printf("%lf ", A2_B[li * N + ci]);
		}
		printf("\n");
	}


	for (li = 0; li < N; li++)
	{
		for (ci = 0; ci < N; ci++)
		{
			R[li * N + ci] = B_At[li * N + ci] + A2_B[li * N + ci];
		}
	}

	free(B_At);
	free(A2_B);
	free(A2);

	return R;
}
