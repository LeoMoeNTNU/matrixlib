#include "../linkedlistintpointer.h"//the interface im testing. 
#include <stdio.h>//for printf
#include <stdbool.h>

int main(int argc, char **args)
{
    int a=1;
    int b=2;
    int c=4;
    int d=5;
    void* pointers[]={&a,&b,&c,&d};

    
    int elements = 4;
    void *linkedlist = 0; // det er en null verdi.
    for (int i = 0; i < 4; i++)
    {
        linkedlist = addToPointerList(pointers[i], linkedlist, true);
    }
    void **result = getPointersOut(linkedlist, elements, true);
    for(int i=0;i<elements;i++){
        if(pointers[i]!=result[i]){
            printf("something is wrong!\n");
            goto end;
        }
    }

    printf("it did work!\n");
    printf("to ensure that we actually have the int that we want here:\n");

    int**resultasint=result;
    for(int i=0;i<elements;i++){
        printf("%d ",*resultasint[i]);
    }
    printf("\n");


    end:

    return 0;
}