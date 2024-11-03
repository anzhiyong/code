#include <iostream>
#include "Client.hpp"

int main()
{
    Client client;
    std::string s;
    client.OpenPipeForWrite();
    while(true)
    {
        std::getline(std::cin, s);
        client.SendPipe(s);
    }
    client.ClosePipe();

    return 0;
}