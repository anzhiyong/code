#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int g, m, x, sum, money;//�ֱ��幫����ĸ����С�����ܹ���ֻ������Ǯ
	for (g = 0; g <= 20; g++)//�������20ֻ
	{
		for (m = 0; m <= 33; m++)//ĸ�����33ֻ
		{
			for (x = 0; x <= 100 - g - m; x++)//С��
			{
				money = g * 5 + m * 3 + x / 3;
				sum = g + m + x;
				if (money == 100 && sum == 100)//һ��Ԫ��һ��ֻ��
					printf("������%dĸ����%dС����%d\n",g, m, x);
			}
		}
	}
	return 0;
}