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

echo "Testing blas API method..."
# Test blas flavour
echo "--------------------------------" >> logile
./tema2_blas input &>> logile
echo "--------------------------------" >> logile
#------------------- Crectness -------------------------
./compare out1 /export/asc/tema2/out1 0.01
./compare out2 /export/asc/tema2/out2 0.01
./compare out3 /export/asc/tema2/out3 0.01

# ------------- Execution for NEOPT --------------------
#
echo "Testing neoptimal method..."
# Test neopt flavour
echo "--------------------------------" >> logile
./tema2_neopt input &>> logile
echo "--------------------------------" >> logile

#------------------- Crectness -------------------------
./compare out1 /export/asc/tema2/out1 0.01
./compare out2 /export/asc/tema2/out2 0.01
./compare out3 /export/asc/tema2/out3 0.01

# ------------- Execution for OPT_M --------------------
#
echo "Testing optimal <<m>> method..."
# Test opt_m flavour
echo "--------------------------------" >> logile
./tema2_opt_m input &>> logile
echo "--------------------------------" >> logile

#------------------- Crectness -------------------------
./compare out1 /export/asc/tema2/out1 0.01
./compare out2 /export/asc/tema2/out2 0.01
./compare out3 /export/asc/tema2/out3 0.01

# ------------- Execution for OPT_F --------------------
#
echo "Testing optimal <<f>> method..."
# Test opt_m flavour
echo "--------------------------------" >> logfile
./tema2_opt_f input &>> logile 
echo "--------------------------------" >> logfile

#------------------- Crectness -------------------------
./compare out1 /export/asc/tema2/out1 0.01
./compare out2 /export/asc/tema2/out2 0.01
./compare out3 /export/asc/tema2/out3 0.01

# ------------- Execution for OPT_F_EXTRA --------------
#
echo "Testing optimal <<f_extra>> method..."
# Test opt_m flavour
echo "--------------------------------" >> logfile
./tema2_opt_f_extra input &>> logile
echo "--------------------------------" >> logfile

#------------------- Crectness -------------------------
./compare out1 /export/asc/tema2/out1 0.01
./compare out2 /export/asc/tema2/out2 0.01
./compare out3 /export/asc/tema2/out3 0.01
