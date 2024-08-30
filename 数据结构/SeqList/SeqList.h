#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Contact.h"
//静态顺序表
//#define N 7
//typedef int SLDataType;
//struct SeqList {
//	SLDataType a[N];
//	int size;
//};

//动态顺序表
//typedef int SLDataType;
typedef Info SLDataType;
typedef struct SeqList {
	SLDataType* arr;
	int capacity;   //记录顺序表的空间大小
	int size;       //记录顺序表当前有效的数据个数
}SL;
//顺序表的初始化和销毁
void SLInit(SL* ps);
void SLPrintf(SL* ps);
void SLDestroy(SL* ps);

//扩容 
void SLCheckCapacity(SL* ps);

//顺序表的头部/尾部插入
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);
//顺序表的头部/尾部删除
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//指定位置之前插入数据
//删除指定数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);