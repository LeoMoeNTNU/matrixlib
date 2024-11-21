#include <stdlib.h>//for malloc
#include "linkedlistint.h"
#include <stdio.h>//for printf
#include <stdbool.h>//for testing mode.
//to init a list, just put 0 as the old pointer. 
void* addToIntList(int newInt,intNode_t* oldPointer, bool testing){
    intNode_t* retp=malloc(sizeof(intNode_t));
    if(testing){
        printf("putting %d into the LL\n",newInt);
    }
    retp->i=newInt;
    retp->p=oldPointer;
    return retp;
}

int* getIntsOut(intNode_t* inp,int length,bool testing){
    intNode_t* node=inp;
    int* retp=malloc(sizeof(int)*length);
    int index=length-1;
    while(index>=0){
        if(testing){
            printf("withdrawing %d from the LL\n",node->i);
        }
        retp[index]=node->i;
        intNode_t* tofree=node;
        node=node->p;
        free(tofree);
        index--;
    }
    return retp;
}

