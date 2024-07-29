#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<map>

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


//auto :自动推断类型
//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	return 0;
//}


// decltype的一些使用使用场景
//关键字decltype将变量的类型声明为表达式指定的类型。
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret的类型是double
//	decltype(&x) p; // p的类型是int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}


//左值 ， 右值
int main()
{
	// 以下的p、b、c、*p都是左值
	int* p = new int(0);
	int b = 1;
	const int c = 2;
	// 以下几个是对上面左值的左值引用
	int*& rp = p;
	int& rb = b;
	const int& rc = c;
	int& pvalue = *p;
	return 0;
}