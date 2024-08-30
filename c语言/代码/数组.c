#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	//创建一维数组
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//打印一维数组
//	int i=0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//数组的输入
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);//依次打印数组元素的地址
//	}
//}

//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = 0;
//	sz = sizeof(arr) / sizeof(arr[0]);//sizeof计算数组元素个数
//	printf("%d", sz);
//}


//二维数组的输入输出
//#include<stdio.h>
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j;
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		int j;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//}


#include<stdio.h>
int main()
{
	int arr[3][5] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j;
		for (j = 0; j < 5; j++)
		{
			printf("&arr[%d][%d]=%p\n", i, j, &arr[i][j]);//以打印出数组所有元素的地址
			
		}
	}
}