#include <stdlib.h> //for malloc
#include "linkedlistintpointer.h"
#include <stdio.h>   //for printf
#include <stdbool.h> //for testing mode.
// to init a list, just put 0 as the old pointer.
void *addToPointerList(void *newPointer, PointerNode_t *oldPointer, bool testing)
{
    PointerNode_t *retp = malloc(sizeof(PointerNode_t));
    if (testing)
    {
        printf("putting %p into the LL\n", newPointer);
    }
    retp->heldpointer=newPointer;
    retp->p = oldPointer;
    return retp;
}

void **getPointersOut(PointerNode_t *inp, int length, bool testing)
{
    PointerNode_t *node = inp;
    void** retp = malloc(sizeof(void*) * length);
    int index = length - 1;
    while (index >= 0)
    {
        if (testing)
        {
            printf("withdrawing %p from the LL\n", node->heldpointer);
        }
        retp[index] = (void *)node->heldpointer;
        PointerNode_t *tofree = node;
        node = node->p;
        free(tofree);
        index--;
    }
    return retp;
}
