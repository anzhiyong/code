#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//ͨѶ¼�˵�
void menu() {
	printf("*****************ͨѶ¼***************\n");
	printf("*******1.�����ϵ��  2.ɾ����ϵ��*****\n");//ctrl+d
	printf("*******3.�޸���ϵ��  4.������ϵ��*****\n");//ctrl+d
	printf("*******5.�鿴ͨѶ¼  0.  �� ��  ******\n");//ctrl+d
	printf("**************************************\n");
}
int main()
{
	int op = -1;
	//����ͨѶ¼�ṹ����
	Contact con;
	ContactInit(&con);
	do {
		menu();
		printf("��ѡ�����Ĳ���:\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			//�����ϵ��
			ContactAdd(&con);
			break;
		case 2:
			//ɾ����ϵ��
			ContactDel(&con);
			break;
		case 3:
			//�޸���ϵ��
			ContactModify(&con);
			break;
		case 4:
			//������ϵ��
			ContactFind(&con);
			break;
		case 5:
			//�鿴ͨѶ¼
			ContactShow(&con);
			break;
		case 0:
			//�˳�ͨѶ¼
			printf("ͨѶ¼�˳���...\n");
			break;
		default:
			break;
		}

	} while (op != 0);
	//����ͨѶ¼
	ContactDesTroy(&con);
	return 0;
}