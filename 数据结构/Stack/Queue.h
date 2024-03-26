#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* ptail;
	int size;

}Queue;


//初始化
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
//入队列
void QueuePush(Queue* pq, QDataType x);
//出队列
void QueuePop(Queue* pq);

//获取队列元素
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//探空
bool QueueEmpty(Queue* pq);
//队列元素个数
int QueueSize(Queue* pq);
