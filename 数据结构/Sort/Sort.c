#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);

	}
	printf("\n");
}

void InsertSort(int* a,int n)
{
	//[0-end]
	int i;
	for (i = 0; i < n-1; i++)
	{
		int end = i;
		int tem = a[end + 1];
		while (end >= 0)
		{
			if (tem < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tem;
		
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)	
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tem = a[end + gap];
			while (end >= 0)
			{
				if (tem < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			
			a[end + gap] = tem;
		}
	}
}




void Swap(int* p1, int* p2)
{
	int tem = *p1;
	*p1 = *p2;
	*p2 = tem;
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int eag = 0;
		for (int j = 1; j < n - i; j++)
		{
			
			if (a[j-1] > a[j])
			{
				Swap(&a[j-1], &a[j]);
				eag = 1;
			}
		}
		if (eag == 0)
		{
			break;
		}
	}
}

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;
//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;//假设左孩子

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])//大堆选大的孩子
		{
			child++;
		}
		if (a[child] > a[parent])  //孩子大就是大堆，孩子小就是小堆
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//升序选大堆
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[mini], &a[begin]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
	
}