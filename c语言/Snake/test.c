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
		GameEnd(&snake);//�ƺ���
		SetPos(20, 15);
		printf("����һ�֣���y/n��");
		ch = getchar();
		getchar();
	} while (ch == 'Y' || ch == 'y');

}
int main()
{
	//���䱾�����Ļ���
	setlocale(LC_ALL, "");

	//̰������Ϸ������
	test();
	return 0;
}