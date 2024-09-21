#include<stdio.h>
#include<unistd.h>

int main()
{
  pid_t id = getpid();

  while(1)
  {
    printf("I am is a process, %d", id);
  }
  return 0;
}
