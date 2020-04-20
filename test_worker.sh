#!/bin/bash

#------------ Homework number 2 --------------- #
#       Andrei Gabriel Popescu 333CA            #
#                                               #
#-----------------------------------------------#

# Load modules                                  
module load compilers/gnu-5.4.0 

# Generate the executables
make

#------------- Execution for BLAS ---------------------
#
chmod 777 ./tema2_blas
chmod 777 ./tema2_neopt
chmod 777 ./tema2_opt_m

for (( c=1; c<=10; c++ ))
do  
    echo "Testing blas API method..."
    # Test blas flavour
    ./tema2_blas input &>> logfile
    ./tema2_blas custom_input &>> custom_logfile
    #------------------- Crectness -------------------------
    ./compare out1 /export/asc/tema2/out1 0.001
    ./compare out2 /export/asc/tema2/out2 0.001
    ./compare out3 /export/asc/tema2/out3 0.001

    # ------------- Execution for NEOPT --------------------
    #
    echo "Testing neoptimal method..."
    # Test neopt flavour
    ./tema2_neopt input &>> logfile
    ./tema2_neopt custom_input &>> custom_logfile

    #------------------- Crectness -------------------------
    ./compare out1 /export/asc/tema2/out1 0.001
    ./compare out2 /export/asc/tema2/out2 0.001
    ./compare out3 /export/asc/tema2/out3 0.001

    # ------------- Execution for OPT_M --------------------
    #
    echo "Testing optimal <<m>> method..."
    # Test opt_m flavour
    ./tema2_opt_m input &>> logfile
    ./tema2_opt_m custom_input &>> custom_logfile
    #------------------- Crectness -------------------------
    ./compare out1 /export/asc/tema2/out1 0.001
    ./compare out2 /export/asc/tema2/out2 0.001
    ./compare out3 /export/asc/tema2/out3 0.001

    # ------------- Execution for OPT_F --------------------
    #
    echo "Testing optimal <<f>> method..."
    # Test opt_m flavour
    ./tema2_opt_f input &>> logfile 
    ./tema2_opt_f custom_input &>> custom_logfile
    #------------------- Crectness -------------------------
    ./compare out1 /export/asc/tema2/out1 0.001
    ./compare out2 /export/asc/tema2/out2 0.001
    ./compare out3 /export/asc/tema2/out3 0.001

    # ------------- Execution for OPT_F_EXTRA --------------
    #
    echo "Testing optimal <<f_extra>> method..."
    # Test opt_m flavour
    ./tema2_opt_f_extra input &>> logfile
    ./tema2_opt_f_extra custom_input &>> custom_logfile
    #------------------- Crectness -------------------------
    ./compare out1 /export/asc/tema2/out1 0.001
    ./compare out2 /export/asc/tema2/out2 0.001
    ./compare out3 /export/asc/tema2/out3 0.001

done

