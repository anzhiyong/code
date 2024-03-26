#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("整型%zd\n", sizeof(int));
	printf("短整型%zd\n", sizeof(short));
	printf("长整型%zd\n", sizeof(long));
	printf("长长整型%zd\n", sizeof(long long));
	printf("单精度浮点型%zd\n", sizeof(float));
	printf("双精度浮点型%zd\n", sizeof(double));
	printf("长精度浮点型%zd\n", sizeof(long double));
	printf("字符型%zd\n", sizeof(char));
	printf("布尔型%zd\n", sizeof(_Bool));
	
}