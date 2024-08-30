#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
f()//界面
{
	printf("*****************\n");
	printf("*1.开始游戏******\n");
	printf("*0.退出**********\n");
	printf("*****************\n");
}
void game()//猜数字功能
{
	int r = rand() % 100 + 1;//生成1~100的随机数
	int guass = 0;
	int count = 5;
	while (count)//当count为0时游戏失败
	{
		printf("你还有%d次机会！\n", count);
		printf("请猜数字：");
		scanf("%d", &guass);
		if (guass > r)
		{
			printf("猜大了\n");
		}
		else if (guass < r)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜中了\n");
			break;
		}
		count--;
	}
	printf("你失败了，正确值是%d\n", r);
	

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//随机数种子
	do
	{
		f();//
		printf("请选择");
		scanf("%d", &input);//输入数字，1为开始游戏，0退出游戏
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束");
			break;
		default:
			printf("输入错误");
			break;
		}
	} while (input);
	
	return 0;
}