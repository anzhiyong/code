#ifndef __UDP_SERVER_HPP__
#define __UDP_SERVER_HPP__

#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <strings.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Log.hpp"
#include "Common.hpp"

using namespace LogModule;


const static int gsockfd = -1;
const static std::string gdefaultip = "127.0.0.1"; // 表示本地主机，用来做测试或本地通信
const static uint16_t gdefaultport = 8080;

class UdpServer
{
public:
    UdpServer(const std::string ip = gdefaultip, uint16_t port = gdefaultport)
        : _sockfd(gsockfd),
          _ip(ip),
          _port(port)
    {
    }

    void InitServer()
    {
        // 1.创建socket (套接字)
        _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_sockfd < 0)
        {
            // std::cout << "socket error !" << std::endl;
            LOG(LogLevel::FATAL) << "socket:" << strerror(errno);

            Die(1);
        }
        LOG(LogLevel::INFO) << "socket success, sockfd is : " << _sockfd;

        // 2.填充网络信息，并bind绑定
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = ::inet_addr(_ip.c_str()); //1.string ip -> 4 bytes 2.network order
        local.sin_port = htons(_port); //主机序列转网络序列

        // 2.1 bind      bind()第二个参数要const sockaddr *类型，所以要强转
        int n = ::bind(_sockfd, CONV(&local), sizeof(local));
        if (n < 0)
        {
            // std::cout << "socket error !" << std::endl;
            LOG(LogLevel::FATAL) << "bind:" << strerror(errno);
            Die(2);
        }
        LOG(LogLevel::INFO) << "bind success ";
    }

    void Start()
    {
        _isrunning = true;
        while(_isrunning)
        {
            // 3.持续接受数据
            char buf[1024];
            struct sockaddr_in client;
            socklen_t len = sizeof(client);
            int n = recvfrom(_sockfd, buf, sizeof(buf), 0, CONV(&client), &len);
            if(n > 0)
            {
                // 1.消息内容是什么  &&  消息是谁发的
                buf[n] = 0;
                LOG(LogLevel::DEBUG) << "client say: " << buf;


                std::string echo_str = "echo##";
                echo_str += buf; 
                ::sendto(_sockfd,  echo_str.c_str(), echo_str.size(), 0, CONV(&client), len);


            }
        }
    }
        

    ~UdpServer()
    {
    }

private:
    int _sockfd;
    std::string _ip; // 服务器对应的ip
    uint16_t _port;  // 服务器未来的端口号
    bool _isrunning; //服务器状态
};

#endif