# (Pthreads) Multiplication of square matrices

mulmatrix.c:
Multiplication of two square matrix in parallel, with order N.
(mNxN * vNxN).

To compile the code:
gcc mulmatrix.c -o mulmatrix -pthread

To run the code:
./mulmatrix

Details:
Inside the code, change at the beginning of the file the defines.

example:<br/>
```
#define nt 4    //is the number of threads is created in execution.<br/>
#define nt 1000 //N:is the order of the matrix square<br/>
#define seed 100 //is the  seed of rand(), or seed ==100 ->  numbers between 0 - 100 in matrix<br/>
```
