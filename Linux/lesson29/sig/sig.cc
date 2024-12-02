#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

// void handler(int signo)
// {
//     std::cout << "get a sig: " << signo << " I am : " << getpid() << std::endl;
//     while (true)
//     {
//         pid_t rid = ::waitpid(-1, nullptr, WNOHANG);
//         if (rid > 0)
//         {
//             std::cout << "子进程退出了,回收成功,child id: " << rid << std::endl;
//         }
//         else if(rid == 0)
//         {
//             std::cout << "退出的子进程已经被全部回收了" << std::endl;
//             break;
//         }
//         else
//         {
//             std::cout << "wait error" << std::endl;
//             break;
//         }
//     }
// }

// 1. 验证子进程退出，给父进程发送SIGCHLD
// 2. 我们可不可以基于信号进行子进程回收呢？
int main()
{
    // signal(SIGCHLD, handler);
    // Linux下，将SIGCHLD的处理动作置为SIG_IGN,这样fork出来的子进程在终止时会自动清理掉
    ::signal(SIGCHLD, SIG_IGN);
    // 问题1: 1个子进程，10个呢？
    // 问题2: 10个子进程，6个退出了！
    for (int i = 0; i < 10; i++)
    {
        if (fork() == 0)
        {
            sleep(5);
            std::cout << "子进程退出" << std::endl;
            // 子进程
            exit(0);
        }
    }

    while (true)
    {
        sleep(1);
    }
    return 0;
}