#ifndef LINKEDLISTINT_H
#define LINKEDLISTINT_H

#include <stdbool.h>
typedef struct
{
    int i;
    void *p;
} intNode_t;

void *addToIntList(int newInt, intNode_t *oldPointer,bool testing);
int* getIntsOut(intNode_t *inp, int length,bool testing);

#endif

