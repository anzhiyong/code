#pragma once
#include "Comm.hpp"

class Client
{
public:
    Client():_fd(gdefaultfd)
    {}

    bool OpenPipeForWrite()
    {
        _fd = OpenPipe(gwrite);
        if(_fd < 0)
            return false;
        return true;
    }

    //std::string *:输出型参数
    //const std::string &:输入性参数
    //std::string &:输入输出型参数
    int SendPipe(const std::string &in)
    {
        return write(_fd, in.c_str(), in.size());
    }

    void ClosePipe()
    {
        ClosePipeHelper(_fd);
    }
    
    ~Client()
    {}

private:
    int _fd;
};