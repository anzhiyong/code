#pragma once
#include <string>
#include <sys/ipc.h>
#include <sys/shm.h>

const std::string gpath = "/home/an/code";
const int gprojId = 0x6666;
const int gshmsize = 4096;

//将key_t转成16进制
std::string ToHex(key_t key)
{
    char buff[gshmsize];
    snprintf(buff, sizeof(buff), "0x%x", key);
    return buff;
}
