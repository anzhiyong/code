#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	//打开data.txt文件
//	FILE* pr = fopen("永劫无间.mp4", "rb");
//	if (pr == NULL)
//	{
//		perror("文件打开错误！");
//		return 1;
//	}
//	//创建data_copy.txt文件
//	FILE* pw = fopen("永劫无间2.mp4", "wb");
//	if (pw == NULL)
//	{
//		perror("文件打开错误!!");
//		fclose(pr);
//		return 1;
//	}
//	int buff[1000] = {0};
//	size_t i = 0;
//	while ((i = fread(buff, sizeof(int), sizeof(buff)/sizeof(int), pr))>0)//拷贝文件内容
//	{
//		fwrite(buff, sizeof(int), i, pw);
//	}
//	fclose(pr);
//	fclose(pw);
//	pr = NULL;
//	pw = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}