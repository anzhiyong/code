#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[10];
	int i, j, temp;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	//Ã°ÅÝÅÅÐò
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%5d", a[i]);
	}

}