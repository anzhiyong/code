#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
namespace an
{
	class string
	{
	public:
		typedef char* iterator;//模拟迭代器实现
		iterator begin();
		iterator end();
		string(const char* str);//有参构造
		~string();
		const char* c_str() const;//打印字符串内容
		size_t size() const;  //返回字符串长度
		char& operator[](size_t pos);//重载[]
	private:
		char* _str; //字符串指针
		int _size;  //长度
		int _capacity;//空间
		
	};
}
