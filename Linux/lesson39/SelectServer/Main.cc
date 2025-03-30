#include "SelectServer.hpp"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "Usage： " << argv[0] << " port" << std::endl;
        exit(1);
    }
    ENABLE_CONSOLE_LOG();
    uint16_t local_port = std::stoi(argv[1]);

    std::unique_ptr<SelectServer> ssvr = std::make_unique<SelectServer>(local_port);
    ssvr->Init();
    ssvr->Start();

    return 0;
}