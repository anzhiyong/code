#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

// 堆的构建
void HeapInit(Heap* hp)
{
	assert(hp);

	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void Swap(HPDataType* px, HPDataType* py)//&&&&&&&!!!!!
{
	HPDataType tmp = *px;
	*px = *py;
	*py = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;//假设左孩子
	
	while (child <n)
	{
		if (child + 1 < n && a[child + 1] < a[child])//大堆选大的孩子
		{
			child++;
		}
		if (a[child] < a[parent])  //孩子大就是大堆，孩子小就是小堆
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

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		size_t newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tem = realloc(hp->a, sizeof(HPDataType) * newCapacity);
		if (tem == NULL)
		{
			perror("realloc:error");
			return;
		}
		hp->a = tem;
		hp->capacity = newCapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	

	AdjustDown(hp->a, hp->size-1 ,0);
	
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a,hp->size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}


// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	//建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}




void PrintTopK()
{
	int k;
	scanf("%d", &k);
	//const char* file = "D:\\Code\\legend\\tree\\data.txt";

	//1.打开文件
	FILE* fout = fopen("D:\\Code\\legend\\tree\\data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen:fail");
		return -1;
	}
	int val = 0;
	//2.开辟数组用来存小堆
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc:fail");
		return -1;
	}
	//3.读取k个数据到数组
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	//4.建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		//5. 读取剩余数据，比堆顶的值大，就替换他进堆
		if (x > minheap[0])
		{
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}

	fclose(fout);
}


void TopK()
{
	int k = 0;
	scanf("%d", &k);
	FILE* fout = fopen("D:\\Code\\legend\\tree\\data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen:file");
		return -1;
	}
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc:fail");
		return -1;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}
	//建小堆
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}
	int x = 0;
	while ((fscanf(fout,"%d",&x)) != -1)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;
			AdjustDown(minheap, k, 0);

		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}



	fclose(fout);
}