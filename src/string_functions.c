#include <string.h>
#include <stdbool.h>
#include "string_functions.h"

bool streq(char str1[32], char str2[32])
{
    int ret;

    ret = strcmp(str1, str2);
    if(ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}