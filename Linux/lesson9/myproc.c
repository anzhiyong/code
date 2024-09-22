#include<stdio.h>
#include<unistd.h>

int gval = 0;

int main()
{
  pid_t pid = getpid(), ppid = getppid();
  printf("I am is a process, pid:%d, ppid:%d", pid, ppid);
  pid_t i = fork();

  if(i > 0)
  {
    while(1)
    {
      printf("我是父进程, pid:%d, ppid:%d, fork_i:%d, gval:%d\n", getpid(), getppid(), i, gval);
      gval+=100;
      sleep(1);
    }
  }
  else if(i == 0)
  {
    while(1)
    {
      printf("我是子进程, pid:%d, ppid:%d, fork_i:%d, gval:%d\n", getpid(), getppid(), i, gval);
      gval++;
      sleep(1);
    }
  }

  return 0;
}
