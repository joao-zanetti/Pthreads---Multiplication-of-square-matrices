# (Pthreads) Multiplication of square matrices

## mulmatrix.c:
Multiplication of two square matrix in parallel, with order N. The Multiplication will split in nt threads.
Each thread will do the multiplication of N/nt lines of matrix m with N columns of matrix v.
mNxN * vNxN = resNxN

## To compile the code:
gcc mulmatrix.c -o mulmatrix -pthread

## To run the code:
./mulmatrix

## Details:
Inside the code, edit the numbers of defines at the beginning of the file, with numbers whatever you want.

### example:<br/>
```
#define nt 4    //is the number of threads is created in execution.
#define nt 1000 //N:is the order of the matrix square
#define seed 100 //is the  seed of rand(), or seed ==100 ->  numbers between 0 - 100 in matrix
```

### Performance:<br/>
For better load balancing, the numbers of threads (nt) selected in define must be higher than number of processors: nt> processors.<br/>
This improve lowest idleness of processors

