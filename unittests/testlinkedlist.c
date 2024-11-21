#include "../linkedlistint.h"
#include <stdio.h>
#include <stdbool.h>


int main(int argc, char** args){
    int a[]={1,2,3,5};
    int* ap=a;//Idk if this is correct syntax. I could check with chat. 
    int elements=4;
    void* linkedlist=0;//det er en null verdi. 
    for(int i=0;i<4;i++){
        linkedlist=addToIntList(a[i],linkedlist,true);
    }
    int* result=getIntsOut(linkedlist,elements,true);
    for(int i=0;i<elements;i++){
        if(ap[i]!=result[i]){
            printf("it doesnt work!\n");
            goto end;

        }
    }
    printf("it did work!\n");

    end:

    return 0;
}



