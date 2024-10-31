#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>

class Channel
{
public:
    Channel(int wfd, pid_t who)
        :_wfd(wfd)
        ,_who(who)
    {
    }
    ~Channel()
    {
    }

private:
    int _wfd;
    std::string _name;
    pid_t _who;
};

int Usage(std::string pro)
{
    std::cout << "Usage:" << pro << "process-num" << std::endl;
    return 1;
}

void worker()
{

}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
    }

    std::vector<Channel> channel;

    // 1.先有管道
    // 2.创建进程
    int num = std::stoi(argv[1]);
    for (int i = 0; i < num; i++)
    {
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        if(n < 0)
            return 2;

        //创建进程
        pid_t id = fork();
        if(id < 0)
            return 3;

        //建立通信信道
        if(id == 0)
        {
            //子进程
            //让子进程从管道读数据，所以关掉写端口
            ::close(pipefd[1]);
            worker();

            ::exit(0);
        }

        //父进程
        //让父进程向管道写数据, 关闭读端口
        close(pipefd[0]);
        channel.emplace_back(pipefd[1], id);
        // Channel ch(pipefd[1]);
        // channel.push_back(ch);

    }

    return 0;
}