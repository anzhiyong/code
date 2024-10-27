#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    pid_t id = fork();
    if (id < 0)
    {
        printf("fork error\n");
        return 1;
    }
    else if (id == 0)
    {
        // 子进程
        while (1)
        {
            printf("i am child, pid:%d\n", getpid());
            sleep(2);
        }
    }
    else
    {
        while (1)
        {
            printf("i am father, pid:%d\n", getpid());
            sleep(1);
        }
    }

    return 0;
}