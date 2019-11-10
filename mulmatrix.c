#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//NUMBER OF THREADS
#define nt 4 
//SQUARE MATRIX SIZE  NxN (mNxN, vNxN, resNxN)
#define N 100
#define seed 10


//GLOBAL STATEMENTS
//Shared memory: all the pthreads can access these variables
//M x V = Y
//Range is the number of iteractions of each thread
int m[N][N],v[N][N],res[N][N],range=N/nt;


//Struct for each thread
typedef struct
{
    int index; //index vector of the thread
    pthread_t id; //id of the thread
}pt;


//function calculates the multiplication of  N/nt  lines of the matrix per thread
void *calculate(void *ptr){
    int i,j,k,aux,initrange,rangelocal=0;
    long int id;
    pt *pa= (pt*)ptr;

    if((*pa).index==nt-1){ //if number(nt) of threads is odd  
        rangelocal=range+(N%nt); //the last thread 
    }
    else{
        rangelocal=range;
    }

    initrange=(*pa).index*range;
    //calculates the multiplication of rangelocal lines of matrix
    for (i=initrange; i<initrange+rangelocal; i++){
        for (j = 0; j<N; j++){
           aux=0;
           for (k = 0; k<N; k++){
           aux+=(m[i][k]*v[k][j]);
            }
            res[i][j]=aux;
        }
    }

}

//function prints matrix NxN
void printmatrix(int matrix[N][N]){
    int i,j;

    printf("MATRIX:\n");
    for (i = 0; i < N; i++){
       for (j = 0; j < N; j++){
          printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//initializes the matrices m,v,res
void initmatrices(){
    int i,j;

    for (i = 0; i < N; i++){
       for (j = 0; j < N; j++){
          m[i][j]=rand()%seed;
          v[i][j]=rand()%seed;
          res[i][j]=0;
        }
    }
    printmatrix(m);
    printmatrix(v);
    printmatrix(res);
}


//initializes the matrices m,v,res FOR TEST THE CODE
//m={2,2,2,...} v={1,1,1,...} res={0,0,0,...}
void testinitmatrices(){
    int i,j;

    for (i = 0; i<N; i++){
       for (j = 0; j<N; j++){
           v[i][j]=1;
           m[i][j]=2;
           res[i][j]=0;
        }
    }
    printmatrix(v);
    printmatrix(m);
    printmatrix(res);
}


int main(void){

    int i,j,k,aux;
    pt *p;

    p=malloc(nt*sizeof(pt));

    //initializes the matrices m,v,res
    initmatrices();
    //if you wanna test the code, comment the function initmatrices() 
    //and uncomment the function testinitmatrices()
    //testinitmatrices(); 


    //create nt threads
    for (i = 0; i < nt; i++){
        p[i].index=i;
        if(pthread_create(&p[i].id, NULL,calculate,(void*)&p[i])) {
            fprintf(stderr, "Error creating thread\n");
            return -1;
        }
    }

    //wait nt threads to finish
    for (i = 0; i < nt; i++){
        if(pthread_join(p[i].id, NULL)){
            fprintf(stderr, "Error joining thread\n");
            return -i;
        }
    }

    //print matrix result of multiplication
    printmatrix(res);

    return 0;
}

