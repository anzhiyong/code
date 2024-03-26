#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Contact.h"
//��̬˳���
//#define N 7
//typedef int SLDataType;
//struct SeqList {
//	SLDataType a[N];
//	int size;
//};

//��̬˳���
//typedef int SLDataType;
typedef Info SLDataType;
typedef struct SeqList {
	SLDataType* arr;
	int capacity;   //��¼˳���Ŀռ��С
	int size;       //��¼˳���ǰ��Ч�����ݸ���
}SL;
//˳���ĳ�ʼ��������
void SLInit(SL* ps);
void SLPrintf(SL* ps);
void SLDestroy(SL* ps);

//���� 
void SLCheckCapacity(SL* ps);

//˳����ͷ��/β������
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);
//˳����ͷ��/β��ɾ��
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//ָ��λ��֮ǰ��������
//ɾ��ָ������
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);