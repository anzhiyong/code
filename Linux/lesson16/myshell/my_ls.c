#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// 1.考察进程等待的意义， 同时理解wait/waitpid函数的使用

// 2.要求：

// 2.1代码创建子进程， 父进程调用wait/waitpid函数进行等待， 子进程打印“i am child process”之后，等待5s钟结束子进程；

// 2.2 父进程在等待到子进程之后， 分析子进程的退出信号， coredump标志位以及退出码， 并打印到标准输出

// 3.提交要求：提交代码截图， 提交代码执行之后的截图
int main()
{
    pid_t id = fork();
    if (id < 0)
        return 1;
    if (id == 0)
    {
        // 子进程
        printf("i am child process");
        sleep(5);
        exit(0);
    }
    int status;
    pid_t rid = waitpid(id, &status, 0);
    if (rid < 0)
    {
        perror("wait error");
        exit(1);
    }

    // 分析子进程的退出状态
    if (WIFEXITED(status))
    {
        printf("子进程正常退出: %d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        printf("被信号终止: %d\n", WTERMSIG(status));
    }
    else if (WIFSTOPPED(status))
    {
        printf("被暂停: %d\n", WSTOPSIG(status));
    }

    return 0;
}

// 1.考察进程程序替换函数簇的函数，利用任一一个进程程序替换函数完成代码。

// 理解进程程序替换的本质， 在深层次的理解程序员在 命令行当中启动一个程序， 本质上是bash程序启动了一个子进程， 子进程程序替换成为程序员启动的程序

// 2.要求： 将启动程序替换成为“ls”程序， 并且要给“ls”程序指定命令行参数， “-l”和“-a”

// 3.提交要求：提交代码截图， 提交替换完成之后代码的运行的结果
// int main()
// {
//     char *s[] = {"ls", "-a", "-l", NULL};
//     execvp("ls", s);

//     return 0;
// }