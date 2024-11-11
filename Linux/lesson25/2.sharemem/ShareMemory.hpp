#pragma once
#include <iostream>
#include <string>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

const std::string gpath = "/home/an/code";
const int gprojId = 0x6666;
//
const int gshmsize = 4096;
mode_t gmode = 0600;

std::string ToHex(key_t key)
{
    char buff[gshmsize];
    snprintf(buff, sizeof(buff), "0x%x", key);
    return buff;
}

class ShareMemory
{
private:
    void CreatMemoryHelper(int shmflg)
    {
        // 1.创建key
        // ftok()
         _key = ::ftok(gpath.c_str(), gprojId);
        if (_key < 0)
        {
            std::cerr << "ftok error" << std::endl;
            return;
        }

        // 2.
        _shmid = ::shmget(_key, gshmsize, shmflg);
        if (_shmid < 0)
        {
            std::cerr << "shm get error." << std::endl;
            return;
        }
    }

public:
    ShareMemory()
        : _shmid(-1)
        ,_key(0)
        ,_addr(nullptr)
    {
    }

    ~ShareMemory()
    {
    }

    void CreatMemory()
    {
        CreatMemoryHelper(IPC_CREAT | IPC_EXCL | gmode);
    }

    void GetShm()
    {
        CreatMemoryHelper(IPC_CREAT);
    }

    void AttachShm()
    {
        _addr = shmat(_shmid, nullptr, 0); // 为什么会失败？？？
        if ((long long)_addr == -1)
        {
            std::cout << "attach error" << std::endl;
            return;
        }
        return;
    }

    void DetachShm()
    {
        if (_addr != nullptr)
            ::shmdt(_addr);
        std::cout << "detach done: " << std::endl;
    }

    void DeleteShm()
    {
        shmctl(_shmid, IPC_RMID, nullptr);
    }

    void *GetAddr()
    {
        return _addr;
    }

    void ShmMeta()
    {
    }

private:
    int _shmid;
    key_t _key;
    void *_addr;
    
};

//临时
ShareMemory shm;