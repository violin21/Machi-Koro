#include <string.h>
#include <stdbool.h>
#include "string_functions.h"

bool streq(char *str1, char *str2)
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