#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"
#define KEY_PRESS(vk)  (GetAsyncKeyState(vk)&0x1 ?1:0)

int main()
{
	char* sol= setlocale(LC_ALL, "");
	wchar_t ch1= L'安';
	printf("%c%c\n", 'a','b');
	//printf("%s\n", sol);
	wprintf(L"%lc\n", ch1);
	
	return 0;
}
//int main()
//{
//	CONSOLE_CURSOR_INFO Cursor_Info = {0};
//	system("mode con cols=100 lines=50");
//	system("title 贪吃蛇");
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	/*COORD pos = { 10,5 };
//	SetConsoleCursorPosition(handle, pos);
//	GetConsoleCursorInfo(handle, &Cursor_Info);
//	Cursor_Info.bVisible = false;
//	SetConsoleCursorInfo(handle, &Cursor_Info);*/
//	while (1)
//	{
//		if (KEY_PRESS(0x30))
//		{
//			printf("0\n");
//		}
//		else if (KEY_PRESS(0x31))
//		{
//			printf("1\n");
//		}
//		else if(KEY_PRESS(0x32))
//		{
//			printf("2\n");
//		}
//		else if(KEY_PRESS(0x33))
//		{
//			printf("3\n");
//		}
//		else if(KEY_PRESS(0x34))
//		{
//			printf("4\n");
//		}
//		else if(KEY_PRESS(0x35))
//		{
//			printf("5\n");
//		}
//		else if(KEY_PRESS(0x36))
//		{
//			printf("6\n");
//		}
//		else if(KEY_PRESS(0x37))
//		{
//			printf("7\n");
//		}
//		else if (KEY_PRESS(0x38))
//		{
//			printf("8\n");
//		}
//		else if (KEY_PRESS(0x39))
//		{
//			printf("9\n");
//		}
//		else {
//
//		}
//	}
//
//	getchar();
//	return 0;
//}