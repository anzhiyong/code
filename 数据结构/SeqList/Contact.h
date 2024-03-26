#pragma once

#define NAME_MAX 100
#define SEX_MAX 10
#define ADDR_MAX 100
#define PHONE_MAX 12
//ͨѶ¼��������
typedef struct PersonoInfo {
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char phone[PHONE_MAX];

}Info;

//˳����ǰ������
struct SeqList;
typedef struct SeqList Contact;

//ͨѶ¼�ĳ�ʼ��������
void ContactInit(Contact* pcon);
void ContactDesTroy(Contact* pcon);

//ͨ��¼������ɾ���飬��  ,�鿴ͨѶ¼
void ContactAdd(Contact* pcon);
void ContactDel(Contact* pcon);
void ContactFind(Contact* pcon);
void ContactModify(Contact* pcon);
void ContactShow(Contact* pcon);


