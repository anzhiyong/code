#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
int main()
{
    // 1.创建管道
    int fds[2] = {0};
    int n = pipe(fds);
    if (n != 0)
    {
        cout << "pipe error" << endl;
        return 1;
    }

    // father->read
    // children->write
    //  2.创建子进程
    pid_t id = fork();
    // fork返回值等于0子进程创建成功，小于0创建失败，大于零返回子进程的pid
    if (id < 0)
    {
        cout << "fork error" << endl;
    }
    else if (id == 0)
    {
        // 子进程关闭读权限
        close(fds[0]);
        int cnt = 0;
        int total = 0;
        while (true)
        {
            string message = "h";
            message += to_string(cnt);
            cnt++;
            total = write(fds[1], message.c_str(), message.size());
            cout << "total:" << total << endl;

            sleep(1);
        }

        exit(0);
    }
    else
    {
        // 父进程
        close(fds[1]);
        char buffer[1024];
        while (true)
        {
            sleep(100);
            size_t n = ::read(fds[0], buffer, 1024);
            if (n > 0)
            {
                buffer[n] = 0;
                cout << "child-message:" << buffer << endl;
            }
            else if (n == 0)
            {
                // n==0 ,写端关闭了
                std::cout << "n:" << n << std::endl;
                std::cout << "child quit ??? me too" << std::endl;
                break;
            }
            close(fds[0]);
            break;
        }
        int status = 0;
        pid_t p = waitpid(id, &status, 0);
        std::cout << "father wait child success: " << p << " exit code: " <<
         ((status << 8) & 0xFF) << ", exit sig: " << (status & 0x7F) << std::endl;
    }

    return 0;
}