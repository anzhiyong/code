#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 

#define N 40
#define LEN sizeof(struct student) 
#define FORMAT "%d	%s	%.2lf	%.2lf	%.2lf	%.2lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].c,stu[i].m,stu[i].e,stu[i].sum 

float Fc,Fm,Fe;
struct student
{
	int num;
	char name[15];
	double c;
	double m;
	double e;
	double sum;

}stu[N];//定义结构体数组

void in();//录入功能 
void show();//显示学生成绩信息 
void search();//查找功能 
void del();//删除功能 
void change();//修改功能
void order();//排序功能
void count();//统计功能
void menu()
{
	printf("\n\n\n\n");
	printf("\t\t|-------------学生成绩管理系统---------------------|\n");
	printf("\t\t|\t 1.录入学生成绩信息                      |\n");
	printf("\t\t|\t 2.查询学生成绩信息                      |\n");
	printf("\t\t|\t 3.删除学生成绩信息                      |\n");
	printf("\t\t|\t 4.修改学生成绩信息                      |\n");
	printf("\t\t|\t 5.学生成绩排序                          |\n");
	printf("\t\t|\t 6.统计信息数量                          |\n");
	printf("\t\t|\t 0.退出                                  |\n");
	printf("\t\t\t请选择(0-6):");
}
void main()/*主函数*/
{ 
	int n;
	menu();
	scanf("%d",&n);/*输入选择功能的编号*/
	while(n)
	{ 
		switch(n)
		{  case 1: in();break;
		   case 2: search();break;
		   case 3: del();break;
		   case 4: change();break;
		   case 5:order();break;
		   case 6:count();break;
		   default:break;  
		}
		menu();
		scanf("%d",&n);  
	}
}

void in()
{ 	int i,m=0;
	char ch[2];
	FILE *fp;
	if((fp=fopen("data","a+"))==NULL)
	{ 
		printf("系统出错，请与开发人员联系！\n");
		return;
	}
	while(!feof(fp)) 
	{ 
		if(fread(&stu[m] ,LEN,1,fp)==1)
			m++;
	}
	fclose(fp);
	if(m==0) 
		printf("无学生成绩记录!\n");
	else 
	{
		system("cls");
		show();
	}
	if((fp=fopen("data","a+"))==NULL)
	{ 
		printf("系统出错，请与开发人员联系！\n");
		return;
	}
	printf("是否录入学生成绩，请按(y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
	{
		printf("请输入学生学号:");
		scanf("%d",&stu[m].num);
		for(i=0;i<m;i++)
			if(stu[i].num==stu[m].num)
			{
				printf("您输入的学号已经存在!");
				getch();
				fclose(fp);				
				return;
			}
			printf("请输入学生姓名:");
			scanf("%s",stu[m].name);
			printf("C语言:");
			scanf("%lf",&stu[m].c);
			printf("高数:");
			scanf("%lf",&stu[m].m);
			printf("英语:");
			scanf("%lf",&stu[m].e);
			stu[m].sum=stu[m].c+stu[m].m+stu[m].e;
			if(fwrite(&stu[m],LEN,1,fp)!=1)
			{
				printf("不能保存，请与开发人员联系!");  
			}
			else
			{ 
				printf("%s成绩录入成功!\n",stu[m].name);
				m++;
			}
			printf("是否继续录入?(y/n):");
			scanf("%s",ch);
	}
	fclose(fp);
	
}
void show()
{
	FILE* fp;
	int i,m=0;
	fp=fopen("data","r");
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp))
		{
			m++;
		}
	}
	fclose(fp);
	printf("学号	姓名	C语言	高数	英语	总分\t\n");
	for(i=0;i<m;i++)
	{
		printf(FORMAT,DATA);
	}
}
void search()
{
	FILE* fp;
	int snum,i,m=0;
	char ch[2];
	if((fp=fopen("data","r"))==NULL)
	{
		printf("打开失败，请联系管理员");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp))
		{
			m++;
		}
	}
	fclose(fp);
	if(m==0)
	{   
		printf("无记录!\n");
		getch();
		return; 
	}
	printf("请输入您要查询的学号:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num)
			{ 
				printf("查询成功,是否显示?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
				{ printf("学号	姓名	C语言	高数	英语	总分\t\n");
					printf(FORMAT,DATA);
					getch();
					break; 	}
				else
					return;
			}   
			if(i==m) 
				printf("未找到您要查询的学生信息!\n");
}
 
void del()
{
	FILE *fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("data","a+"))==NULL)
	{   printf("系统出错，请与开发人员联系！\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0) 
		{   printf("无记录!\n");
			return; 	}
		printf("请输入您要删除的学号:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num)
				break;
		 if(i==m)
			{   printf("对不起，没有您要删除的学生信息！");
			    return; 
}
			printf("确定删除?(y/n)");
			scanf("%s",ch);
			if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
			{
				for(j=i;j<m;j++)
					stu[j]=stu[j+1];
					m--;
					printf("删除成功!\n");
					getch();
				}
				if((fp=fopen("data","w"))==NULL)
				{ 
					printf("系统出错，请与开发人员联系！\n");
					return;
				}
				for(j=0;j<m;j++)
					if(fwrite(&stu[j] ,LEN,1,fp)!=1)
					{   printf("更新失败，请与开发人员联系!\n"); 	}
					fclose(fp);
}
void change()
{ 
	FILE *fp;
	int i,j,m=0,snum;
	if((fp=fopen("data","a+"))==NULL)
	{   printf("系统出错，请与开发人员联系！\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		if(m==0)
		{   printf("无记录!\n");
			fclose(fp);
			return;	
		}
		printf("请输入您要修改的学生学号:\n");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num)
				break;
			if(i<m)
			{	
				printf("姓名:\n");
				scanf("%s",stu[i].name);
				printf("\nC语言成绩:");
				scanf("%lf",&stu[i].c);
				printf("\n高数:");
				scanf("%lf",&stu[i].m);
				printf("\n英语:");
				scanf("%lf",&stu[i].e);
				stu[i].sum=stu[i].c+stu[i].m+stu[i].e;
			}
			else 
			{   printf("没有您要修改的学生信息!");
				return;
			}
			if((fp=fopen("data","w"))==NULL)
			{   printf("系统出错，请与开发人员联系！\n");
				return;
			}
			for(j=0;j<m;j++)
				if(fwrite(&stu[j] ,LEN,1,fp)!=1)
				{   printf("更新失败，请与开发人员联系!");   }
					fclose(fp);
}
void order()
{ 
	FILE *fp;
	struct student t;
	int i=0,j=0,m=0;
	if((fp=fopen("data","a+"))==NULL)
	{ 
		printf("系统出错，请与开发人员联系！\n");
		return;
	}
	while(!feof(fp)) 
		if(fread(&stu[m] ,LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0) 
		{
			printf("无记录!\n");
			return;
		}
		for(i=0;i<m-1;i++)
			for(j=i+1;j<m;j++)
				if(stu[i].sum<stu[j].sum)
				{ 
					t=stu[i];
					stu[i]=stu[j];
					stu[j]=t;
				}
				if((fp=fopen("data","w"))==NULL)
				{ 
					printf("系统出错，请与开发人员联系！\n");
					getch();
					return;
				}
				for(i=0;i<m;i++)
					if(fwrite(&stu[i] ,LEN,1,fp)!=1)
					{ 
						printf("更新失败，请与开发人员联系！\n"); 
					}
					fclose(fp);
					show();
					getch();
}
void count()
{ 
	FILE *fp;
	int m=0;
	if((fp=fopen("data","r"))==NULL)
	{         
		printf("系统出错，请与开发人员联系！\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		if(m==0)
		{
			printf("无记录!\n");
			fclose(fp);
			return;
		}
		printf("本系统有%d条记录!\n",m);
		getch();
		fclose(fp);
}

 


 