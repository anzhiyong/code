#include <stdio.h>
#include <unistd.h>

int main()
{
    while(1)
    {
        printf("我是一个进程, 我的pid: %d, ppid, %d\n", getpid(), getppid());
        sleep(1);
    }
//    printf("父进程运行: pid: %d, ppid:%d\n", getpid(), getppid());
//
//    pid_t id = fork();
//    if(id == 0)
//    {
//        // 子进程
//        int cnt = 10;
//        while(1)
//        {
//            printf("我是子进程,我的pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//            sleep(1);
//            cnt--;
//        }
//    }
//    else
//    {
//        // 父进程
//        while(1)
//        {
//            printf("我是父进程,我的pid: %d, ppid: %d\n", getpid(), getppid());
//            sleep(1);
//        }
//    }

    return 0;
}
