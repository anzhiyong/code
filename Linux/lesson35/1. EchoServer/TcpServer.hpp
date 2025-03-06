#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#include "Log.hpp"
#include "Common.hpp"
#include "InetAddr.hpp"

#define BACKLOG 8

using namespace LogModule;

static const uint16_t gport = 8081;

class TcpServer
{
public:
    TcpServer(int port = gport) : _port(port), _isrunning(false)
    {
    }
    void InitServer()
    {
        // 1. 创建tcp socket
        _listensockfd = ::socket(AF_INET, SOCK_STREAM, 0); // Tcp Socket
        if (_listensockfd < 0)
        {
            LOG(LogLevel::FATAL) << "socket error";
            Die(SOCKET_ERR);
        }
        LOG(LogLevel::INFO) << "socket create success, sockfd is : " << _listensockfd;

        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(gport);
        local.sin_addr.s_addr = INADDR_ANY;

        // 2. bind
        int n = ::bind(_listensockfd, CONV(&local), sizeof(local));
        if (n < 0)
        {
            LOG(LogLevel::FATAL) << "bind error";
            Die(BIND_ERR);
        }
        LOG(LogLevel::INFO) << "bind success, sockfd is : " << _listensockfd;

        // 3. cs,tcp是面向连接的，就要求tcp随时随地等待被连接
        // tcp 需要将socket设置成为监听状态
        n = ::listen(_listensockfd, BACKLOG);
        if (n < 0)
        {
            LOG(LogLevel::FATAL) << "listen error";
            Die(LISTEN_ERR);
        }
        LOG(LogLevel::INFO) << "listen success, sockfd is : " << _listensockfd;

        // ::signal(SIGCHLD, SIG_IGN); // 子进程退出，OS会自动回收资源，不用在wait了
    }
    void HandlerRequest(int sockfd) // TCP也是全双工通信的
    {
        LOG(LogLevel::INFO) << "HandlerRequest, sockfd is : " << sockfd;
        char inbuffer[4096];
        while (true)
        {
            ssize_t n = ::read(sockfd, inbuffer, sizeof(inbuffer) - 1);
            if (n > 0)
            {
                LOG(LogLevel::INFO) << inbuffer;

                inbuffer[n] = 0;
                std::string echo_str = "server echo# ";
                echo_str += inbuffer;

                ::write(sockfd, echo_str.c_str(), echo_str.size());
            }
            else if (n == 0)
            {
                // read 如果读取返回值是0，表示client退出
                LOG(LogLevel::INFO) << "client quit: " << sockfd;
                break;
            }
            else
            {
                // 读取失败了
                break;
            }
        }
        ::close(sockfd); // fd泄漏问题！
    }
    void Start()
    {
        _isrunning = true;
        while (_isrunning)
        {
            // 不能直接读取数据
            // 1. 获取新连接
            struct sockaddr_in peer;
            socklen_t peerlen;
            LOG(LogLevel::DEBUG) << "accept ing ...";
            // 我们要获取client的信息：数据(sockfd)+client socket信息(accept || recvfrom)
            int sockfd = ::accept(_listensockfd, CONV(&peer), &peerlen);
            if (sockfd < 0)
            {
                LOG(LogLevel::WARNING) << "accept error: " << strerror(errno);
                continue;
            }

            // 获取连接成功了
            LOG(LogLevel::INFO) << "accept success, sockfd is : " << sockfd;
            InetAddr addr(peer);
            LOG(LogLevel::INFO) << "client info: " << addr.Addr();

            // version-0
            // HandlerRequest(sockfd);

            // version-1: 多进程版本
            pid_t id = fork();
            if (id == 0)
            {
                // child
                // 问题1: 子进程继承父进程的文件描述符表。两张，父子各一张
                // 1. 关闭不需要的fd
                ::close(_listensockfd);
                if(fork() > 0) exit(0); //子进程退出
                // 孙子进程 -> 孤儿进程 -> 1
                HandlerRequest(sockfd);
                exit(0);
            }
            ::close(sockfd);
            // 不会阻塞
            int rid = ::waitpid(id, nullptr, 0);
            if(rid < 0)
            {
                LOG(LogLevel::WARNING) << "waitpid error";
            }
        }
    }
    void Stop()
    {
        _isrunning = false;
    }
    ~TcpServer()
    {
    }

private:
    int _listensockfd; // 监听socket
    uint16_t _port;
    bool _isrunning;
};