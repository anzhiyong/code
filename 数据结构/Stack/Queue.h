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


//��ʼ��
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
//�����
void QueuePush(Queue* pq, QDataType x);
//������
void QueuePop(Queue* pq);

//��ȡ����Ԫ��
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//̽��
bool QueueEmpty(Queue* pq);
//����Ԫ�ظ���
int QueueSize(Queue* pq);
