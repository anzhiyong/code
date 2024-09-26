#include<stdio.h>

#define MAXLEN 100
typedef int DataType;
typedef struct 
{
  DataType data[MAXLEN];
  int top;
}SeqStack;

void InitStack(SeqStack *s)
{
  s->top = -1;
}

//判断是否为空
int EmptyStack(SeqStack *s)
{
  if(s->top == -1)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

//判断栈是否为满
int FullStack(SeqStack *s)
{
  if(s->top == MAXLEN-1)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

//进栈
int Push(SeqStack *s, DataType x)
{
  if(FullStack(s))
  {
   printf("栈满，不能进栈!");
   return 0;
  }
  else 
  {
    s->top++;
    s->data[s->top] = x;
    return 1;
  }
}

//出栈
int Pop(SeqStack *s, DataType *x)
{
  if(EmptyStack(s))
  {
    printf("栈为空，不能出栈！");
    return 0;
  }
  else 
  {
    *x = s->data[s->top];
    s->top--;
    return 1;
  }
}

//取栈顶元素
int GetTop(SeqStack *s, DataType *x)
{
  if(EmptyStack(s))
  {
    printf("栈空，取栈顶元素失败！");
    return 0;
  }
  else 
  {
    *x = s->data[s->top];
    return 1;
  }
}

void Menu()
{
  printf("-----------------顺序栈的各种操作----------------\n");
  printf("-------------------------------------------------\n");
  printf("-------------------------------------------------\n");
  printf("|              1.初始化栈                       |\n");
  printf("|              2.入栈操作                       |\n");
  printf("|              3.出栈操作                       |\n");
  printf("|              4.求栈顶元素                     |\n");
  printf("|              0.返回                           |\n");
  printf("-------------------------------------------------\n");
  printf("-------------------------------------------------\n");
  printf("请输入菜单数（0-4）：");
}

int main()
{
  int i, n, flag;
  SeqStack s;
  DataType x;
  char ch1, ch2, a;
  ch1 = 'y';
  while(ch1 == 'y'||ch1 =='Y')
  {
    Menu();
    scanf("%c", &ch2);
    getchar();
    switch(ch2)
    {
      case '1':
        InitStack(&s);
        printf("栈的初始化完成！");
        break;
      case '2':
        printf("请输入要入栈的元素个数：");
        scanf("%d", &n);
        printf("请输入%d个入栈的整数：", n);
        for(i = 0; i<n; i++)
        {
          scanf("%d", &x);
          flag = Push(&s, x);

        }
        if(flag == 1)
        {
          printf("入栈成功！");
        }
        break;
      case '3':
        printf("请输入要出栈的元素个数：");
        scanf("%d", &n);
        printf("出栈的元素为：");
        for(i = 0; i<n; i++)
        {
          flag = Pop(&s, &x);
          printf("%5d", x);
        }
        if(flag == 1)
        {
          printf("出栈成功!");
        }
        else 
        {
          printf("出栈失败!");
        }
        break;
      case '4':
        if(flag = GetTop(&s, &x))
        {
          printf("当前栈顶元素为:%d", x);
        }
        break;
      case '0':
        ch1 = 'n';
        break;
      default:
        printf("输入有误，请输入0-4选择");
    }
    if(ch2 != '0')
    {
      printf("\n请按回车键继续，按任意键返回主菜单！\n");
      a = getchar();
      if(a != '\xA')
      {
        getchar();
        ch1 = 'n';
      }
    }
  }

  return 0;
}
