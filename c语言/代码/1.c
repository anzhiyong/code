#include<stdio.h>
//int is_prime(int n)
//{
//	if (n == 1 || n < 1)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (is_prime(a))
//	{
//		printf("%d������",a);
//	}
//	else
//	{
//		printf("%d��������", a);
//	}
//	return 0;
//}


#include<stdio.h>
void displayMenu()
{
	printf("��ӭ���������\n");
	printf("***********************************\n");
	printf("*                1.�ӷ�            *\n");
	printf("*                2.����            *\n");
	printf("*                3.�˷�            *\n");
	printf("*                4.����            *\n");
	printf("*                5.����            *\n");
	printf("*                6.�׳�            *\n");
	printf("*                7.�ۼ�            *\n");
	printf("*                8.����            *\n");

}
int main()
{
	int n;
	char input;
	do
	{
		printf("�Ƿ���������,y/n(�ǻ��)��\n");
		scanf("%c", &input);
		if (input == 'y')
		{
			displayMenu();
			scanf("%d",&n);
			switch(n)
			{
				case 8:exit(0);
			} 
		}
		else if (input == 'n')
		{
			break;
		}
		else
		{
			printf("�����д�������������\n");
		}
	} while (input != 'y' && input != 'n');
	return 0;
}



