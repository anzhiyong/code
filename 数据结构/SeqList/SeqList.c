#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SLInit(SL* ps) {
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SLDestroy(SL* ps) {
	assert(ps);

	if (ps->arr) {
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
void SLPrintf(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* ps) {
	if (ps->capacity == ps->size) {
		int newscapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tem = (SLDataType*)realloc(ps->arr, newscapacity * sizeof(SLDataType));
		if (tem == NULL)
		{
			perror("realloc file!");
			exit(1);
		}
		ps->arr = tem;
		ps->capacity = newscapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	//�ռ䲻��������
	SLCheckCapacity(ps);
	//�ռ��㹻��ֱ�Ӳ���
	ps->arr[ps->size] = x;
	ps->size++;
}
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	for (int i = ps->size; i >= 0; i--) {
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}
//βɾ
void SLPopBack(SL* ps) {
	assert(ps);
	assert(ps->size);

	ps->size--;
}
//ͷɾ
void SLPopFront(SL* ps) {
	assert(ps);
	SLCheckCapacity(ps);

	for (int i = 0; i <ps->size-1; i++) {
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//ָ��λ�ò���
void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//?

	for (int i = ps->size; i >= pos; i--) {
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//ָ��λ��ɾ��
void SLErase(SL* ps, int pos) {  
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	//��pos�Ժ��������ǰŲ
	for (int i = pos; i < ps->size-1; i++) {
		ps->arr[i] = ps->arr[i+1];
	}
	ps->size--;
}