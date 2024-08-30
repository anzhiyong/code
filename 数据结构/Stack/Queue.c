#define _CRT_SECURE_NO_WARNINGS 1
#include  "Queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->ptail = NULL;
	pq->size = 0;
	
}

//释放队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->ptail = NULL;
	pq->size = 0;
}
//入队列
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//队列只有一个元素
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc:false");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;


	if (pq->ptail)
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	else
	{
		pq->head = pq->ptail = newnode;
	}

	pq->size++;
}
//出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	//检查队列为空
	assert(pq->head != NULL);
	//一个节点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;
}

//获取队列元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//检查队列为空
	assert(pq->head != NULL);
	return pq->head->val;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//检查队列为空
	assert(pq->head != NULL);
	return pq->ptail->val;
}

//探空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	
	return pq->head == NULL;
}
//队列元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}