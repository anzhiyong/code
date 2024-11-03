#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <functional>
#include "task.h"

typedef std::function<void()> task_t;

void LoadTask(std::vector<task_t> &tasks)
{
    tasks.push_back(PrintLog);
    tasks.push_back(Download);
    tasks.push_back(Backup);
}

int main()
{
    std::vector<task_t> tasks;
    LoadTask(tasks);

    pid_t id = fork();
    if(id == 0)
    {
        // child
        while(true)
        {
            printf("我是子进程, pid : %d\n", getpid());
            sleep(1);
        }
        exit(0);
    }

    // father
    while(true)
    {
        sleep(1);
        pid_t rid = waitpid(id, nullptr, WNOHANG);
        if(rid > 0)
        {
            printf("等待子进程%d 成功\n", rid);
            break;
        }
        else if(rid < 0)
        {
            printf("等待子进程失败\n");
            break;
        }
        else
        {
            printf("子进程尚未退出\n");

            // 做自己的事情
            for(auto &task : tasks)
            {
                task();
            }
        }
    }

}



































//enum{
//    OK = 0,
//    OPEN_FILE_ERROR,
//};
//
//const std::string gsep = " ";
//std::vector<int> data;
//
//int SaveBegin()
//{
//    std::string name = std::to_string(time(nullptr));
//    name += ".backup";
//    FILE *fp = fopen(name.c_str(), "w");
//    if(fp == nullptr) return OPEN_FILE_ERROR;
//
//    std::string dataStr;
//    for (auto d : data)
//    {
//        dataStr += std::to_string(d);
//        dataStr += gsep;
//    }
//    fputs(dataStr.c_str(), fp);
//    fclose(fp);
//    return OK;
//}
//
//void Save()
//{
//    pid_t id = fork();
//    if(id == 0) // 子进程
//    {
//        int code = SaveBegin();
//        exit(code);
//    }
//    int status = 0;
//    pid_t rid = waitpid(id, &status, 0);
//    if(rid > 0)
//    {
//        int code = WEXITSTATUS(status);
//        if(code == 0) printf("备份成功, exit code : %d\n", code);
//        else printf("备份失败, exit code : %d\n", code);
//    }
//    else
//    {
//        perror("waitpid");
//    }
//}
//
//int main()
//{
//    int cnt = 1;
//    while(true)
//    {
//        data.push_back(cnt++);
//        sleep(1);
//
//        if(cnt % 10 == 0)
//        {
//            Save();
//        }
//    }
//}
