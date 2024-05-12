#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace an
{
	class string
	{
	public:
		typedef char* iterator;//ģ�������ʵ��
		typedef const char* const_iterator;


		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;


		string(const char* str);//�вι���
		string(const string& s);
		~string();

		const char* c_str() const;//��ӡ�ַ�������

		size_t size() const;  //�����ַ�������
		char& operator[](size_t pos);//����[]

		void reserve(size_t n);

		void push_back(char ch);
		void append(const char* str);


		void insert(size_t pos, const char ch);
		void insert(size_t pos, const char* str);
	private:
		char* _str; //�ַ���ָ��
		int _size;  //����
		int _capacity;//�ռ�
		
	};
}
