#include <iostream>
#include <string>
#include <memory.h>
#include "ShareMemory.hpp"

int main()
{
   
    shm.GetShm();
    shm.AttachShm();

   // 获取共享内存的地址
    char *shm_addr = (char *)shm.GetAddr();  // 假设共享内存是字符数组类型
    
    std::cout << "从共享内存读取数据：" << std::endl;
    
    while (true)
    {
        // 读取共享内存中的数据
        std::string shared_data(shm_addr);  // 从共享内存读取字符串
        std::cout << "共享内存中的内容: " << shared_data << std::endl;
        
        // 判断是否需要退出
        if (shared_data == "exit") {
            break;
        }
        sleep(10);
    }

    shm.DetachShm();
    shm.DeleteShm();
    return 0;
}

// int main()
// {
//     key_t key = ftok(gpath.c_str(), gprojId);
//     if(key < 0)
//     {
//         std::cerr << "ftok error" << std::endl;
//         return 1;
//     }
//     std::cout << "k: " << ToHex(key) << std::endl;

//     return 0;
// }