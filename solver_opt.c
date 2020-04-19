/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"
#define BAD_ALLOC 12

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
 * Optimal version of the matrix multiplication algorithm 
 * 
 * @param: N: int the number of elements per line/column in each matrix
 * @param: A: double* the first matrix stored as a vector
 * @param: B: double* the second matrix stored as a vector
 * @return: The matrix A and B multiplication result 
 * 
 **/ 
double* optimal_solver(int N, double *A, double* B) {
	
    size_t li;
    size_t ci;
    size_t hi;

	double* At = (double *) malloc(N * N * sizeof(double));
    if (At == NULL)
        exit(BAD_ALLOC);;

	double* A2 = (double *) malloc(N * N * sizeof(double));
    if (A2 == NULL)
        exit(BAD_ALLOC);

    double *LHS = (double *) malloc(N * N * sizeof(double));
    if (LHS == NULL)
        exit(BAD_ALLOC);

	double *RHS = (double *) malloc(N * N * sizeof(double));
    if (RHS == NULL)
        exit(BAD_ALLOC);


    /* Separately calculte the A * A matrix as A2 */ 

	for (li = 0; li < N; li++) {
        register double* p_A_orig = &A[li * N];

      for (ci = 0; ci < N; ci++) {
          register double* p_A = p_A_orig;
          register double* p_A_s = &A[ci];
          At[li * N + ci] = A[ci * N + li];
		  double register sum = 0.0;
	    for (hi = 0; hi < N; hi++) {
			/* A * A */
			sum += *p_A * *p_A_s;
            
            p_A++;
            p_A_s += N;
        }
        A2[li * N + ci] = sum;
      }
    }


    for (li = 0; li < N; li++) {

		double* p_A2_orig = &A2[li * N];
        double* p_B_orig = &B[li * N];

      for (ci = 0; ci < N; ci++) {

        register double lhs_sum = 0.0;
        register double rhs_sum = 0.0;

        register double* p_B_1 = p_B_orig;
        register double* p_A2 = p_A2_orig;

        register double* p_At = &At[ci];
        register double* p_B_2 = &B[ci];

	    for (hi = 0; hi < N; hi++) {
			/* B * At */
            lhs_sum += *p_B_1 * *p_At;

            /* A2 * B */
			rhs_sum += *p_A2 * *p_B_2;
            
            p_B_1++;
            p_A2++;
           
            p_At += N;
            p_B_2 += N;
        }

		LHS[li * N + ci] = lhs_sum;
        RHS[li * N + ci] = rhs_sum;
        LHS[li * N + ci] += RHS[li * N + ci];
      }
    }
    
	free(A2);
	free(RHS);
    return LHS;
}

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) 
{
	/* Computing the main parameters used for computation */ 
	double* R = optimal_solver(N, A, B);
	return R;	
}
