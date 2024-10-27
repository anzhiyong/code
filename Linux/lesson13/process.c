#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

//监控代码
//while :; do ps axj | grep process|grep -v grep;sleep 1;echo "###########";done
int main()
{
    pid_t id= fork();
    if(id < 0)
    {
        printf("fork error");
        return 1;
    }
    else if(id == 0)
    {
        printf("child[%d]", getpid());
        sleep(5);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("parent[%d]", getpid());
        sleep(30);

    }

    return 0;
}