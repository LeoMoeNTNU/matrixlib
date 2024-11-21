#include "validint.h"
#include <stdbool.h>//I think its being used but idk.

validint_t maybeint(char cp)
{
    validint_t ret;
    ret.valid = (cp >= '0' && cp <= '9');
    ret.value = cp - '0';
    return ret;
}