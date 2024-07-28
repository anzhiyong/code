#include<iostream>
using namespace std;

//struct Point
//{
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	//统一的列表初始化
//	int arry1[] = { 2,54,3,2,3,52,34,2,4,43 };  //  {}
//	int arry2[10]{ 2,54,3,2,3,52,34,2,4,43 };  //可以省略  =
//	Point p{ 2,4 };
//	Point pi = { 4,8 };
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2022, 1, 1); // old style
//	// C++11支持的列表初始化，这里会调用构造函数初始化
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}


//initializer_list  是什么类型？
//int main()
//{
//	// the type of il is an initializer_list
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}