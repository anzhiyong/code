//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int is_prime(int n)//判断素数
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
//	int i = 0;
//	scanf("%d", &i);
//	if (is_prime(i))
//	{
//		printf("%d是素数\n", i);
//	}
//	else
//	{
//		printf("%d不是素数\n", i);
//	}
//	
//}

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%d*%d=%d\t", i, j, i * j);
		printf("\n");
	}
	system("pause");
	return 0;
}