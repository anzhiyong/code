#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"

//设置光标位置
void SetPos(int x,int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(handle, pos);
}
void WelcomeToGame()
{
	SetPos(40, 15);
	printf("欢迎来到贪吃蛇");
	SetPos(40, 20);
	system("pause");
	system("cls");

	//功能介绍
	SetPos(15, 10);
	printf("用 ↑ . ↓ . ← . → 来控制蛇的移动，F3是加速，F4是减速");
	SetPos(15, 11);
	printf("加速能得到更高的分数");
	SetPos(38, 20);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//上
	SetPos(0, 0);
	for (int i = 0; i <= 56; i += 2)
	{
		wprintf(L"%c", WALL);
	}
	//下
	SetPos(0, 26);
	for (int i = 0; i <= 56; i += 2)
	{
		wprintf(L"%c", WALL);
	}
	//左
	for (int i = 1; i <= 25; i ++)
	{
		SetPos(0, i);
		wprintf(L"%c", WALL);
	}
	//右
	for (int i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%c", WALL);
	}
}

void InitSnake(pSnake ps)
{
	//创建五个蛇神节点
	pSnakeNode cur = NULL;
	for (int i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake:malloc");
			return;
		}
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		cur->next = NULL;

		//头插法
		if (ps->pSnake == NULL)
		{
			ps->pSnake = cur;
		}
		else
		{
			cur->next = ps->pSnake;
			ps->pSnake = cur;
		}
	}
	//打印蛇的身体
	cur = ps->pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//贪吃蛇其他信息初始化
	ps->dir = RIGHT;
	ps->FoodWeight = 10;
	ps->pFood = NULL;
	ps->Score = 0;
	ps->SleepTime = 200;
	ps->state = OK;
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;

again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 24 + 1;
	} while (x % 2 != 0);

	//判断食物是否在蛇身上
	pSnakeNode cur = ps->pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//创建食物
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood():malloc()");
		return;
	}
	pFood->x = x;
	pFood->y = y;

	ps->pFood = pFood;
	SetPos(x, y);
	wprintf(L"%c", FOOD);

}

void GameStart(pSnake ps)
{
	//设置控制台
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇@安");
	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorinfo;
	GetConsoleCursorInfo(handle, &cursorinfo);
	cursorinfo.bVisible = false;
	SetConsoleCursorInfo(handle, &cursorinfo);
	//打印欢迎信息
	WelcomeToGame();
	//绘制地图
	CreateMap();
	//初始化蛇
	InitSnake(ps);
	//创建食物
	CreateFood(ps);
}

void PrintHelpInfo()
{
	SetPos(60, 15);
	printf("1.不能撞墙 不能撞自己");
	SetPos(60, 16);
	printf("2.用上下左右控制蛇的方向");
	SetPos(60, 17);
	printf("3.f3加速 f4减速");
	SetPos(60, 19);
	printf("版权@an");
}

void Pause()//游戏暂停
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

int NextIsFood(pSnake ps, pSnakeNode pNext)
{
	if (ps->pFood->x == pNext->x && ps->pFood->y == pNext->y)
		return 1;
	else
		return 0;
}

void EatFood(pSnake ps, pSnakeNode pNext)
{
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;
	
	pSnakeNode cur = ps->pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%c", BODY);
		cur = cur->next;
	}
	ps->Score += ps->FoodWeight;

	//释放掉旧食物
	free(ps->pFood);
	//创建新食物;
	CreateFood(ps);
}

void NotEatFood(pSnake ps, pSnakeNode pNext)
{
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;

	pSnakeNode cur = ps->pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%c", BODY);
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}

void KillByWall(pSnake ps)
{
	if (ps->pSnake->x == 0 ||
		ps->pSnake->x == 56 ||
		ps->pSnake->y == 0 ||
		ps->pSnake->y == 26)
	{
		ps->state = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->pSnake->next;
	while (cur)
	{
		if (cur->x == ps->pSnake->x && cur->y == ps->pSnake->y)
		{
			ps->state = KILL_BY_SELF;
			return;
		}
		cur = cur->next;
	}
}
void SnakeMove(pSnake ps)
{
	pSnakeNode pNext = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNext == NULL)
	{
		perror("SnakeMove():malloc:");
		return;
	}
	pNext->next = NULL;
	switch (ps->dir)
	{
	case UP:
		pNext->x = ps->pSnake->x;
		pNext->y = ps->pSnake -> y - 1;
		break;
	case DOWN:
		pNext->x = ps->pSnake->x;
		pNext->y = ps->pSnake -> y + 1;
		break;
	case LEFT:
		pNext->x = ps->pSnake->x - 2;
		pNext->y = ps->pSnake->y;
		break;
	case RIGHT:
		pNext->x = ps->pSnake->x + 2;
		pNext->y = ps->pSnake->y;
		break;
	}
	//下一个坐标处是否是食物
	if (NextIsFood(ps, pNext))
	{
		//是食物就吃掉
		EatFood(ps, pNext);
	}
	else
	{
		//不是，正常走
		NotEatFood(ps, pNext);
	}

	//检测撞墙
	KillByWall(ps);
	//是否撞到自己
	KillBySelf(ps);
}

void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintHelpInfo();
	
	do
	{
		//当前的分数情况
		SetPos(60, 10);
		printf("总分：%5d", ps->Score);
		SetPos(60, 11);
		printf("食物的分值：%02d", ps->FoodWeight);
		//检测按键
		if (KEY_PRESS(VK_UP) && ps->dir != DOWN)
		{
			ps->dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->dir != UP)
		{
			ps->dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->dir != RIGHT)
		{
			ps->dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->dir != LEFT)
		{
			ps->dir = RIGHT;
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->state = ESC;
			break;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停和恢复游戏
			Pause();
		}
		else if (KEY_PRESS(VK_F3))
		{
			if (ps->SleepTime >= 80 )
			{
				ps->SleepTime -= 30;
				ps->FoodWeight += 2;
			}
			
		}
		else if (KEY_PRESS(VK_F4))
		{
			if (ps->FoodWeight > 2)
			{
				ps->SleepTime += 30;
				ps->FoodWeight -= 2;
			}
		}
		//走一步
		SnakeMove(ps);
		//休眠一下
		Sleep(ps->SleepTime);
		
	} while (ps->state == OK);
	
}

void GameEnd(pSnake ps)
{
	SetPos(15, 12);
	switch (ps->state)
	{
	case ESC:
		printf("主动退出游戏\n");
		break;
	case KILL_BY_WALL:
		printf("很遗憾，撞墙了，游戏结束\n");
		break;
	case KILL_BY_SELF:
		printf("很遗憾，撞到自己，游戏结束\n");
		break;
	}

	//释放
	pSnakeNode cur = ps->pSnake;
	pSnakeNode del = NULL;

	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}

	free(ps->pFood);
	ps = NULL;

}