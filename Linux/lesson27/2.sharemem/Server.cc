#include <iostream>
#include <unistd.h>
#include "ShareMemory.hpp"


int main()
{
    shm.CreatMemory();
    shm.AttachShm();
    std::cout << "server attach done" << std::endl;
    sleep(10);

    shm.DetachShm();
    std::cout << "server detach done" << std::endl;
    sleep(10);

    shm.DeleteShm();
    std::cout << "server delete done" << std::endl;
    sleep(10);



    return 0;
}


// int main()
// {
//     //1.创建key
//     //ftok()
    
//     std::cout << "k: " << ToHex(key) << std::endl;

//     //2.创建共享内存 && 获取
//     //注意：共享内存也有权限
//     //shmget()
    
//     std::cout << "shmid: " << shmid << std::endl;


//     //3.把共享内存挂接到地址空间上
//     //shmat()
    

//     sleep(10);
//     //n.删除共享内存
//     //shmctl()
    
//     return 0;
// }