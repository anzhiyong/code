#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
namespace an
{
	class string
	{
	public:
		typedef char* iterator;//ģ�������ʵ��
		iterator begin();
		iterator end();
		string(const char* str);//�вι���
		~string();
		const char* c_str() const;//��ӡ�ַ�������
		size_t size() const;  //�����ַ�������
		char& operator[](size_t pos);//����[]
	private:
		char* _str; //�ַ���ָ��
		int _size;  //����
		int _capacity;//�ռ�
		
	};
}
