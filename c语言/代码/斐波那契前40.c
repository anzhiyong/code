#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
void main()
{
    int i, f1, f2, f3;
    f1 = 1;
    f2 = 1;
    f3 = f1 + f2;
    printf("%d\n%d\n", f1, f2);
    for (i = 2; i < 40; i++)
    {
        f3 = f1 + f2;
        printf("%d\n", f3);
        f1 = f2;
        f2 = f3;
    }
}