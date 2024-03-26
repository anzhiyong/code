#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>

//int main()
//{
//	//char arr[] = "abcdef";//[a b c d e f \0]
//	char arr[] = { 'a', 'b', 'c' ,'\0'};//[a b c]
//	size_t len = strlen(arr);
//	printf("%zd\n", len);
//
//	return 0;
//}

//int main()
//{
//	//3-6=-3
//	if ((int)strlen("abc") - (int)strlen("abcdef") > 0)
//	{
//		printf("大于\n");
//	}
//	else
//	{
//		printf("小于等于\n");
//	}
//	return 0;
//}
//
#include <assert.h>

size_t my_strlen1(const char* str)
{
	size_t count = 0;
	assert(str != NULL);
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

size_t my_strlen2(const char* str)
{
	assert(str);
	const char* start = str;
	while (*str)
	{
		str++;
	}
	return str - start;
}

//写一个函数，不能使用临时变量，求字符串长度 - 递归
size_t my_strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen(str + 1);
}

//my_strlen("abcdef");
//1+my_strlen("bcdef");
//1+1+my_strlen("cdef");
//1+1+1+my_strlen("def");
//1+1+1+1+my_strlen("ef");
//1+1+1+1+1+my_strlen("f");
//1+1+1+1+1+1+my_strlen("");
//1+1+1+1+1+1+0;
//
//int main()
//{
//	char arr[] = "abc";
//	size_t len = my_strlen(arr);
//	printf("%zd\n", len);
//
//	return 0;
//}
//



//int main()
//{
//	char arr1[20] = "xxxxxxxxx";
//	char arr2[] = {'a', 'b', 'c','\0'};
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//int main()
//{
//	char arr1[5] = {0};//目标空间必须足够大
//	char arr2[] = "hello world";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//int main()
//{
//	char* p = "abcdefghilmkqwer";//常量字符串，不能修改
//	char arr2[] = "hello world";
//	strcpy(p, arr2);//目标空间必须是可修改的
//	printf("%s\n", p);
//
//	return 0;
//}

//模拟实现strcpy函数

//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//}
//
//char* my_strcpy(char* dest, char* src)
//{
//	/*assert(dest != NULL);
//	assert(src != NULL);*/
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//	printf("%s\n", my_strcpy(arr1, arr2));
//
//	return 0;
//}



//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	//1. 找到目标空间的\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//2. 拷贝
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	//1. 找到目标空间的\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//2. 拷贝
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	my_strcat(arr1, arr1);
//	printf("%s\n", arr1);
//
//	return 0;
//}
//

//int main()
//{
//	int ret = strcmp("bbq", "abcdef");
//	printf("%d\n", ret);
//
//	return 0;
//}


//int main()
//{
//	int ret = strcmp("bbq", "abcdef");
//	if (ret > 0)
//		printf("大于\n");
//	else if (ret == 0)
//		printf("等于\n");
//	else
//		printf("小于\n");
//
//	return 0;
//}

//int my_strcmp(const char* s1, const char* s2)
//{
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	if (*s1 > *s2)
//		return 1;
//	else
//		return -1;
//}
//
//int my_strcmp(const char* s1, const char* s2)
//{
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//
//int main()
//{
//	int ret = my_strcmp("abcdef", "abc");
//	if (ret > 0)
//		printf("大于\n");
//	else if (ret == 0)
//		printf("等于\n");
//	else
//		printf("小于\n");
//	return 0;
//}
//
//



//int main()
//{
//	char arr1[20] = "xxxxxxxxxx";
//	char arr2[] = "hello";
//	strncpy(arr1, arr2, 7);
//
//	return 0;
//}

//int main()
//{
//	char arr1[20] = "hello\0xxxxxxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 7);
//
//	return 0;
//}




//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcq";
//	int ret = strncmp(arr1, arr2, 3);
//
//	printf("%d\n", ret);
//	return 0;
//}

//strstr 返回字符串在另外一个字符中第一次出现的位置

//int main()
//{
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "deq";
//	char* ret = strstr(arr1, arr2);
//	if (ret != NULL)
//		printf("%s\n", ret);
//	else
//		printf("找不到\n");
//
//	return 0;
//}

char* my_strstr(const char* str1, const char*str2)
{
	const char* cur = str1;
	const char* s1 = NULL;
	const char* s2 = NULL;

	assert(str1 && str2);
	if (*str2 == '\0')
	{
		return (char*)str1;
	}

	while (*cur)
	{
		s1 = cur;
		s2 = str2;
		while (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cur;
		}
		cur++;
	}
	return NULL;
}

int main()
{
	char arr1[] = "abbbcdef";
	char arr2[] = "bbq";
	char* ret = my_strstr(arr1, arr2);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		printf("找不到\n");

	return 0;
}




