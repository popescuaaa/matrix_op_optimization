/*
 * Homework number 2 ASC 2020 
 * @author: Andrei Gabriel Popescu 333CA
 * 2020 Spring
 */
#include "utils.h"
#define BAD_ALLOC 12
#include <stdio.h>
#include <stdlib.h>

/**
 * @param: N: int - the number of elements per column / line
 * @param: M: double* - the matrix stored as a vector N * N 
 * @return: The transpose of a matrix
 * 
 **/ 
double* transpose(int N, double *M)
{   
    size_t li;
    size_t ci;
    double *T = (double*) malloc(N * N * sizeof(double));
    if (T == NULL)
        exit(BAD_ALLOC);

    for (li = 0; li < N; li++) {
        for (ci = 0; ci < N; ci++) {
            T[li * N + ci] = M[ci * N + li];
        }
    }
    
    return T;
}


/**
 * Neoptimal version of the matrix multiplication algorithm 
 * 
 * @param: N: int the number of elements per line/column in each matrix
 * @param: A: double* the first matrix stored as a vector
 * @param: B: double* the second matrix stored as a vector
 * @return: The matrix A and B multiplication result 
 * 
 **/ 
double* nonoptimal_solver(int N, double *A, double *B) 
{   
    size_t li;
    size_t ci;
    size_t hi;

	double* At = transpose(N, A);

	double* A2 = (double *) malloc(N * N * sizeof(double));
    if (A2 == NULL)
        exit(BAD_ALLOC);

    double *LHS = (double *) malloc(N * N * sizeof(double));
    if (LHS == NULL)
        exit(BAD_ALLOC);

	double *RHS = (double *) malloc(N * N * sizeof(double));
    if (RHS == NULL)
        exit(BAD_ALLOC);

	for (li = 0; li < N; li++) {
      for (ci = 0; ci < N; ci++) {
		  A2[li * N + ci] = 0.0;
	    for (hi = 0; hi < N; hi++) {
			/* A * A */
			A2[li * N + ci] += A[li * N + hi] * A[hi * N + ci];
        }
      }
    }

    for (li = 0; li < N; li++) {
      for (ci = 0; ci < N; ci++) {
        LHS[li * N + ci] = 0.0;
		RHS[li * N + ci] = 0.0;
	    for (hi = 0; hi < N; hi++) {
			/* B * At */
            LHS[li * N + ci] += B[li * N + hi] * At[hi * N + ci];
            /* A2 * B */
			RHS[li * N + ci] += A2[li * N + hi] * B[hi * N + ci];
        }
		LHS[li * N + ci] += RHS[li * N + ci];
      }
    }
    
	free(A2);
	free(RHS);
    return LHS;
}

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) 
{
	/* Computing the main parameters used for computation */ 
	double* R = nonoptimal_solver(N, A, B);
	return R;
}
