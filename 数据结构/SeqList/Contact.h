#pragma once

#define NAME_MAX 100
#define SEX_MAX 10
#define ADDR_MAX 100
#define PHONE_MAX 12
//通讯录数据类型
typedef struct PersonoInfo {
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char phone[PHONE_MAX];

}Info;

//顺序表的前置声明
struct SeqList;
typedef struct SeqList Contact;

//通讯录的初始化和销毁
void ContactInit(Contact* pcon);
void ContactDesTroy(Contact* pcon);

//通信录的增，删，查，改  ,查看通讯录
void ContactAdd(Contact* pcon);
void ContactDel(Contact* pcon);
void ContactFind(Contact* pcon);
void ContactModify(Contact* pcon);
void ContactShow(Contact* pcon);


