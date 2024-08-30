#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 

#define LEN sizeof(struct student) /*student结构体所占字节数*/
#define FORMAT "%d	%s	%.2lf	%.2lf	%.2lf	%.2lf\n" /*设置显示格式*/
#define DATA stu[i].num,stu[i].name,stu[i].c,stu[i].m,stu[i].e,stu[i].sum /*设置显示内容*/
#define N 40 /*符号常量：班级人数*/
float Fc,Fm,Fe;/*全局变量：C语言成绩,高数成绩，英语成绩*/
struct student/*定义学生成绩结构体*/
{ 
	int num;/*学号*/
	char name[15];/*姓名*/
	double c;/*C语言课程成绩*/
	double m;/*高数课程成绩*/
	double e;/*英语课程成绩*/
	double sum;/*总分*/
} stu[N];/*定义结构体数组*/

void in();/*录入学生成绩信息*/
void show();/*显示学生信息*/
void order();/*按总分排序*/
void del();/*删除学生成绩信息*/
void modify();/*修改学生成绩信息*/
void menu();/*主菜单*/
void total();/*计算总人数*/
void search();/*查找学生信息*/

void menu()/*自定义函数实现菜单功能*/
{
	system("cls");/*清屏函数*/
	printf("\n\n\n\n\n");
	printf("\t\t|----------------学生成绩管理系统---------------|\n");
	printf("\t\t|\t 1. 录入学生成绩信息                    |\n");
	printf("\t\t|\t 2. 查询学生成绩信息                    |\n");
	printf("\t\t|\t 3. 删除学生成绩信息                    |\n");
	printf("\t\t|\t 4. 修改学生成绩信息                    |\n");
	printf("\t\t|\t 5. 学生成绩排序                        |\n");
	printf("\t\t|\t 6. 统计信息数量                        |\n");
	printf("\t\t|\t 0. 退出                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
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
		   case 4: modify();break;
		   case 5:order();break;
		   case 6:total();break;
		default:break;  }
		menu();/*执行完功能再次显示菜单界面*/
		scanf("%d",&n);   }
	}
void in()/*自定义函数实现录入学生成绩信息*/
{ 	int i,m=0;/*m是记录的条数*/
	char ch[2];
	FILE *fp;/*定义文件指针*/
	if((fp=fopen("data","a+"))==NULL)/*打开指定文件*/
	{ 
		printf("系统出错，请与开发人员联系！\n");
		return;
	}
	while(!feof(fp)) 
	{ 
		if(fread(&stu[m] ,LEN,1,fp)==1)
			m++;/*统计当前记录条数*/
	}
	fclose(fp);
	if(m==0) 
		printf("无学生成绩记录!\n");
	else 
	{
		system("cls");
		show();/*调用show函数，显示原有信息*/
	}
	if((fp=fopen("data","a+"))==NULL)
	{ 
		printf("系统出错，请与开发人员联系！\n");
		return;
	}
	printf("是否录入学生成绩，请按(y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要录入新信息*/
	{
		printf("请输入学生学号:");
		scanf("%d",&stu[m].num);/*输入学生学号*/
		for(i=0;i<m;i++)
			if(stu[i].num==stu[m].num)
			{
				printf("您输入的学号已经存在!");
				getch();
				fclose(fp);				
				return;
			}
			printf("请输入学生姓名:");
			scanf("%s",stu[m].name);/*输入学生姓名*/
			printf("C语言:");
			scanf("%lf",&stu[m].c);/*输入C语言成绩*/
			printf("高数:");
			scanf("%lf",&stu[m].m);/*输入高数成绩*/
			printf("英语:");
			scanf("%lf",&stu[m].e);/*输入英语成绩*/
			stu[m].sum=stu[m].c+stu[m].m+stu[m].e;/*计算出总成绩*/
			if(fwrite(&stu[m],LEN,1,fp)!=1)/*将新录入的信息写入指定的磁盘文件*/
			{
				printf("不能保存，请与开发人员联系!");  
			}
			else
			{ 
				printf("%s成绩录入成功!\n",stu[m].name);
				m++;
			}
			printf("是否继续录入?(y/n):");/*询问是否继续*/
			scanf("%s",ch);
	}
	fclose(fp);
	
}
void show()/*自定义函数实现显示学生成绩信息*/
{
	FILE *fp;
	int i,m=0;
	fp=fopen("data","r");
	while(!feof(fp))
	{
		if(fread(&stu[m] ,LEN,1,fp)==1) 
			m++;
	}  
	fclose(fp);
	printf("学号	姓名	C语言	高数	英语	总分\t\n");
	for(i=0;i<m;i++)
	{ 
		printf(FORMAT,DATA);/*将信息按指定格式打印*/
	}
}
void search()/*自定义函数实现学生成绩信息查询*/
{ 
	FILE *fp;
	int snum,i,m=0;
	char ch[2];
	if((fp=fopen("data","r"))==NULL)
	{ printf("系统出错，请与开发人员联系！\n");
		return; 	}
	while(!feof(fp)) 
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0)
		{   printf("无记录!\n");
			getch();
			return; 
		}
		printf("请输入您要查询的学号:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num)/*查找输入的学号是否在记录中*/
			{ 
				printf("查询成功,是否显示?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
				{ printf("学号	姓名	C语言	高数	英语	总分\t\n");
					printf(FORMAT,DATA);/*将查找出的结果按指定格式输出*/
					getch();
					break; 	}
				else
					return;
			}   
			if(i==m) 
				printf("未找到您要查询的学生信息!\n");/*未找到要查找的信息*/
	}
void del()/*自定义函数实现学生成绩信息删除*/
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
			if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要进行删除*/
			{
				for(j=i;j<m;j++)
					stu[j]=stu[j+1];/*将后一个记录移到前一个记录的位置*/
					m--;/*记录的总个数减1*/
					printf("删除成功!\n");
					getch();
				}
				if((fp=fopen("data","w"))==NULL)
				{ 
					printf("系统出错，请与开发人员联系！\n");
					return;
				}
				for(j=0;j<m;j++)/*将更改后的记录重新写入指定的磁盘文件中*/
					if(fwrite(&stu[j] ,LEN,1,fp)!=1)
					{   printf("更新失败，请与开发人员联系!\n"); 	}
					fclose(fp);
}
void modify()/*自定义函数实现学生成绩信息修改*/
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
			if(snum==stu[i].num)/*检索记录中是否有要修改的信息*/
				break;
			if(i<m)
			{	
				printf("姓名:\n");
				scanf("%s",stu[i].name);/*输入名字*/
				printf("\nC语言成绩:");
				scanf("%lf",&stu[i].c);/*输入C语言程序设计成绩*/
				printf("\n高数:");
				scanf("%lf",&stu[i].m);/*输入高等数学成绩*/
				printf("\n英语:");
				scanf("%lf",&stu[i].e);/*输入英语成绩*/
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
			for(j=0;j<m;j++)/*将新修改的信息写入指定的磁盘文件中*/
				if(fwrite(&stu[j] ,LEN,1,fp)!=1)
				{   printf("更新失败，请与开发人员联系!");   }
					fclose(fp);
}
void order()/*自定义函数实现学生成绩排序*/
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
			for(j=i+1;j<m;j++)/*双重循环实现成绩比较并交换*/
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
				for(i=0;i<m;i++)/*将重新排好序的内容重新写入指定的磁盘文件中*/
					if(fwrite(&stu[i] ,LEN,1,fp)!=1)
					{ 
						printf("更新失败，请与开发人员联系！\n"); 
					}
					fclose(fp);
					show();
					getch();
}
void total()/*自定义函数实现本系统信息数量统计*/
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
			m++;/*统计记录个数即学生个数*/
		if(m==0)
		{
			printf("无记录!\n");
			fclose(fp);
			return;
		}
		printf("本系统有%d条记录!\n",m);/*将统计的个数输出*/
		getch();
		fclose(fp);
}

 
