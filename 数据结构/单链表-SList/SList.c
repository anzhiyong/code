#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SLTPrint(SLTNode* phead) 
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* SLBuyNode(SLTDataType x) 
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}
//�����ͷ�塢β��
void SLTPushBack(SLTNode** pphead, SLTDataType x) 
{
	assert(pphead);
	SLTNode* newnode = SLBuyNode(x);
	//����Ϊ�գ��½ڵ���Ϊpphead
	if (*pphead == NULL)
	{
		*pphead = newnode;
		return;
	}
	//����Ϊ��,��β�ڵ�
	SLTNode* ptail = *pphead;
	while (ptail->next)
	{
		ptail = ptail->next;
	}
	ptail->next = newnode;
}
void SLTPushFront(SLTNode** pphead, SLTDataType x) 
{
	assert(pphead);
	SLTNode* newnode = SLBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//�����ͷɾ��βɾ
void SLTPopBack(SLTNode** pphead) 
{
	assert(pphead);
	assert(*pphead);
	//�������ֻ��һ��
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	//����Ϊ��
	SLTNode* ptail = *pphead;
	SLTNode* preve = NULL;
	while (ptail->next)
	{
		preve = ptail;
		ptail = ptail->next;
	}
	preve->next = NULL;
	//����β�ڵ�
	free(ptail);
	ptail = NULL;
}
void SLTPopFront(SLTNode** pphead) 
{
	assert(pphead);
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//����
SLTNode* SLTFind(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);

	SLTNode* newnode = SLBuyNode(x);
	//pos��ͷ�ڵ�ʱ
	if (pos == *pphead)
	{
		//ͷ��
		SLTPushFront(pphead, x);
		return;
	}
	//pos����ͷ�ڵ�
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = newnode;
	newnode->next = pos;
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = SLBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	//��posΪͷ�ڵ�
	if (*pphead == pos)
	{
		//ͷɾ
		SLTPopFront(pphead);
		return;
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//prev pos pos->next
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}

void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	//pos      pos->next    pos->next->next
	SLTNode* next = pos->next;
	pos->next = pos->next->next;
	free(next);
	next = NULL;
}

void SListDesTroy(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}