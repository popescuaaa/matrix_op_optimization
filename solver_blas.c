/*
 * Homework number 2 ASC 2020 
 * @author: Andrei Gabriel Popescu 333CA
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


	/**
	 * Here is the method that holds the ideea of 
	 * upper traingular but there is no significat time 
	 * improvement and I decided not to use this as basically
	 * I want at first to make a fair comparation with the optm_m.
	 * 
	 * 
	 * apha * A * B
	 * 
	 * cblas_dtrmm (
	 *  	CblasRowMajor,
	 * 		CblasLeft,
	 * 		CblasUpper,
	 * 		CblasNoTrans,
	 * 		CblasNonUnit,
	 * 		N,
	 * 		N,
	 * 		alpha,
	 * 		A,
	 * 		N,
	 * 		A, -> the result is in A
	 * 		N
	 * )
	 * 
	 * 
	 * 
	 *  A2 */
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

	/* A2 * B */
	cblas_dgemm(
		CblasRowMajor,
		CblasNoTrans,
		CblasNoTrans,
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
