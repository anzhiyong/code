#pragma once
#include<stdio.h>
#include<stdlib.h>

//��ӡ
void PrintArray(int* a, int n);

//1.ֱ�Ӳ�������
void InsertSort(int* a, int n);
//2.ϣ������
void ShellSort(int* a, int n);


//3.ѡ������
void SelectSort(int* a, int n);
//4.������
void HeapSort(int* a, int n);


//5.ð������
void BubbleSort(int* a, int n);
//6.��������
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);//�ǵݹ�

//7.�鲢����
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);//�ǵݹ�

//��������
void CountSort(int* a, int n);