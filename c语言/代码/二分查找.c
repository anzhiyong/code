#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int bin_search(int arr[], int left, int right, int KEY)
{
	while (left < right)
	{
		if (KEY > arr[(left + right + 1) / 2])
		{
			left = (left + right + 1) / 2;
		}
		else if(KEY < arr[(left + right + 1) / 2])
		{
			right = (left + right + 1) / 2;
		}
		else
		{
			return  (left + right + 1) / 2;
		}
	}
	return -1;
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int KEY;
	scanf("%d", &KEY);//输入要查找的数字
	int z = bin_search(arr, 0, 9, KEY);
	printf("位置是%d", z);
	return 0;
}