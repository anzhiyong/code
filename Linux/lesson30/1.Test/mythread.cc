#include <iostream>
#include <unistd.h>
#include <string>
#include <pthread.h>



class ThreadData
{
    ThreadData()
    {}

    void Init(const std::string &name, int a, int b)
    {
        _name = name;
        _a = b;
        _b = b;
    }

    void Execute()
    {
        _result = _a + _b;
    }

    int Result()    {return _result;}//返回结果
    std::string Name() {return _name;}
    int A() {return _a;}
    int B() {return _b;}
    void SetId(pthread_t tid) {_tid = tid;}
    pthread_t Id()  {return _tid;}//返回tid
    ~ThreadData()
    {}

private:
    std::string _name;
    int _a;
    int _b;
    int _result;
    pthread_t _tid;
};








// std::string toHex(pthread_t tid)
// {
//     char buffer[64];
//     snprintf(buffer, sizeof(tid), "0x%lx", tid);
//     return buffer;
// }

// void *routine(void *args)
// {
//     std::string name = static_cast<const char *>(args);
//     while(true)
//     {
//         std::cout << "我是新线程，我的名字是：" << name << "my tid is: " << toHex(pthread_self()) << std::endl;
//         sleep(1);
//     }
// }

// int main()
// {
//     // std::thread_t([](){

//     // });

//     pthread_t tid;
//     int n = pthread_create(&tid, nullptr, routine, (void*)"thread_1");
//     if(n!=0)
//     {
//         std::cout << "pthread_create error" << std::endl;
//         return 1;
//     }
//     //printf("new pthread_t: 0x%lx\n", toHex(tid));
//     while(true)
//     {
//         std::cout << "我是main线程。" << std::endl;
//         sleep(10);
//     }
//     return 0;
// }