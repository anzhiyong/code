#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"

//���ù��λ��
void SetPos(int x,int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(handle, pos);
}
void WelcomeToGame()
{
	SetPos(40, 15);
	printf("��ӭ����̰����");
	SetPos(40, 20);
	system("pause");
	system("cls");

	//���ܽ���
	SetPos(15, 10);
	printf("�� �� . �� . �� . �� �������ߵ��ƶ���F3�Ǽ��٣�F4�Ǽ���");
	SetPos(15, 11);
	printf("�����ܵõ����ߵķ���");
	SetPos(38, 20);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//��
	SetPos(0, 0);
	for (int i = 0; i <= 56; i += 2)
	{
		wprintf(L"%c", WALL);
	}
	//��
	SetPos(0, 26);
	for (int i = 0; i <= 56; i += 2)
	{
		wprintf(L"%c", WALL);
	}
	//��
	for (int i = 1; i <= 25; i ++)
	{
		SetPos(0, i);
		wprintf(L"%c", WALL);
	}
	//��
	for (int i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%c", WALL);
	}
}

void InitSnake(pSnake ps)
{
	//�����������ڵ�
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

		//ͷ�巨
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
	//��ӡ�ߵ�����
	cur = ps->pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//̰����������Ϣ��ʼ��
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

	//�ж�ʳ���Ƿ���������
	pSnakeNode cur = ps->pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//����ʳ��
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
	//���ÿ���̨
	system("mode con cols=100 lines=30");
	system("title ̰����@��");
	//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorinfo;
	GetConsoleCursorInfo(handle, &cursorinfo);
	cursorinfo.bVisible = false;
	SetConsoleCursorInfo(handle, &cursorinfo);
	//��ӡ��ӭ��Ϣ
	WelcomeToGame();
	//���Ƶ�ͼ
	CreateMap();
	//��ʼ����
	InitSnake(ps);
	//����ʳ��
	CreateFood(ps);
}

void PrintHelpInfo()
{
	SetPos(60, 15);
	printf("1.����ײǽ ����ײ�Լ�");
	SetPos(60, 16);
	printf("2.���������ҿ����ߵķ���");
	SetPos(60, 17);
	printf("3.f3���� f4����");
	SetPos(60, 19);
	printf("��Ȩ@an");
}

void Pause()//��Ϸ��ͣ
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

	//�ͷŵ���ʳ��
	free(ps->pFood);
	//������ʳ��;
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
	//��һ�����괦�Ƿ���ʳ��
	if (NextIsFood(ps, pNext))
	{
		//��ʳ��ͳԵ�
		EatFood(ps, pNext);
	}
	else
	{
		//���ǣ�������
		NotEatFood(ps, pNext);
	}

	//���ײǽ
	KillByWall(ps);
	//�Ƿ�ײ���Լ�
	KillBySelf(ps);
}

void GameRun(pSnake ps)
{
	//��ӡ������Ϣ
	PrintHelpInfo();
	
	do
	{
		//��ǰ�ķ������
		SetPos(60, 10);
		printf("�ܷ֣�%5d", ps->Score);
		SetPos(60, 11);
		printf("ʳ��ķ�ֵ��%02d", ps->FoodWeight);
		//��ⰴ��
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
			//��ͣ�ͻָ���Ϸ
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
		//��һ��
		SnakeMove(ps);
		//����һ��
		Sleep(ps->SleepTime);
		
	} while (ps->state == OK);
	
}

void GameEnd(pSnake ps)
{
	SetPos(15, 12);
	switch (ps->state)
	{
	case ESC:
		printf("�����˳���Ϸ\n");
		break;
	case KILL_BY_WALL:
		printf("���ź���ײǽ�ˣ���Ϸ����\n");
		break;
	case KILL_BY_SELF:
		printf("���ź���ײ���Լ�����Ϸ����\n");
		break;
	}

	//�ͷ�
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