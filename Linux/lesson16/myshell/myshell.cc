#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

#define basesize 1024

const int argv = 64;
char *gargv[argv];

int gargc = 0;
string GetUsreName()
{
  string username = getenv("USER");
  return username;
}

string GetHostName()
{
  return getenv("HOSTHOME");
}

string GetPwd()
{
  return getenv("PWD");
}

string MakeCommandLine()
{
  //[an@VM-24-14-centos myshell]$
  char command_line[basesize];
  snprintf(command_line, basesize, "[%s@%s %s]# ",
           GetUsreName().c_str(), GetUsreName().c_str(), GetPwd().c_str());
  return command_line;
}

// 1.打印命令行提示符
void PrintCommandLine()
{
  printf("%s", MakeCommandLine().c_str());
  fflush(stdout);
}

bool GetCommandLine(char command_buffer[], int size) // 2.获取用户命令
{
  char *result = fgets(command_buffer, size, stdin);
  if (!result)
  {
    return false;
  }
  command_buffer[strlen(command_buffer) - 1] = '\0';
  return true;
}

void ParseCommandLine(char command_buffer[], int len) //3.解析命令
{
  gargc = 0;
  const char *sep = " ";
  gargv[gargc++] = strtok(command_buffer, sep);

  while(gargv[gargc++] = strtok(nullptr, sep));
  gargc--;
}

bool ExecuteCommand()  //4.执行命令
{
  //子进程执行
  pid_t id = fork();
  if(id < 0)
    return false;
  if(id == 0)
  {
    //
    execvp(gargv[0], gargv);

    exit(1);
  }
  int state = 0;
  pid_t rid = waitpid(id, &state, 0);
  if(rid < 0)
    return false;
  return true;
}

void deBug()
{
  printf("gargc:%d\n", gargc);
  for(int i = 0; gargv[i]; i++)
  {
    printf("argv[%d]:%s\n", gargc, gargv[i]);
  }
}

int main()
{
  char command_buffer[basesize];
  while (true)
  {
    PrintCommandLine(); // 1.打印命令行提示符
    // printf("\n");
    sleep(1);
    if (!GetCommandLine(command_buffer, basesize)) // 2.获取用户命令
    {
      continue;
    }
    // printf("%s\n", command_buffer);

    ParseCommandLine(command_buffer, strlen(command_buffer)); // 3.解析命令
    //deBug();
    ExecuteCommand();  //4.执行命令
  }
  return 0;
}
