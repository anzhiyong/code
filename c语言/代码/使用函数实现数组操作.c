#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void init(int* a,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		a[i] = 0;
	}
}
void print(int* a, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
}
void reverse(int* a, int sz)
{
	int i = 0;
	for (i = sz-1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	int arr[] = { 0,1,2,3,4,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	init(arr, sz);
	print(arr, sz);
	reverse(arr, sz);
	
}