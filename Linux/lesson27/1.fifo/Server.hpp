#pragma once
#include "Comm.hpp"
class Init
{
public:
    Init()
    {
        int n = mkfifo(gpipePath.c_str(), 0600);
        if(n < 0)
        {
            std::cout << "mkfifo error" << std::endl;
        }
        std::cout << "mkfifo success" << std::endl;
        //sleep(10);
    }
    ~Init()
    {
        int n = unlink(gpipePath.c_str());
        if(n < 0)
        {
            std::cout << "unlink error" << std::endl;
        }
        std::cout << "unlink success" << std::endl;
    }
};

Init init;

class Server
{
public:
    Server():_fd(gdefaultfd)
    {}

    bool OpenPipeForRead()
    {
        _fd = OpenPipe(gread);
        if(_fd < 0)
            return false;
        return true;
    }

    //std::string *:输出型参数
    //const std::string &:输入性参数
    //std::string &:输入输出型参数
    int RecvPipe(std::string *out)
    {
        char buff[gsize];
        ssize_t n = ::read(_fd, buff, sizeof(buff) - 1);//    gsize?
        if(n > 0)
        {
            buff[n] = 0;
            *out = buff;
        }
        return n;
    }

    void ClosePipe()
    {
        ClosePipeHelper(_fd);
    }
    
    ~Server()
    {}

private:
    int _fd;
};