#include "TcpServer.hpp"
#include <memory>

using namespace LogModule;

int main()
{
    ENABLE_CONSOLE_LOG();
    
    std::unique_ptr<TcpServer> tsvr = std::make_unique<TcpServer>();

    tsvr->InitServer();
    tsvr->Start();

    return 0;
}