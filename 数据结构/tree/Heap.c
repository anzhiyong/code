#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

// �ѵĹ���
void HeapInit(Heap* hp)
{
	assert(hp);

	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}
// �ѵ�����
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
	int child = parent * 2 + 1;//��������
	
	while (child <n)
	{
		if (child + 1 < n && a[child + 1] < a[child])//���ѡ��ĺ���
		{
			child++;
		}
		if (a[child] < a[parent])  //���Ӵ���Ǵ�ѣ�����С����С��
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

// �ѵĲ���
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
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a,hp->size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// �ѵ��п�
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}


// ��������ж�����
void HeapSort(int* a, int n)
{
	//�����
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

	//1.���ļ�
	FILE* fout = fopen("D:\\Code\\legend\\tree\\data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen:fail");
		return -1;
	}
	int val = 0;
	//2.��������������С��
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc:fail");
		return -1;
	}
	//3.��ȡk�����ݵ�����
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	//4.��С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		//5. ��ȡʣ�����ݣ��ȶѶ���ֵ�󣬾��滻������
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
	//��С��
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