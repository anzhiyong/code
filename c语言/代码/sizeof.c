#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("����%zd\n", sizeof(int));
	printf("������%zd\n", sizeof(short));
	printf("������%zd\n", sizeof(long));
	printf("��������%zd\n", sizeof(long long));
	printf("�����ȸ�����%zd\n", sizeof(float));
	printf("˫���ȸ�����%zd\n", sizeof(double));
	printf("�����ȸ�����%zd\n", sizeof(long double));
	printf("�ַ���%zd\n", sizeof(char));
	printf("������%zd\n", sizeof(_Bool));
	
}