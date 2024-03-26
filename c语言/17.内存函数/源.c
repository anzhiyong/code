#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<string.h>
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	memcpy(arr2, arr1, 5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//  return 0;
//}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	//将arr1中的4 5 6 7 8，拷贝到arr2中
	memcpy(arr2, arr1+3, 5 * sizeof(int));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}

	return 0;
}