#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

void test()
{
	int ch = 0;
	do
	{
		Snake snake = { 0 };
		GameStart(&snake);
		GameRun(&snake);
		GameEnd(&snake);//善后工作
		SetPos(20, 15);
		printf("再来一局？（y/n）");
		ch = getchar();
		getchar();
	} while (ch == 'Y' || ch == 'y');

}
int main()
{
	//适配本地中文环境
	setlocale(LC_ALL, "");

	//贪吃蛇游戏的设置
	test();
	return 0;
}