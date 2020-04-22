            # Matrix optimization
--------------------------------------------------------------------------------------------
            ## Popescu Andrei Gabriel 333CA
--------------------------------------------------------------------------------------------
            > Computer Architecture Second Assignment 2020

            ## Implementations 

            ### Blas method 
            > Considering the exposed API of the ATLAS BLAS librabry I decided to 
            use the cblas_dgemm method that calcultes by default the result of the 
            following equation:
            R := alpha*op( A )*op( B ) + beta*C. 
            Of course, in terms of parameters will be adapted as alpha = 1.0 
            and beta = 0.0. A couple of the results are displayed bellow. I decided 
            not to use cblas_dtremm as the speed is similar becuase of the dimensions 
            of the matrix is not in terms of 10^6 to see a specific slow down to the 
            computation time for triangulars matrixes.
            ----
            Run=./tema2_blas: N=400: Time=0.077897 
            Run=./tema2_blas: N=800: Time=0.383385 
            Run=./tema2_blas: N=1200: Time=1.229295
            ----

            ### Nonoptimal method
            > For the nonoptimal method I choosed to use the classical matrix 
            multiplication algorithm in O(N^3) and this forced me to use the same complexity 
            in the next algorithm, the manul optimal implementation. As mean values for running 
            n different type of input here there are:
            ----
            Run=./tema2_neopt: N=400: Time=1.792944 
            Run=./tema2_neopt: N=800: Time=15.994570 
            Run=./tema2_neopt: N=1200: Time=61.052860
            ----
            I didn't made in the final variant of the homework the adaptation for 
            upper triagular matrix as the time difference was minimal, almost 
            inexistent for current matrix behaviours.


            ### Optimal manula method
            > For the optimal method there are a couple of steps that I've made in order to 
            reduce the time down. First was to use registers for sum values during the addition 
            loop (this step reduced the time significanlty) and then to use pointers for fast access. 
            One the other hand another significat speed improvment was a manul loop unrolling made for a 
            block size, as specified in the homework text, of 40. With all these from an average of 60s on 
            nonoptimal algorithm for N = 1200, I made it drop down to a medium value of 15s (more than 30% less) 
            analyzed for up to 100 script runs on the ibm_nehalem queue.
            ----
            Run=./tema2_opt_m: N=400: Time=0.868241 
            Run=./tema2_opt_m: N=800: Time=4.055339
            Run=./tema2_opt_m: N=1200: Time=15.25711
            ----


            ### Optimal f_extra flags explanation
            > Using O3 there are enabled a lot of flags that speed up 
            the computational process, but gcc stadnard has a specific speed flag, 
            the Ofast flag, that enables a couple of other flags. As Ofast is a multiple or 
            group flag specifier I just used the ffast-math flag, which is a shortcut for several 
            options, presenting the least conforming but fastest math mode. It enables -fno-trapping-math, 
            -funsafe-math-optimizations, -ffinite-math-only, -fno-errno-math, -fno-signaling-nans, 
            -fno-rounding-math, -fcx-limited-range and -fno-signed-zeros. Each of these flags violates 
            IEEE in a different way. -ffast-math also may disable some features of the hardware IEEE 
            implementation such as the support for denormals or flush-to-zero behavior. An example for 
            such a case is x86_64 with it's use of SSE and SSE2 units for floating point math. 
            [https://gcc.gnu.org/wiki/FloatingPointMath]. 

            ---
            > Then, another flag that I used is -funroll-loops, which as the name specifies 
            perform a force unroll on all loops. The results are comformilly reduced with a 
            small portion, vary from 5% to 6% from opt_f implementation executable.
            ---
            Run=./tema2_opt_f: N=400: Time=0.897131 
            Run=./tema2_opt_f: N=800: Time=4.404994 
            Run=./tema2_opt_f: N=1200: Time=13.264750 
            Run=./tema2_opt_f_extra: N=400: Time=0.887535 
            Run=./tema2_opt_f_extra: N=800: Time=4.068586 
            Run=./tema2_opt_f_extra: N=1200: Time=13.136699
            ---

            ### Logging method
            > For the testing process I choosed to use a a testing script that runs 
            on a couple of custom tests too. The script is in the archive and it was 
            ran on the queue a couple of times to gather data that will be processed by 
            a python script for plotting. The data will be send in the archive as a "logfile" for 
            the given input and then "custom_logile" for my tests that don't have a corectness check step.

            ### Performance analysis
            > There is a graph made with the data gatherd from multiple test sessions that shows 
            how the time evolution is for all 5 variants.



