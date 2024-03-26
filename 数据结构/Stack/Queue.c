#define _CRT_SECURE_NO_WARNINGS 1
#include  "Queue.h"
//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->ptail = NULL;
	pq->size = 0;
	
}

//�ͷŶ���
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
//�����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//����ֻ��һ��Ԫ��
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
//������
void QueuePop(Queue* pq)
{
	assert(pq);
	//������Ϊ��
	assert(pq->head != NULL);
	//һ���ڵ�
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

//��ȡ����Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//������Ϊ��
	assert(pq->head != NULL);
	return pq->head->val;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//������Ϊ��
	assert(pq->head != NULL);
	return pq->ptail->val;
}

//̽��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	
	return pq->head == NULL;
}
//����Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}