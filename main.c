#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "strings.h"
#include "matrix.h"


void checkcontentsoffile(char* cp){
    FILE *fp;

    // fp=fopen(args[1],"r"); //not being used anymore.

    fp = fopen(cp, "r");
    if (fp == NULL)
    {
        printf("couldnt find file\n");
        return ;
    }

    bool done = false;
    char touse;
    int i = 0;
    while (!done)
    {
        touse = fgetc(fp);
        if (touse == EOF)
        {
            done = true;
        }
        else if (touse == '\n')
        {
            printf("\n");
            printf("ENTER\n");
        }
        else
        {
            printf("%c ", touse);
        }
        i++;
    }
    fclose(fp);
}

void testbasiccleanse(){
    num_t num={4,2};
    basiccleanse(&num);
    printnum(&num);
    printf("\n");
}

void testingvariables(){
    //This was just a test and I was right. Keeping it here because why not
    int a=10;
    int* pA=&a;
    int b=*pA;
    b=20;
    printf("%d\n",a);
}

void testingstringadd(){
    char a[]="hello";
    char b[]=" world";
    char *whole = stringadd((char *)&a, (char *)&b);
    printstring(whole);
    free(whole);
}

int main(int argc, char* args[]){

    //testingvariables();   


    char directory[]="txtfiles/";
    char fileName[]="matA";
    char filetype[]=".txt";
    char* fullfilename=stringaddthree((char*)directory,(char*)fileName,(char*)filetype);

    checkcontentsoffile(fullfilename);
    


    FILE* fp=fopen(fullfilename,"r");
    if(fp==NULL){printf("didnt find file!\n");}
    else{


        matrix_t m=parsematrix(fp);
        printf("height is %d and len is %d\n",m.height,m.len);
        printmatrix(m);
    }
    free(fullfilename);

    /*if(argc==1){
        printf("no arguments\n");
        return 0;
    }
    */
    //checkcontentsoffile(args[1]);//hopefully this does the same. Then I can comment it out later :)
    
}