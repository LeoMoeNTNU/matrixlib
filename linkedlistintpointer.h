#ifndef LINKEDLISTINTPOINTER_H
#define LINKEDLISTINTPOINTER_H

#include <stdbool.h>
typedef struct
{
    void* heldpointer;
    void *p;
} PointerNode_t;

void *addToPointerList(void* newIntP, PointerNode_t *oldPointer, bool testing);
void **getPointersOut(PointerNode_t *inp, int length, bool testing);

#endif