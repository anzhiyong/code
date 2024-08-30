#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//通讯录菜单
void menu() {
	printf("*****************通讯录***************\n");
	printf("*******1.添加联系人  2.删除联系人*****\n");//ctrl+d
	printf("*******3.修改联系人  4.查找联系人*****\n");//ctrl+d
	printf("*******5.查看通讯录  0.  退 出  ******\n");//ctrl+d
	printf("**************************************\n");
}
int main()
{
	int op = -1;
	//创建通讯录结构对象
	Contact con;
	ContactInit(&con);
	do {
		menu();
		printf("请选择您的操作:\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			//添加联系人
			ContactAdd(&con);
			break;
		case 2:
			//删除联系人
			ContactDel(&con);
			break;
		case 3:
			//修改联系人
			ContactModify(&con);
			break;
		case 4:
			//查找联系人
			ContactFind(&con);
			break;
		case 5:
			//查看通讯录
			ContactShow(&con);
			break;
		case 0:
			//退出通讯录
			printf("通讯录退出中...\n");
			break;
		default:
			break;
		}

	} while (op != 0);
	//销毁通讯录
	ContactDesTroy(&con);
	return 0;
}