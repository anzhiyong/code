#pragma once
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

const std::string gpipePath = "./fifo";
const int gmode = 0600;
const int gdefaultfd = -1;
const int gsize = 1024;
const int gread = O_RDONLY;
const int gwrite = O_WRONLY;

int OpenPipe(int flag)
{
    //如果读端打开时，写端还没打开，会堵塞在这里
    int fd = ::open(gpipePath.c_str(), flag);
    if (fd < 0)
    {
        std::cerr << "open error" << std::endl;
        return fd;
    }
    return fd;
}

void ClosePipeHelper(int _fd)
{
    if (_fd < 0)
        ::close(_fd);
}
