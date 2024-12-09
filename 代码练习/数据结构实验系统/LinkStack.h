#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100
typedef int DataType; 
typedef struct stacknode
{
DataType data;
struct stacknode *next;
} LinkStack;

LinkStack* InitStack()
{
  LinkStack * S;
  S=NULL;
  return S;
}

int EmptyStack ( LinkStack * S )
{
  if (S ==NULL)
    return 1;
  else
    return 0;
}

LinkStack* Push ( LinkStack * S, DataType x )
{
  LinkStack * p;
  p= ( LinkStack * ) malloc(sizeof(LinkStack));
  p->data=x;
  p->next=S;
  S=p;
  return S;
}
LinkStack * Pop ( LinkStack * S, DataType * x )
{
  LinkStack * p;
  if ( EmptyStack(S))
  {
    printf ( "\t栈空,不能出栈!" );
    return NULL;
  }
  else
  {
    *x=S->data;
    p=S;
    S=S->next;
    free ( p );
    return S;
  }
}

int GetTop ( LinkStack * S, DataType * x )
{
  if ( EmptyStack ( S ))
  {
    printf ( "栈空!");
    return 0;
  }
  else 
  {
    *x=S->data;
    return 1;
  }
}

void ShowStack ( LinkStack * S )
{
  LinkStack * p=S;
  if ( p == NULL )
    printf ( "\t栈空!" ) ;
  else 
  {
    printf ( " 从栈顶元素起栈中各元素为:" ) ;
    while ( p != NULL )
    {
      printf ( "% d ", p->data ) ;
      p=p->next;
    }
  }
}

void D_B ( LinkStack * S, DataType x )
{
  while ( x )
  {
    S=Push ( S, x% 2 );
    x/=2;
  }
  printf ( " 转换后的二进制为:" ) ;
  while ( ! EmptyStack ( S ) )
  {
    S=Pop ( S, &x );
    printf ( "% d", x ) ;
  }
}

void trans ( char * exp, char *postexp)
{
  struct 
  {
    char data [MAXSIZE];
    int top;
  } op;
  int i=0;
  op.top=-1;
  while ( *exp != '#' )
  {
    switch ( *exp )
    {
      case '(' :
        op.top++; op.data [op.top] = *exp;
        exp++;
        break;
      case ')':
        while ( op.data [op.top] != '(')
        {
          postexp [i++] =op.data [op.top];
          op.top--;
        }
        op.top--;
        exp++;
        break;
      case '+':
      case '-' :
        while(op.top != -1&&op.data [op.top] !='(')
        {
          postexp [i++] =op.data [op.top];
          op.top--;
        }
        op.top++;
        op.data [op.top] = *exp;
        exp++;
        break;
      case '*':
      case '/':
        while ( op.data [op.top] == '*'||op.data [op.top] == '/')
        {
          postexp [i++] = op.data [op.top];
          op.top--;
        }
        op.top++;
        op.data [op.top] = *exp;
        exp++;
        break;
      case ' ' : break;
      default:
        while (*exp>='0' && *exp<='9' )
        {
          postexp [i++] =* exp;
          exp++;
        }
        postexp [i++] ='#' ;
    }
  }
  while ( op.top !=-1 )
  {
    postexp [i++] = op.data [op.top];
    op.top--;
  }
  postexp [i] = '\0';
}

float compvalue ( char * postexp )
{
  struct 
  {
    float data [MAXSIZE];
    int top;
  } st;
  float a, b, c, d;
  st.top=-1;
  while ( *postexp != '\0' )
  {
    switch (*postexp)
    {
      case '+':
        a = st.data [st.top];
        st.top--;
        b = st.data [st.top];
        st.top--;
        c=b+a;
        st.top++;
        st.data[st.top] = c;
        break;
      case '-':
        a=st.data [st.top];
        st.top--;
        b=st.data [st.top];
        st.top--;
        c=b-a;
        st.top++;
        st.data [st.top] =c;
        break;
      case '*':
        a=st.data [st.top];
        st.top--;
        b=st.data [st.top];
        st.top--;
        c=b* a;
        st.top++;
        st.data[st.top]=c;
        break;
      case '/':
        a=st.data [st.top];
        st.top--;
        b=st. data [st.top];
        st.top--;
        if(a !=0)
        {
          c=b/a;
          st.top++;
          st.data [st.top] =c;
        }
        else 
          printf ( " \n \t 除零错误! \n" ) ;
        break;
      default:
        d=0;
        while ( *postexp>='0' && *postexp<='9')
        {
          d=10* d+* postexp- '0' ;
          postexp++;
        }
        st.top++;
        st.data[st.top] = d;
        break;
    }
    postexp++;
  }
  return st.data[st.top];
}

void MenuStack()
{   
    /* 显示菜单子函数 */
    printf("\n 栈子系统");
    printf("\n ========================================");
    printf("\n |  1———初始化栈                    | ");
    printf("\n |  2———入栈操作                    | ");
    printf("\n |  3———出栈操作                    | ");
    printf("\n |  4———求栈顶元素                  | ");
    printf("\n |  5———显示栈中元素                | ");
    printf("\n |  6———十、二进制数转换            | ");
    printf("\n |  7———表达式转换并求值            | ");
    printf("\n |  0———返回                        | ");
    printf("\n ========================================");
    printf("\n 请输入菜单号(0-7):");
}

int linkstack()
{
    int i, n, flag;
    LinkStack *S;
    DataType x;
    char ch1, ch2, a;
    char exp[MAXSIZE], postexp[MAXSIZE]; /* 求表达式值的两个数组 */
    ch1 = 'y';
    
    while (ch1 == 'y' || ch1 == 'Y')
    {
        MenuStack();
        scanf("%c", &ch2);
        getchar();

        switch (ch2)
        {
        case '1':
            S = InitStack();
            printf(" 栈的初始化完成!");
            break;

        case '2':
            printf(" 请输入要入栈的元素个数:");
            scanf("%d", &n);
            printf(" 请输入%d个整数进行入栈:", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &x);
                S = Push(S, x);
            }
            printf(" 入栈成功!");
            break;

        case '3':
            printf(" 请输入要出栈的元素个数:");
            scanf("%d", &n);
            printf(" 出栈的元素为:");
            for (i = 0; i < n; i++)
            {
                S = Pop(S, &x);
                if (S != NULL)
                    printf("%5d", x);
            }
            break;

        case '4':
            if (flag = GetTop(S, &x))
                printf(" 当前的栈顶元素值为:%d", x);
            break;

        case '5':
            ShowStack(S);
            break;

        case '6':
            S = InitStack();
            printf(" 请输入十进制正整数:");
            scanf("%d", &x); /* 输入十进制正整数 */
            D_B(S, x);        /* 调用进制转换函数 */
            break;

        case '7':
            printf(" 请输入算术表达式(只有+、-、* 、/四种运算符)，以'#'结束:");
            scanf("%s", exp);
            trans(exp, postexp);
            printf(" 该表达式的中缀表达式为:%s\n", exp);
            printf(" 转换之后的后缀表达式为(每个操作数用“#”分隔):%s\n", postexp);
            printf(" 表达式的值为:%2f\n", compvalue(postexp));
            break;

        case '0':
            ch1 = 'n';
            break;

        default:
            printf(" 输入有误，请输入0~7进行选择!");
        }

        if (ch2 != '0')
        {
            printf("\n 按回车键继续，按任意键返回主菜单!\n");
            a = getchar();
            if (a != '\n')
            {
                getchar();
                ch1 = 'n';
            }
        }
    }
    return 0;
}

