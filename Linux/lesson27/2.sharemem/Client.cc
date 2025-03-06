#include <iostream>
#include "ShareMemory.hpp"

int main()
{
    shm.GetShm();
    shm.AttachShm();
    //在这里进行IPC
    
   



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