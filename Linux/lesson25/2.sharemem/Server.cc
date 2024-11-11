#include <iostream>
#include <unistd.h>
#include <string>
#include <memory.h>

#include "ShareMemory.hpp"

int main()
{
    std::string s;
    shm.CreatMemory();
    shm.AttachShm();

    // 检查共享内存是否成功附加
    if (shm.GetAddr() == nullptr)
    {
        perror("shmat");
        return 1;
    }

    // 获取共享内存地址
    char *shm_addr = (char *)shm.GetAddr(); // 假设共享内存是字符数组类型

    std::cout << "共享内存已附加，输入内容以写入共享内存，输入'exit'退出：" << std::endl;

    while (true)
    {
        // 获取用户输入
        std::getline(std::cin, s);

        // 判断是否退出
        if (s == "exit")
        {
            break;
        }

        // 将用户输入的内容写入共享内存
        memset(shm_addr, 0, 1024);          // 清空共享内存内容
        strncpy(shm_addr, s.c_str(), 1023); // 写入输入数据到共享内存

        std::cout << "已写入共享内存: " << s << std::endl;
    }

    shm.DetachShm();
    shm.DeleteShm();
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