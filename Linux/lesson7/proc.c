#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("hello Linux!");
    fflush(stdout);
    sleep(2);
    return 0;
}