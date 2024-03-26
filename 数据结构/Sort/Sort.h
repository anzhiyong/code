#pragma once
#include<stdio.h>
#include<stdlib.h>

//¥Ú”°
void PrintArray(int* a, int n);

//1.÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);
//2.œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);


//3.—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);
//4.∂—≈≈–Ú
void HeapSort(int* a, int n);


//5.√∞≈›≈≈–Ú
void BubbleSort(int* a, int n);
//6.øÏÀŸ≈≈–Ú
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);//∑«µ›πÈ

//7.πÈ≤¢≈≈–Ú
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);//∑«µ›πÈ

//º« ˝≈≈–Ú
void CountSort(int* a, int n);