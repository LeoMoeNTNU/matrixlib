#ifndef STRINGS_H
#define STRINGS_H

typedef struct
{
    char *cp;
    int len;
} string_t;

void printstring(char *c);

int lengthofstring(char *a);

char* stringadd(char *a, char *b);
char *stringaddthree(char *a, char *b,char* c);

#endif
