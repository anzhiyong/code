#include <iostream>
#include <string>
#include <cstdio>
#include <string.h>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int fun()
{
    std::cout << "hello world" << std::endl;

    _exit(23);
    //return 100;
    //exit(100);
}

int main()
{
    pid_t id = fork();
    if(id < 0)
    {
        printf("errno : %d, errstring: %s\n", errno, strerror(errno));
        return errno;
    }
    else if(id == 0)
    {
        int cnt = 5;
        while(cnt)
        {
            printf("子进程运行中， pid: %d\n", getpid());
            cnt--;
            sleep(1);
        }
        //int *p = nullptr;
        //*p = 100;
        // 我们可不可以使用全局变量，来获取子进程的退出码呢？
        exit(123);
    }
    else
    {
        //pid_t rid = wait(nullptr);
        int status = 0;
        // 为什么?我们只能通过系统调用获取退出信息
        pid_t rid = waitpid(id, &status, 0); // == wait
        if(rid > 0)
        {
            if(WIFEXITED(status))
            {
                printf("wait sub process success, rid: %d, status code: %d\n", rid, WEXITSTATUS(status)); // ??
            }
            else
            {
                printf("child process quit error!\n");
            }
        }
        else
        {
            perror("waitpid");
        }
        while(true)
        {
            printf("我是父进程: pid:%d\n", getpid());
            sleep(1);
        }
    }
   
   

   // while(true)
   // {
   //     int a = 1/0;
   //     printf("hello world\n");
   //     sleep(1);
   // }

   //char *p = nullptr;
   //*p = 'a';





    //printf("进程运行结束!\n");
    //sleep(2);
    //_exit(5);

    //sleep(2);

    //for(int i = 0; i < 200; i++)
    //{
    //    std::cout << "code :" << i <<", errstring: " <<strerror(i) << std::endl;
    //}
   // printf("before: errno : %d, errstring: %s\n", errno, strerror(errno));
   // 
   // FILE *fp = fopen("./log.txt", "r");
   // if(fp == nullptr)
   // {
   //     printf("after: errno : %d, errstring: %s\n", errno, strerror(errno));
   //     return errno;
   // }

    return 0;
}
