#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Data
//{
//public:
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//���캯��
//	/*Data(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//
//int main()
//{
//	//Data d1(2024,4,2);
//	Data d2;//��������Ĭ�������޲ι��캯����һ����ʽ���幹�캯�����ᱨ��
//	//d1.Init(2024, 4, 2);
//	//d1.Print();
//	return 0;
//}


class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hours = 0;
		_minute = 0;
		_second = 0;
	}

private:
	int _hours;
	int _minute;
	int _second;
};

class Data
{
	

private:
	//�������ͣ��������ͣ�
	int _year = 1978;
	int _month = 2;
	int _day= 3;

	//�Զ�������
	Time _t;
};

int main()
{
	Data d1;
	return 0;
}