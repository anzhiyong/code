#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Log.hpp"
#include "InetAddr.hpp"
#include "Socket.hpp"

using namespace SocketModule;
using namespace LogModule;

#define NUM sizeof(fd_set) * 8

const int gdefaulted = -1;

class SelectServer
{
public:
    SelectServer(int port)
        : _port(port), _listen_socket(std::make_unique<TcpSocket>()), _isrunning(false)
    {
    }

    void Init()
    {
        _listen_socket->BuildTcpSocketMethod(_port);
        for (int i = 0; i < NUM; i++)
            _fd_array[i] = -1;

        _fd_array[0] = _listen_socket->Fd();
    }

    void Start()
    {
        fd_set rfds;
        _isrunning = true;
        while (_isrunning)
        {
            // 清空fds
            FD_ZERO(&rfds);
            // //设置fds
            // FD_SET(_listen_socket->Fd(), &rfds);
            struct timeval timeout = {1, 0};
            int maxfd = gdefaulted;
            for (int i = 0; i < NUM; i++)
            {
                if (_fd_array[i] == gdefaulted)
                    continue;
                FD_SET(_fd_array[i], &rfds);

                if (maxfd < _fd_array[i])
                {
                    maxfd = _fd_array[i];
                }
            }

            int n = select(maxfd + 1, &rfds, nullptr, nullptr, &timeout);
            switch (n)
            {
            case 0:
                std::cout << "time out" << std::endl;
                break;
            case -1:
                perror("select false");
                break;
            default:
                std::cout << "准备就绪 " << std::endl;
                // 处理
                HanderEvents(rfds);
                break;
            }
            // InetAddr client;
            // int newsocket = _listen_socket->Accepter(&client);
        }
        _isrunning = false;
    }

    void HanderEvents(fd_set &rfds)
    {
        for (int i = 0; i < NUM; i++)
        {
            if (_fd_array[i] == gdefaulted)
                continue;
            //
            if (_fd_array[i] == _listen_socket->Fd())
            {
                // 判断_listen_socket->Fd()是否在rfds中
                if (FD_ISSET(_listen_socket->Fd(), &rfds))
                {
                    InetAddr client;
                    int newfd = _listen_socket->Accepter(&client);
                    if (newfd < 0)
                        return;
                    else
                    {
                        std::cout << "获得了一个新链接：" << newfd << "client: " << client.Addr() << std::endl;
                        // recv
                        // 把newfd给select
                        int pos = -1;
                        for (int j = 0; j < NUM; j++)
                        {
                            if (_fd_array[j] == gdefaulted)
                            {
                                pos = j;
                                break;
                            }
                        }
                        if (pos == -1)
                        {
                            LOG(LogLevel::ERROR) << "服务器满载...";
                            close(newfd);
                        }
                        else
                        {
                            _fd_array[pos] = newfd;
                        }
                    }
                }
            }
            else
            {
                char buffer[1024];
                ssize_t n = recv(_fd_array[i], buffer, sizeof(buffer) - 1, 0);
                if (n > 0)
                {   
                    buffer[n] = 0;
                    std::cout << "client::" << buffer << std::endl;
                }
                else if (n == 0)
                {
                    LOG(LogLevel::DEBUG) << "客户端退出,socket:" << _fd_array[i];
                    close(_fd_array[i]);
                    _fd_array[i] = gdefaulted;
                }
                else
                {
                    LOG(LogLevel::DEBUG) << "客户端读取出错,socket:" << _fd_array[i];
                    close(_fd_array[i]);
                    _fd_array[i] = gdefaulted;
                }
                // 不会被阻塞了
            }
        }
    }
    ~SelectServer()
    {
    }

private:
    uint16_t _port;
    std::unique_ptr<Socket> _listen_socket;
    bool _isrunning;
    int _fd_array[NUM];
};