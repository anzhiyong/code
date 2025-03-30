#include "UdpClient.hpp"
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << "server_ip server port" << std::endl;
        exit(1);
    }
    std::string server_ip = argv[1];
    int server_port = stoi(argv[2]);

    //1.创建套接字
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
    {
        std::cerr << "socket error" << std::endl;
        exit(0);
    }

    //2.用户输入
    while(true)
    {

    }

    return 0;
}