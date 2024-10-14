#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<unistd.h>

using namespace std;

#define basesize 1024
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
  snprintf(command_line, basesize, "[%s@%s %s]# ", \
      GetUsreName().c_str(), GetUsreName().c_str(), GetPwd().c_str());
  return command_line;
}
void PrintCommandLine()
{
  printf("%s", MakeCommandLine().c_str());
  fflush(stdout);
}

int main()
{
  while(true)
  {
    PrintCommandLine();//1.打印命令行提示符
    printf("\n");
    sleep(1);
//    GetCommandLine(); //2.获取用户命令
//    
//    ParseCommandLine(); //3.解析命令
//
//    ExecuteCommand();  //4.执行命令
  }
    return 0;
}
