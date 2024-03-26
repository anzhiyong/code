#define _CRT_SECURE_NO_WARNINGS 1
//#include"Stack.h"
//
//int main()
//{
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPop(&st);
//
//
//	int ret = StackSize(&st);
//	printf("%d\n", ret);
//	StackDestroy(&st);
//	return 0;
//}

#include"Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePop(&q);
	int data = QueueFront(&q);
	printf("%d\n", data);
	QueueDestroy(&q);
	return 0;
}