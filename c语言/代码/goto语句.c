#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("hello,an\n");
	goto next;				//����hello,you���
	printf("hello,you\n");
next:
	printf("hello,me\n");
	return 0;
}