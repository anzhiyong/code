#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	//��data.txt�ļ�
//	FILE* pr = fopen("�����޼�.mp4", "rb");
//	if (pr == NULL)
//	{
//		perror("�ļ��򿪴���");
//		return 1;
//	}
//	//����data_copy.txt�ļ�
//	FILE* pw = fopen("�����޼�2.mp4", "wb");
//	if (pw == NULL)
//	{
//		perror("�ļ��򿪴���!!");
//		fclose(pr);
//		return 1;
//	}
//	int buff[1000] = {0};
//	size_t i = 0;
//	while ((i = fread(buff, sizeof(int), sizeof(buff)/sizeof(int), pr))>0)//�����ļ�����
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