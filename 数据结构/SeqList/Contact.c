#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
#include"Contact.h"


//ͨѶ¼�ĳ�ʼ��������
void ContactInit(Contact* pcon) {
	SLInit(pcon);
}
void ContactDesTroy(Contact* pcon) {
	SLDestroy(pcon);
}

//ͨ��¼������ɾ���飬��  ,�鿴ͨѶ¼
void ContactAdd(Contact* pcon) {
	Info info;//����һ����ϵ�˽ṹ�����
	printf("����������:\n");
	scanf("%s", info.name);
	printf("����������:\n");
	scanf("%d", &info.age);//ע��ȡ��ַ
	printf("�������Ա�:\n");
	scanf("%s", info.sex);
	printf("������סַ:\n");
	scanf("%s", info.addr);
	printf("�������ֻ���:\n");
	scanf("%s", info.phone);

	//�������ݵ�ͨѶ¼
	SLPushBack(pcon, info);
}

//����
int FindByName(Contact* pcon, char name[]) {
	for (int i = 0; i < pcon->size; i++) {
		if (strcmp(pcon->arr[i].name, name)==0) {
			return i;
		}
	}
	return -1;
}
void ContactDel(Contact* pcon) {
	//ɾ��֮ǰҪ�Ȳ��ң��ҵ��˲���ɾ��
	char name[NAME_MAX];
	printf("������Ҫɾ������ϵ��������\n");
	scanf("%s", name);
	int ret = FindByName(pcon, name);
	if (ret < 0) {
		printf("Ҫɾ������ϵ�˲����ڣ�\n");
	}
	SLErase(pcon, ret);
	printf("ɾ���ɹ���\n");
}
void ContactFind(Contact* pcon) {
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ��������\n");
	scanf("%s", name);
	int ret = FindByName(pcon, name);
	if (ret < 0) {
		printf("Ҫ���ҵ���ϵ�˲����ڣ�\n");
		return;
	}
	//�ҵ��ˣ���ӡ��ϵ����Ϣ
	printf("%s %s %s %s %s\n", "����", "����", "�Ա�", "��ͥסַ", "�ֻ���");
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
	//�޸�֮ǰҪ�Ȳ���
	//�ҵ��ˣ��޸�
	//û�ҵ������޸�
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ��������\n");
	scanf("%s", name);
	int ret = FindByName(pcon, name);
	if (ret < 0) {
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�\n");
		return;
	}
	//�޸�
	printf("����������:\n");
	scanf("%s", pcon->arr[ret].name);
	printf("����������:\n");
	scanf("%d", &pcon->arr[ret].age);//ȡ��ַ������
	printf("�������Ա�:\n");
	scanf("%s", pcon->arr[ret].sex);
	printf("������סַ:\n");
	scanf("%s", pcon->arr[ret].addr);
	printf("�������ֻ���:\n");
	scanf("%s", pcon->arr[ret].phone);

	printf("��ϵ���޸ĳɹ���\n");
}
void ContactShow(Contact* pcon) {
	printf("%s %s %s %s %s\n", "����", "����", "�Ա�", "��ͥסַ", "�ֻ���");
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