#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
#include"Contact.h"


//通讯录的初始化和销毁
void ContactInit(Contact* pcon) {
	SLInit(pcon);
}
void ContactDesTroy(Contact* pcon) {
	SLDestroy(pcon);
}

//通信录的增，删，查，改  ,查看通讯录
void ContactAdd(Contact* pcon) {
	Info info;//创建一个联系人结构体变量
	printf("请输入姓名:\n");
	scanf("%s", info.name);
	printf("请输入年龄:\n");
	scanf("%d", &info.age);//注意取地址
	printf("请输入性别:\n");
	scanf("%s", info.sex);
	printf("请输入住址:\n");
	scanf("%s", info.addr);
	printf("请输入手机号:\n");
	scanf("%s", info.phone);

	//保存数据到通讯录
	SLPushBack(pcon, info);
}

//查找
int FindByName(Contact* pcon, char name[]) {
	for (int i = 0; i < pcon->size; i++) {
		if (strcmp(pcon->arr[i].name, name)==0) {
			return i;
		}
	}
	return -1;
}
void ContactDel(Contact* pcon) {
	//删除之前要先查找，找到了才能删除
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名：\n");
	scanf("%s", name);
	int ret = FindByName(pcon, name);
	if (ret < 0) {
		printf("要删除的联系人不存在！\n");
	}
	SLErase(pcon, ret);
	printf("删除成功！\n");
}
void ContactFind(Contact* pcon) {
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名：\n");
	scanf("%s", name);
	int ret = FindByName(pcon, name);
	if (ret < 0) {
		printf("要查找的联系人不存在！\n");
		return;
	}
	//找到了，打印联系人信息
	printf("%s %s %s %s %s\n", "姓名", "年龄", "性别", "家庭住址", "手机号");
	for (int i = 0; i < pcon->size; i++) {
		printf("%s %d %s %s %s\n",
			pcon->arr[i].name,
			pcon->arr[i].age,
			pcon->arr[i].sex,
			pcon->arr[i].addr,
			pcon->arr[i].phone);
	}
}
void ContactModify(Contact* pcon) {
	//修改之前要先查找
	//找到了，修改
	//没找到，不修改
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名：\n");
	scanf("%s", name);
	int ret = FindByName(pcon, name);
	if (ret < 0) {
		printf("要修改的联系人不存在！\n");
		return;
	}
	//修改
	printf("请输入姓名:\n");
	scanf("%s", pcon->arr[ret].name);
	printf("请输入年龄:\n");
	scanf("%d", &pcon->arr[ret].age);//取地址！！！
	printf("请输入性别:\n");
	scanf("%s", pcon->arr[ret].sex);
	printf("请输入住址:\n");
	scanf("%s", pcon->arr[ret].addr);
	printf("请输入手机号:\n");
	scanf("%s", pcon->arr[ret].phone);

	printf("联系人修改成功！\n");
}
void ContactShow(Contact* pcon) {
	printf("%s %s %s %s %s\n", "姓名", "年龄", "性别", "家庭住址", "手机号");
	for (int i = 0; i < pcon->size; i++) {
		printf("%s %d %s %s %s\n",
			pcon->arr[i].name,
			pcon->arr[i].age,
			pcon->arr[i].sex,
			pcon->arr[i].addr,
			pcon->arr[i].phone
		);
	}
}