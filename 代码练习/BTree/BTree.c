#include <stdio.h>
#include <malloc.h>
#define MAX 100

int count = 0;
typedef struct tnode
{
	char data;
	struct tnode *lchild, *rchild;
}BT;

BT *CreatBtree()
{
	BT *t;
	char ch;
	//输入要建立的值
	scanf("%c", &ch);
	getchar();
	//如果ch为零,空树
	if(ch == '0')
	{
		t = NULL;	
	}
	else
	{
		t = (BT*)malloc(sizeof(BT));
		t->data = ch;
		printf("请输入左孩子：");
		t->lchild = CreatBtree();
		printf("请输入右孩子：");
		t->rchild = CreatBtree();
	} 
	 return t;
}

void ShowBTree(BT *t)
{
	if(t!=NULL)
	{
		printf("%c", t->data);
		if(t->lchild!=NULL)
		{
			printf("(");
			ShowBTree(t->lchild);
			if(t->rchild!=NULL)
			{
				printf(",");
				ShowBTree(t->rchild);
			}
			printf(")");
		}
		else if(t->rchild!=NULL)
		{
			printf("(");
			ShowBTree(t->lchild);
			if(t->rchild!=NULL)
			{
				printf(",");
				ShowBTree(t->rchild);
			}
			printf(")");
		}
	}
}
//先序遍历
void PreOrder(BT *t)
{
	if(t == NULL)
		return;
	else
	{
		printf("%d ", t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

//中序遍历
void InOrder(BT *t)
{
	if(t == NULL)
		return;
	else
	{
		InOrder(t->lchild);
		printf("%d ", t->data);
		InOrder(t->rchild);
	}
} 

//后序遍历
void BehandOrder(BT *t)
{
	if(t == NULL)
		return;
	else
	{
		BehandOrder(t->lchild);
		BehandOrder(t->rchild);
		printf("%d ", t->data);
	}
} 

void LevelOrder(BT *t)
{
	int f, r;
	BT *p, *q[MAX];
	p = t;
	if(p!=NULL)
	{
		f=1;
		q[f]=p;
		r =2;
	}
		while(f!=r)
		{
			p=q[f];
			printf("%c",p->data);
			if(p->lchild!=NULL)
			{
				q[r]=p->lchild;
				r = (r+1)%MAX;
			}
			if(p->rchild!=NULL)
			{
				q[r]=p->rchild;
				r = (r+1)%MAX;
			}
			f = (f+1)%MAX;
		}
}
//求叶子节点的个数 
void Leafnum(BT *t)
{
	if(t)
	{
		if(t->lchild==NULL && t->rchild == NULL)
			count++;
		Leafnum(t->lchild);
		Leafnum(t->rchild);
	}
 } 
 
//求总结点个数
void  Nodenum(BT *t)
{
	if(t)
	{
		count++;
		Nodenum(t->lchild);
		Nodenum(t->rchild);
	}
}

int TreeDepth(BT *t)
{
	//
	int ldep = 0, rdep = 0;
	if(t == NULL)
		return 0;
	else
	{
		ldep = TreeDepth(t->lchild);
		rdep = TreeDepth(t->rchild);
		if(ldep > rdep)
			return ldep + 1;
		else
			return rdep + 1;
	}
}

void MenuTree()
{
	printf("\n            二叉树子系统                   ");
	printf("\n===========================================");
	printf("\n           1.建立一个新二叉树              ");
	printf("\n           2.广义表表示法显示              ");
	printf("\n           3.先序遍历                      ");
	printf("\n           4.中序遍历                      ");
	printf("\n           5.后序遍历                      ");
	printf("\n           6.层次遍历                      ");
	printf("\n           7.求叶子结点个数                ");
	printf("\n           8.求二叉树总结点个数            ");
	printf("\n           9.求树深度                      ");
	printf("\n           0.返回                          ");
	printf("\n===========================================");
	printf("\n请输入菜单号（0-9）                        ");
}

int main()
{
	BT *t = NULL;
	char ch1, ch2, a;
	ch1 = 'y';
	while(ch1 == 'Y'||ch1=='y')
	{
		MenuTree();
		scanf("%c", &ch2);
		getchar();
		switch(ch2)
		{
			case '1':
				printf("请先按先序遍历输入二叉树的结点：\n");
				printf("说明：输入结点后按回车键：\n");
				printf("请输入根节点：");
				t = CreatBtree();
				printf("二叉树成功建立！");
				break;
			case '2':
				printf("二叉树广义表如下:");
				ShowBTree(t);
				break;
			case '3':
				printf("二叉树先序遍历如下:");
				PreOrder(t); 
				break;
			case '4':
				printf("二叉树中序遍历如下:");
				InOrder(t);
				break;
			case '5':
				printf("二叉树后序遍历如下:");
				BehandOrder(t);
				break;
			case '6':
				printf("二叉树的层序遍历如下:");
				LevelOrder(t);
				break; 
			case '7':
				count = 0;
				Leafnum(t);
				printf("该二叉树有%d个叶子。", count);
				break;
			case '8':
				count = 0;
				Nodenum(t);
				printf("该二叉树有%d个结点。", count);
				break;
			case '9':
				printf("该二叉树的深度是%d", TreeDepth(t));
				break;
			case '0':
				ch1 = 'n';
				break;
			default:
				printf("输入有误，请输入0-9");	 
		}
		if(ch2!='0')
		{
			printf("\n回车继续,按任意键返回主菜单!\n");
			a=getchar();
			if(a!='\xA')
			{
				getchar();
				ch1 = 'n';
			}
		}
	}
	return 0;
}






