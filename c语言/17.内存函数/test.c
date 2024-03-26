#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//暴力求解
//char* my_strstr(const char* str1, const char* str2)
//{
//	const char* cur = str1;
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//
//	assert(str1 && str2);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = str2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cur;
//		}
//		cur++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//		printf("%s\n", ret);
//	else
//		printf("找不到\n");
//
//	return 0;
//}

//测试用例1
//abcdef
//cde

//测试用例2
//abcdef
//cbq

//测试用例3
//abbbcdef
//bbc

//测试用例4
//abcdef
//abcdef

#include <string.h>

//
//int main()
//{
//	char arr[] = "zhangsan@163.com#hehe";
//	char arr2[30] = {0}; //zhangsan\0163\0com
//	strcpy(arr2, arr);
//	const char* p = "@.#";
//	char* s = NULL;
//	//   初始化部分只执行一次
//	for (s = strtok(arr2, p); s != NULL; s=strtok(NULL, p))
//	{
//		printf("%s\n", s);
//	}
//
//	//char *s = strtok(arr2, p);
//	//printf("%s\n", s);
//	//s = strtok(NULL, p);
//	//printf("%s\n", s);
//	//s = strtok(NULL, p);
//	//printf("%s\n", s);
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d: %s\n",i, strerror(i));
//	}
//
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <errno.h>

//int main()
//{
//    FILE* pFile;
//    pFile = fopen("unexist.txt", "r");
//    if (pFile == NULL)
//        printf("Error opening file unexist.ent: %s\n", strerror(errno));
//    else
//        printf("打开文件成功\n");
//
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    FILE* pFile;
//    pFile = fopen("unexist.ent", "r");
//    if (pFile == NULL)
//        //printf("Error opening file unexist.ent: %s\n", strerror(errno));
//        perror("Error opening file unexist.ent");
//    return 0;
//}
//

#include <string.h>
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = {0};
//	//将arr1中的1 2 3 4 5，拷贝到arr2中
//	memcpy(arr2, arr1, 5*sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}


//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	//将arr1中的4 5 6 7 8，拷贝到arr2中
//	memcpy(arr2, arr1+3, 5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr1[10] = "he\0lo bit";
//	char arr2[10] = { 0 };
//	//将arr1中的4 5 6 7 8，拷贝到arr2中
//	memcpy(arr2, arr1, 5);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%c ", arr2[i]);
//	}
//
//	return 0;
//}

//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest+1;
//		src = (char*)src + 1;
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	//将arr1中的4 5 6 7 8，拷贝到arr2中
//	my_memcpy(arr2, arr1+3, 5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//void* my_memmove(void* dest, const void*src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	if (dest < src)
//	{
//		//前->后
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//后->前
//		while (num--)
//		{
//			*((char*)dest+num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1, arr1+2, 5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);// 1 2 1 2 3 4 5 8 9 10
//	}
//
//	return 0;
//}


//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	memcpy(arr1+2, arr1, 5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);// 1 2 1 2 3 4 5 8 9 10
//	}
//
//	return 0;
//}

//memset - 内存设置
//int main()
//{
//	char arr[10] = "hello bit";
//	memset(arr, 'x', 5);
//	//memset 在设置的时候，是以字节为单位来设置的
//	//
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 40);
//
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 1,2,3,4,8 };
//	int ret = memcmp(arr1, arr2, 17);
//	printf("%d\n", ret);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;//0x 00 00 00 0a
//	int b = 0x11223344;
//
//	return 0;
//}


//
//写一个代码，来判断当前机器是大端还是小端？
//

//int main()
//{
//	int a = 1;
//	char* p = (char*)& a;
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	if (*(char*)&a == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}


int check_sys()
{
	int a = 1;
	//1. 取出a的地址
	//2. 强制类型转换成char*后解引用，只取a的第一个字节的数据
	//3. 如果取出是1，就是小端，取出是0就是大端
	return *(char*)&a;
}

int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("小端\n");
	else
		printf("大端\n");

	return 0;
}
