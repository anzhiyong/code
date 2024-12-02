#include <iostream>
#include <pthread.h>
#include <unistd.h>


void *run(void *args)
{
    while(true)
    {
        std::cout << "new thread, pid: " << getpid() << std::endl;
        sleep(1);
    }
    return nullptr;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, run, (void*)"thread-1");
    printf("tid:0x%lx\n", tid);
    std::cout << "main pid :" << getpid() << std::endl;
    while(true)
    {
        std::cout << "我是新线程" << std::endl;
        sleep(1);
    }
    return 0;
}