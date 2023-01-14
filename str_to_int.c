#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "account.h"
#include "post.h"
#define TRUE 1
#define FALSE 0
#define ASCII 48

int str_to_int(char *str, int len)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        int ten = 1;
        for (int j = i; j < len - 1; j++)
        {
            ten *= 10;
        }
        printf("%d", ten);
        result += ((int)str[i] - ASCII) * ten;
    }
    return result;
}