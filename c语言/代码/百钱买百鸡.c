#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int g, m, x, sum, money;//分别定义公鸡，母鸡，小鸡，总共几只，花的钱
	for (g = 0; g <= 20; g++)//公鸡最多20只
	{
		for (m = 0; m <= 33; m++)//母鸡最多33只
		{
			for (x = 0; x <= 100 - g - m; x++)//小鸡
			{
				money = g * 5 + m * 3 + x / 3;
				sum = g + m + x;
				if (money == 100 && sum == 100)//一百元买一百只鸡
					printf("公鸡：%d母鸡：%d小鸡：%d\n",g, m, x);
			}
		}
	}
	return 0;
}