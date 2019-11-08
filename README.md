# (Pthreads) Multiplication of square matrices

#h1mulmatrix.c:
Multiplication of two square matrix in parallel, with order N.
(mNxN * vNxN).

##h2 To compile the code:
gcc mulmatrix.c -o mulmatrix -pthread

##h2 To run the code:
./mulmatrix

##h2Details:
Inside the code, edit the numbers of defines at the beginning of the file, with numbers whatever you want.

example:<br/>
```
#define nt 4    //is the number of threads is created in execution.<br/>
#define nt 1000 //N:is the order of the matrix square<br/>
#define seed 100 //is the  seed of rand(), or seed ==100 ->  numbers between 0 - 100 in matrix<br/>
```
