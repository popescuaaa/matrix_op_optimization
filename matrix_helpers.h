#ifndef _MATRIX_HELPERS_
#define _MATRIX_HELPERS_

#include <stdlib.h>

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
 * @param: N: int number of elements per line/colum in each matrix
 * @param: A: double* the first matrix stored as a vector
 * @param: B: double* the second matrix stored as a vector
 * @return: The matrix A and B addition result
 * 
 **/ 
double* matrix_add(int N, double* A, double* B)
{
    size_t li;
    size_t ci;
    double* R = (double *) malloc(N * N * sizeof(double));
    if (R == NULL)
        exit(BAD_ALLOC);
    
    for (li = 0; li < N; li++) {
        for (ci = 0; ci < N; ci++) {
            R[li * N + ci] = A[li * N + ci] + B[li * N + ci];   
        }
    }
    
    return R;
}

/**
 * @param: N: int number of elements per line/colum in each matrix
 * @param: A: double* the first matrix stored as a vector
 * @param: B: double* the second matrix stored as a vector
 * @return: The matrix A and B substraction result
 * 
 **/ 
double* matrix_substract(int N, double* A, double* B)
{   
    size_t li;
    size_t ci;
    double* R = (double *) malloc(N * N * sizeof(double));
    if (R == NULL)
        exit(BAD_ALLOC);
    
    for (li = 0; li < N; li++) {
        for (ci = 0; ci < N; ci++) {
            R[li * N + ci] = A[li * N + ci] - B[li * N + ci];   
        }
    }
    
    return R;
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
double* multiply_neopt(int N, double *A, double *B) 
{   
    size_t li;
    size_t ci;
    size_t hi;
    double *R = (double *) malloc(N * N * sizeof(double));
    if (R == NULL)
        exit(BAD_ALLOC);

    for (li = 0; li < N; li++) {
      for (ci = 0; ci < N; ci++) {
        R[li * N + ci] = 0.0;
	    for (hi = 0; hi < N; hi++) {
              R[li * N  + ci] += A[li * N + hi] * B[hi * N + ci];
        }
      }
    }
    
    return R;
}

/**
 * Optimal version of the matrix multiplication algorithm 
 * using cache and compiler technique.
 * 
 * @param: N: int number of elements per line/column
 * @param: A: double* the first matrix stored as a vector
 * @param: B: double* the second matrix stored as a vector
 * @return: The matrix A and B multiplication result
 * 
 **/ 
double* multiply_opt(int N, double* A, double* B)
{
    size_t li;
    size_t ci;
    size_t hi;

    double *R = (double *) malloc(N * N * sizeof(double));
    if (R == NULL)
        exit(BAD_ALLOC);

    for (li = 0; li < N; li++) {

        double *orig_pa = A + li;

      for (ci = 0; ci < N; ci++) {
        
        double *pa = orig_pa;
        double *pb = B + ci;
        register double sum = 0.0;

	    for (hi = 0; hi < N; hi++) {
            sum += *pa * *pb;
            pa++;
            pb += N;
            // sum += A[li * N + hi] * B[hi * N + ci];
        }

        R[li * N + ci] = sum;
      }
    }
    
    return R;
}   

#endif // _MATRIX_HELPERS_
