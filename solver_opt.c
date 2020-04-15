/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"
#include "matrix_helpers.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) 
{
	/* Computing the main parameters used for computation */ 
	size_t li;
	size_t ci;
	printf("A:");	
	for (li = 0; li < N; li++) {
		for (ci = 0; ci < N; ci++) {
			printf("%lf ", A[li * N + ci]);
		}
		printf("\n");
	}
	printf("At:");
	double* At = transpose(N, A);
	for (li = 0; li < N; li++) {
		for (ci = 0; ci < N; ci++) {
			printf("%lf ", At[li * N + ci]);
		}
		printf("\n");
	}
	printf("A2:");
	double* A2 = multiply_opt(N, A, A);
	for (li = 0; li < N; li++) {
		for (ci = 0; ci < N; ci++) {
			printf("%lf ", A2[li * N + ci]);
		}
		printf("\n");
	}
	printf("BAt:");
	double* T1 = multiply_opt(N, B, At);
	for (li = 0; li < N; li++) {
		for (ci = 0; ci < N; ci++) {
			printf("%lf ", T1[li * N + ci]);
		}
		printf("\n");
	}
	printf("A2B:");
	double* T2 = multiply_opt(N, A2, B);
	for (li = 0; li < N; li++) {
		for (ci = 0; ci < N; ci++) {
			printf("%lf ", T2[li * N + ci]);
		}
		printf("\n");
	}
	double* R = matrix_add(N, T1, T2);
	
	free(At);
	free(A2);
	free(T1);
	free(T2);

	return R;	
}
