#include <iostream>
#include <string>
#include "Server.hpp"

int main()
{
    Server server;
    std::string s;
    server.OpenPipeForRead();
    while(true)
    {
        if(server.RecvPipe(&s) > 0)
        {
            std::cout << "client say#" << s << std::endl;
        }
        else
        {
            break;
        }
    }
    std::cout << "client quit, me too!" << std::endl;
    server.ClosePipe();

    return 0;
}