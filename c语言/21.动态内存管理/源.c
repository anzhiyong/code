#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	return 0;
//}

//
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//int main()
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//
//}

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p != NULL) {
//		for (int i = 0; i < 10; i++) {
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p != NULL) {
//		for (int i = 0; i < 10; i++) {
//			*(p + i) = i;
//		}
//	}
//	else {
//		return 1;
//	}
//	int* str = (int*)realloc(p, 20 * sizeof(int));
//	if (str != NULL) {
//		p = str;
//	}
//	for (int i = 0; i < 20; i++) {
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 20; i++) {
//		*(p + i) = i;
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	return 0;
//}

//
int main()
{
	int** p = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++) {
		p[i] = (int*)malloc(5 * sizeof(int));
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			p[i][j] = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	//ÊÍ·Å
	for (int i = 0; i < 3; i++) {
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
	return 0;
}