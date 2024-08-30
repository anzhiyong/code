#pragma once

#include<iostream>
using namespace std;

#include<assert.h>
class Date
{

	// 友元函数声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	void Print()const;
	//取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		//四年一闰，百年不闰， 四百年再闰
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}
	bool CheckDate();

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	//d1 +=100;
	Date& operator+=(int day);
	Date operator+(int day);
	//d1 -=100;
	Date& operator-=(int day);
	//d1-100;
	Date operator-(int day) const;
	//d1-d2
	int operator-(const Date& d) const;

	//++d1-->> d1.operator++()
	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;



};

//重载
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);