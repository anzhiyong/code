#include "UdpServer.hpp"
#include "Log.hpp"

int main()
{
    LogModule::ENABLE_CONSOLE_LOG();
    std::unique_ptr<UdpServer> svr_uptr = std::make_unique<UdpServer>();
    svr_uptr->InitServer();
    svr_uptr->Start();
    return 0;
}