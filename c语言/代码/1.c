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
//		printf("%d是素数",a);
//	}
//	else
//	{
//		printf("%d不是素数", a);
//	}
//	return 0;
//}


#include<stdio.h>
void displayMenu()
{
	printf("欢迎进入计算器\n");
	printf("***********************************\n");
	printf("*                1.加法            *\n");
	printf("*                2.减法            *\n");
	printf("*                3.乘法            *\n");
	printf("*                4.除法            *\n");
	printf("*                5.求余            *\n");
	printf("*                6.阶乘            *\n");
	printf("*                7.累加            *\n");
	printf("*                8.结束            *\n");

}
int main()
{
	int n;
	char input;
	do
	{
		printf("是否进入计算器,y/n(是或否)：\n");
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
			printf("输入有错误请重新输入\n");
		}
	} while (input != 'y' && input != 'n');
	return 0;
}



