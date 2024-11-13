// #include <iostream>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// 易变关键字
volatile int flag = 0;

void change(int signo) // 信号捕捉的执行流
{
    (void)signo;

    flag = 1;
    printf("change flag 0->1, getpid: %d\n", getpid());
}

int main()
{
    printf("I am main process, pid is : %d\n", getpid());
    signal(2, change);

    while(!flag); // 主执行流--- flag我们没有做任何修改！
    printf("我是正常退出的!\n");
}


// // printBLocklist
// void PirintBLock()
// {
//     sigset_t set, oset;
//     sigemptyset(&set);
//     sigemptyset(&oset);

//     sigprocmask(SIG_BLOCK, &set, &oset);
//     std::cout << "block: ";
//     for (int signo = 31; signo > 0; signo--)
//     {
//         if (sigismember(&oset, signo))
//         {
//             std::cout << 1;
//         }
//         else
//         {
//             std::cout << 0;
//         }
//     }
//     std::cout << std::endl;
// }

// void PrintPending()
// {
//     sigset_t pending;
//     ::sigpending(&pending);

//     std::cout << "Pending: ";
//     for (int signo = 31; signo > 0; signo--)
//     {
//         if (sigismember(&pending, signo))
//         {
//             std::cout << 1;
//         }
//         else
//         {
//             std::cout << 0;
//         }
//     }
//     std::cout << std::endl;
// }

// void handler(int signo)
// {
//     static int cnt = 0;
//     cnt++;
//     while (true)
//     {
//         std::cout << "get a sig: " << signo << ", cnt: " << cnt << std::endl;
//         // PirintBLock();
//         PrintPending();
//         sleep(1);
//         // break;
//     }
//     // exit(1);
// }

// int main()
// {
//     struct sigaction act, oact;
//     act.sa_handler = handler;
//     sigemptyset(&act.sa_mask);
//     sigaddset(&act.sa_mask, 3);
//     sigaddset(&act.sa_mask, 4);
//     sigaddset(&act.sa_mask, 5);
//     sigaddset(&act.sa_mask, 6);
//     sigaddset(&act.sa_mask, 7);

//     ::sigaction(2, &act, &oact);

//     while (true)
//     {
//         // PirintBLock();
//         PrintPending();
//         pause();
//     }
// }