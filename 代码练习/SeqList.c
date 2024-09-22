#include<stdio.h>
#include<malloc.h>
typedef int DataType;
typedef struct linknode
{
  DataType data;
  struct linknode* next;
}LinkList;

//初始化
LinkList* InitList()
{
  LinkList* head = (LinkList*)malloc(sizeof(LinkList));
  head->next = NULL;
  return head;
}

//尾插建立链表
void CreatList(LinkList* head, int n)
{
  LinkList* s, *last;
  last = head;
  int i;
  printf("请输入%d个整数：", n);
  for(i = 0; i < n; i++)
  {
    s = (LinkList*)malloc(sizeof(LinkList));
    scanf("%d", &s->data);
    s->next = NULL;
    last->next = s;
    last = s;
  }
  printf("链表建立成功!\n");
}

//求表长
int LengthList(LinkList* head)
{
  LinkList* p = head->next;
  int i = 0;
  while(p != NULL)
  {
    i++;
    p = p->next;
  }
  return i;
}

//查找值为x的元素位置
void Locate(LinkList* head, DataType x)
{
  int i = 0;
  LinkList* p = head->next;
  while(p != NULL && p->data != x)
  {
    i++;
    p = p->next;
  }
  if(p != NULL)
  {
    printf("在第%d个位置找到值为%d的节点!", i, x);
  }
  else
  {
    printf("未找到值为%d的节点!", x);
  }
}

//按位置查找元素
void SearchList(LinkList* head, int i)
{
  int j = 0;
  LinkList* p = head->next;
  if(i > LengthList(head))
    printf("位置错误，表中没有此数据!");
  while(p->next != NULL && j < i)
  {
    p = p->next;
    j++;
  }
  if(j == i)
    printf("在第%d的位置上的元素值为%d!", i, p->data);
}

//按位置插入元素
void InsertList(LinkList* head, int i, DataType x)
{
  LinkList* p = head->next, *s;
  int j = 0;
  while(p->next != NULL && j < i-1)
  {
    p = p->next;
    j++;
  }
  if(p != NULL)
  {
    s = (LinkList*)malloc(sizeof(LinkList));
    s->data = x;
    s->next = NULL;
    p->next = s;

    printf("插入元素成功！");
  }
  else
  {
    printf("插入元素失败！");
  }
}

//按位置删除表中元素
void DelLIst(LinkList* head, int i)
{
  int j =0;
  DataType x;
  LinkList *p = head, *s;
  while(p->next != NULL && j<i-1)
  {
    p = p->next;
    j++;
  }
  if(p->next != NULL && j == i-1)
  {
    s = p->next;
    x = s->data;
    p->next = s->next;
    free(s);
    printf("删除第%d位上的元素%d成功！", i, x);
  }
  else
  {
    printf("删除节点错误");
  }
}

//显示链表中的数据
void DispList(LinkList* head)
{
  LinkList* p = head->next;
  while(p != NULL)
  {
    printf("%5d", p->data);
    p = p->next;
  }
}

void MenuLine()
{
  printf("\n线性表子系统");
  printf("\n==========================================================");
  printf("\n|                  1.建立                                 ");
  printf("\n|                  2.插入                                 ");
  printf("\n|                  3.删除                                 ");
  printf("\n|                  4.按位置查找                           ");
  printf("\n|                  5.按元素查找                           ");
  printf("\n|                  6.求表长                               ");
  printf("\n|                  0.返回                                 ");
  printf("\n==========================================================");
  printf("\n请输入菜单号（0-6）");
}

int main()
{
  LinkList* head;
  DataType x;
  int i, n;
  char ch1, ch2, a;
  ch1 = 'y';
  while(ch1 == 'y' || ch1 == 'Y')
  {
    MenuLine();
    scanf("%c", &ch2);
    getchar();
    switch(ch2)
    {
      case '1':
        head = InitList();
        printf("请输入要建立的线性表的长度：");
        scanf("%d", &n);
        CreatList(head, n);
        printf("建立后的线性表为：\n");
        DispList(head);
        break;
      case '2':
        printf("请输入要插入的元素的位置：");
        scanf("%d", &i);
        getchar();
        printf("请输入要插入的元素值：");
        scanf("%d",&x);
        InsertList(head, i, x);
        printf("插入元素%d后的链表为：\n", x);
        DispList(head);
        break;
      case '3':
        printf("请输入要删除的元素的位置：");
        scanf("%d", &i);
        DelLIst(head, i);
        printf("删除第%d位的元素后的链表为：\n",i);
        DispList(head);
        break;
      case '4':
        printf("请输入查找的元素位置(大于等于1的整数)：");
        scanf("%d", &i);
        SearchList(head, i);
        break;
      case '5':
        printf("请输入查找的整数：");
        scanf("%d", &x);
        Locate(head, x);
        break;
      case '6':
        printf("该链表的长度为%d", LengthList(head));
        break;
      case '0':
        ch1 = 'n';
        break;
      default:
        printf("输入有误,请输入0-9进行选择！");
    }
    if(ch2 != '0')
    {
      printf("\n按回车键继续，按任意键返回主菜单！\n");
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
