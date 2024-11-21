#include "numbers.h"

// What this one will do is check if the two numbers have a common divisor and in that case fix it.
void basiccleanse(num_t *num)
{
    int top = num->overslash;
    int bot = num->underslash;
    if ((top / bot) * bot == top)
    {
        num->overslash = top / bot;
        num->underslash = 1;
    }
}

// doesnt end with \n
void printnum(num_t *numP)
{
    printf("%d//%d", numP->overslash, numP->underslash);
}