#ifndef NUMBERS_H
#define NUMBERS_H

typedef struct
{
    int overslash;
    int underslash;
} num_t;

void basiccleanse(num_t *num);
void printnum(num_t *numP);
//I will probably move some stuff around. 

#endif