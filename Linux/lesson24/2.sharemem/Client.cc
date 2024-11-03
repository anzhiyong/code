#include <iostream>
#include "Comm.hpp"

int main()
{
    key_t key = ftok(gpath.c_str(), gprojId);
    if(key < 0)
    {
        std::cerr << "ftok error" << std::endl;
        return 1;
    }
    std::cout << "k: " << ToHex(key) << std::endl;

    return 0;
}