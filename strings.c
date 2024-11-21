#include "strings.h"
#include <stdio.h>
#include <stdlib.h>//for malloc

void printstring(char *c)
{
    while (*c != 0)
    {
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

string_t getword()
{
    char b[] = "things on things...";
    char *bp = (char*)&b;
    while (*bp != 0)
    {
        bp++;
    }
    int length = bp - (char *)&b + 1;
    char *retP = malloc(sizeof(char) * length);

    for (int i = 0; i < length; i++)
    {
        retP[i] = b[i];
    }

    return (string_t){retP, length};
}
int lengthofstring(char *a){
    char*b=a;
    
    while(*b!=0){b++;}
    return b-a;
}

//has to be freed
char* stringadd(char *a, char *b){
    const int lenA=lengthofstring(a);
    const int lenB=lengthofstring(b);
    //const is to help the compiler help me know the value isnt being changed. 
    char *retP=malloc(sizeof(char)*(lenA+lenB+1));
    for(int i=0;i<lenA;i++){
        retP[i]=a[i];
    }
    for(int i=0;i<lenB;i++){
        retP[lenA+i]=b[i];
    }
    retP[lenA+lenB]=0;
    //first I need to find length.
    return retP;
}
//slightly bigger version of the of the one over. 
//If I use the other one twice I quickly get lost memory because the other one wasnt freed.
char *stringaddthree(char *a, char *b, char *c){
    const int lenA=lengthofstring(a);
    const int lenB=lengthofstring(b);
    const int lenC=lengthofstring(c);
    char *retP=malloc(sizeof(char)*lenA+lenB+lenC+1);
    for(int i=0;i<lenA;i++){
        retP[i]=a[i];
    }
    for (int i = 0; i < lenB; i++)
    {
        retP[lenA+i] = b[i];
    }
    for (int i = 0; i < lenC; i++)
    {
        retP[lenA+lenB+i] = c[i];
    }
    retP[lenA+lenB+lenC]=0;
    return retP;
}
