#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//int main()
//{
//	int n = 0;//
//	char ch = 'a';
//
//	//数组 - 存放一个班级的数学成绩
//	int arr[30] = {0};
//
//
//	return 0;
//}

#include <stdlib.h>
//
//int main()
//{
//	//int arr[10];//
//
//	int* p = (int*)malloc(10*sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	//
//	int i = 0;
//	//使用 - 给数组赋值
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	//释放空间
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//
//int main()
//{
//	//int arr[10];//
//
//	//int* p = (int*)malloc(10 * sizeof(int));
//	int*p = (int*)calloc(10, sizeof(int));
//
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	//
//	int i = 0;
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	//空间不够，想要扩大空间，20个整型
//	int* ptr = (int*)realloc(p, 12*sizeof(int));
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	//使用空间了
//	
//	//释放空间
//	free(p);
//	p = NULL;
//
//	return 0;
//}



//int main()
//{
//	int*p = (int*)realloc(NULL, 40);//等价于malloc
//
//	//释放空间
//	free(p);
//	p = NULL;
//
//	return 0;
//}
//

//1. 对NULL指针的解引用操作
//int main()
//{
//	int*p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		//报错信息
//		perror("malloc");
//		return 1;
//	}
//	*p = 20;//p有可能是NULL指针的
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//2 对动态开辟空间的越界访问

//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当循环到第11次时就越界访问了
//	}
//	//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//3 对非动态开辟内存使用free释放

//int main()
//{
//	int a = 10;
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	//使用
//	//...
//	p = &a;//p指向的空间就不再是堆区上的空间
//	free(p);
//	p = NULL;
//	//....
//
//	return 0;
//}


//int* test()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//		return NULL; 
//	else
//		return p;
//}
//
//int main()
//{
//	int* ret = test();
//
//	return 0;
//}

//4 使用free释放一块动态开辟内存的一部分


//int main()
//{
//	int a = 10;
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}	
//	//使用
//	p++;
//
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//5 对同一块动态内存多次释放

//int main()
//{
//	int a = 10;
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	//使用
//
//	//释放
//	free(p);
//	p = NULL;
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}
// 
//6 动态开辟内存忘记释放（内存泄漏）
//
//
//void test()
//{
//    int* p = (int*)malloc(100);
//    if (NULL != p)
//    {
//        *p = 20;
//    }
//    free(p);
//    p = NULL;
//}
//
//int main()
//{
//    test();
//    //
//    while (1);
//}



//void test()
//{
//    int* p = (int*)malloc(100);
//    if (NULL != p)
//    {
//        return;
//    }
//    free(p);
//    p = NULL;
//}
//
//int main()
//{
//    test();
//    //
//    while (1);
//}


//void GetMemory(char* p)
//{
//    p = (char*)malloc(100);
//}
//void Test(void)
//{
//    char* str = NULL;
//    GetMemory(str);
//    strcpy(str, "hello world");
//    printf(str);
//}
//
//
//int main()
//{
//    Test();
//    return 0;
//}


//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	printf("abcdef\n");
//	printf(arr);
//
//	return 0;
//}
// 
// 
//void GetMemory(char** p)
//{
//    *p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//    char* str = NULL;
//    GetMemory(&str);
//    strcpy(str, "hello world");
//    printf(str);
//    free(str);
//    str = NULL;
//}
//
//int main()
//{
//    Test();
//    return 0;
//}
#include <string.h>

//char* GetMemory()
//{
//    char* p = (char*)malloc(100);
//    return p;
//}
//
//void Test(void)
//{
//    char* str = NULL;
//    str = GetMemory();
//    strcpy(str, "hello world");
//    printf(str);
//    free(str);
//    str = NULL;
//}
//
//int main()
//{
//    Test();
//    return 0;
//}
//


//char* GetMemory(void)
//{
//    static char p[] = "hello world";
//    return p;
//}
//
//void Test(void)
//{
//    char* str = NULL;
//    str = GetMemory();
//    printf(str);
//}
//
//int main()
//{
//    Test();
//    return 0;
//}
//


//int* test()
//{
//	int n = 100;
//	return &n;
//}
//
//int main()
//{
//	int* ptr = test();
//	printf("hehe\n");
//
//	printf("%d\n", *ptr);
//
//	return 0;
//}
//
//

//
//void GetMemory(char** p, int num)
//{
//    *p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//    char* str = NULL;
//    GetMemory(&str, 100);
//    strcpy(str, "hello");
//    printf(str);
//    free(str);
//    str = NULL;
//}
//
//int main()
//{
//    Test();
//    return 0;
//}

//void Test(void)
//{
//    char* str = (char*)malloc(100);
//    strcpy(str, "hello");
//    free(str);
//    str = NULL;
//
//    //str就是野指针
//    if (str != NULL)
//    {
//        strcpy(str, "world");//非法访问
//        printf(str);
//    }
//}
//
//int main()
//{
//    Test();
//    return 0;
//}

//
//
//struct St
//{
//	char c;
//	int n;
//	int arr[0];//
//};
//
//
//int main()
//{
//	//struct St s = {0};
//	//printf("%d\n", sizeof(struct St));
//	struct St* ps = (struct St*)malloc(sizeof(struct St) + 10 * sizeof(int));
//	if (ps == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	ps->c = 'w';
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//数组空间不够
//	struct St* ptr = realloc(ps, sizeof(struct St) + 15 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	//...继续使用
//
//	for (i = 10; i < 15; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	for (i = 0; i < 15; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n%d\n", ps->n);
//	printf("%c\n", ps->c);
//
//
//
//	//释放
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}




struct St
{
	char c;
	int n;
	int* arr;
};


int main()
{
	//struct St s = {0};
	//printf("%d\n", sizeof(struct St));
	struct St* ps = (struct St*)malloc(sizeof(struct St));
	if (ps == NULL)
	{
		perror("malloc");
		return 1;
	}
	ps->c = 'w';
	ps->n = 100;
	
	ps->arr = (int*)malloc(10*sizeof(int));
	if (ps->arr == NULL)
	{
		perror("malloc-2");
		return 1;
	}
	//使用
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}

	//数组空间不够
	int* ptr = (int*)realloc(ps->arr, 15*sizeof(int));
	if (ptr == NULL)
	{
		perror("realloc");
		return 1;
	}
	else
	{
		ps->arr = ptr;
	}
	//使用
	for (i = 10; i < 15; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 15; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n%d\n", ps->n);
	printf("%c\n", ps->c);

	//释放
	free(ps->arr);
	ps->arr = NULL;

	free(ps);
	ps = NULL;

	return 0;
}




