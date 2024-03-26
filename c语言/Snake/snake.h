#pragma once
#include<locale.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#define WALL L'□'//墙体
#define BODY L'●'//蛇身体
#define FOOD L'★'//食物

#define POS_X 24//蛇初始坐标
#define POS_Y 5

#define KEY_PRESS(VK)  ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )

//蛇走的方向
enum DIRECTION
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态
enum GAME_STATE
{
	OK = 1,
	ESC,
	KILL_BY_WALL,
	KILL_BY_SELF
};

//蛇身节点
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

//贪吃蛇
typedef struct Snake
{
	pSnakeNode pSnake;//蛇的长度
	pSnakeNode pFood;//食物
	int Score;       //当前累计的分数
	int FoodWeight;   //一个食物的分值
	int SleepTime;    //蛇的速度
	enum GAME_STATE state;//蛇的状态
	enum DIRECTION dir;//蛇的方向
}Snake,* pSnake;

void SetPos(int x, int y);//设置光标位置

void GameStart(pSnake ps);//游戏初始化
void WelcomeToGame();//打印欢迎信息
void CreateMap();//创建地图
void InitSnake(pSnake ps);//初始化蛇
void CreateFood(pSnake ps);//创建食物

void GameRun(pSnake ps);//游戏运行逻辑
void PrintHelpInfo();//打印帮助信息
void SnakeMove(pSnake ps);//蛇移动一步
int NextIsFood(pSnake ps,pSnakeNode pNext);//判断蛇头的下一步是否是食物
void EatFood(pSnake ps, pSnakeNode pNext);//下一个位置是食物吃掉
void NotEatFood(pSnake ps, pSnakeNode pNext);//下一个位置不是食物，正常走
void KillByWall(pSnake ps);//检测撞墙
void KillBySelf(pSnake ps);//撞到自己

void GameEnd(pSnake ps);//游戏结束资源释放
