#include <iostream>
#include <unistd.h>
#include "Comm.hpp"

int main()
{
    //1.创建key
    key_t key = ::ftok(gpath.c_str(), gprojId);
    if(key < 0)
    {
        std::cerr << "ftok error" << std::endl;
        return 1;
    }
    std::cout << "k: " << ToHex(key) << std::endl;

    //2.创建共享内存 && 获取
    int shmid = ::shmget(key, gshmsize, IPC_CREAT | IPC_EXCL);
    if(shmid < 0)
    {
        std::cerr << "shm get error." << std::endl;
        return 2;
    }
    std::cout << "shmid: " << shmid << std::endl;

    sleep(10);
    //3.删除共享内存
    shmctl(shmid, IPC_RMID, nullptr);
    return 0;
}