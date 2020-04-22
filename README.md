# matrix_op_optimization
Computer Architecture Second Assignment 2020

## Implementations 

### Blas method 
> Considering the exposed API of the ATLAS BLAS librabry I decided to use the cblas_dgemm method that calcultes by default the result of the following equation:
``` R := alpha*op( A )*op( B ) + beta*C ```. Of course, in terms of parameters will be adapted as alpha = 1.0 and beta = 0.0. A couple of the results are displayed bellow. I decided not to use cblas_dtremm as the speed is similar becuase of the dimensions of the matrix is not in terms of 10^6 to see a specific slow down to the computation time for triangulars matrixes.
----
>```Run=./tema2_blas: N=400: Time=0.077897 Run=./tema2_blas: N=800: Time=0.383385 Run=./tema2_blas: N=1200: Time=1.229295 ```
----

