#include <stdio.h>

int flag = 0;

int Sum(int s, int e)
{
    int sum = 0;
    int i = s;
    for(; i <=e; i++)
    {
        sum += i;
    }

    return sum*flag;
}

int Add(int x, int y)
{
    return x + y;
}

int div(int x, int y)
{
    if(y == 0) return -1;
    int z = x/y;
    return z;
}

int main()
{
    printf("process is running\n");

    int start = 1;
    int end = 100;
    int result = Sum(start, end);
    printf("process is done, result: %d\n", result);

    int a = div(10, 0);
    printf("process is done, div result: %d\n", a);

    int b = Add(10, 20);
    printf("process is done, add result: %d\n", b);

    return 0;
}
