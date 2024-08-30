#include"proc.h"
#include<stdio.h>
#include<string.h>
#include<unistd.h>


#define NUM 101
#define STYLE '$' 

void print()
{
  const char* label = "|/\\";
  int len = strlen(label);
  char bar[NUM];
  memset(bar,'\0',sizeof(bar));

  int cnt = 0;
  while(cnt <= 100)
  {
    printf("[%-100s][%d%%][%c]\r", bar, cnt, label[cnt % len]);
    fflush(stdout); 
    bar[cnt] = STYLE; 
    cnt++;

    //sleep(1);
    usleep(20000);
  }
  printf("\n");
}
