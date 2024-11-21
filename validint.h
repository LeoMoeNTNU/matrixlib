#ifndef VALIDINT
#define VALIDINT
#include <stdbool.h>
typedef struct
{
    bool valid;
    int value;
} validint_t;

validint_t maybeint(char cp);

#endif
