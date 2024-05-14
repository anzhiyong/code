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
		typedef char* iterator;//模拟迭代器实现
		typedef const char* const_iterator;


		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;


		string(const char* str = " ");//有参构造
		string(const string& s);
		string& operator=(const string& s);
		~string();

		const char* c_str() const;//打印字符串内容

		size_t size() const;  //返回字符串长度
		char& operator[](size_t pos);//重载[]
		const char& operator[](size_t pos) const;

		void reserve(size_t n);

		void push_back(char ch);
		void append(const char* str);

		void operator+=(char ch);
		void operator+=(const char* str);


		void insert(size_t pos, const char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);

		size_t find(char ch, size_t npos = 0);
		size_t find(const char* str, size_t npos = 0);

		void swap(string& s);
		string substr(size_t pos = 0, size_t len = npos);        //截取字符串

		bool operator<(const string& s) const;
		bool operator>(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;

		void clear();

	private:
		char* _str; //字符串指针
		int _size;  //长度
		int _capacity;//空间

		const static size_t npos;
		
	};
	istream& operator>> (istream& is, string& str);
	ostream& operator<< (ostream& os, const string& str);
}
