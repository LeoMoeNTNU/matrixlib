#include <stdbool.h> //because bool is nice. 
#include <stdio.h> //for file open and file read. 

#include "numbers.h"

typedef struct {
    int height;
    int len;
    void **p;
    bool valid;
}matrix_t;

//This one won't actually be in the interface in the future. 
//It will only be used in parsematrix, which is what is actually used in the file. 

matrix_t parsematrix(FILE *fp);
void printmatrix(matrix_t m);