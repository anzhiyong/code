#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<algorithm>

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


////左值 ， 右值
//int main()
//{
//	// 以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// 以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}
//
// 


//void Fun(int& i)
//{
//	cout << "左值引用" << endl;
//}
//
//void Fun(const int& i)
//{
//	cout << "左值引用" << endl;
//}
//
//void Fun(int&& i)
//{
//	cout << "右值引用" << endl;
//}
//
//void Fun(const int&& i)
//{
//	cout << "右值引用" << endl;
//}
//
//template <class T>
//void perfectForward(T&& t)
//{
//	Fun(forward<T>(t));//完美转发   forward<T>(t)
//}
//int main()
//{
//	
//	perfectForward(10);//右值引用
//
//	int a;
//	perfectForward(a);//左值引用
//
//	perfectForward(move(a)); // 右值
//
//	const int b  = 1;
//	perfectForward(b);  //左
//	perfectForward(move(b));  //右值
//	return 0;
//}


//template <class T>
//void Print(T t)
//{
//	cout << t << endl;
//}

//template <class value, class ...Args>
//void ShowList(value v, Args... args)
//{
//	cout << v << " ";
//	ShowList(args...);
//}

//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (Print(args), 0)... };
//}
//
//int main()
//{
//	//ShowList(4);
//	ShowList(string("sort"), "an", "dj");
//	return 0;
//}



//lambda 表达式
//书写格式：[capture-list] (parameters) mutable -> return-type { statement}

struct Goods
{
	string _name; // 名字
	double _price; // 价格
	int _evaluate; // 评价
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};


//通过仿函数更改比较规则
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
//	3 }, { "菠萝", 1.5, 4 } };
//
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << (*it)._name;
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//用lambda
//书写格式：[capture-list] (parameters) mutable -> return-type { statement}
//         捕捉列表         参数列表      取消常性    返回值类型    函数体

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
//	3 }, { "菠萝", 1.5, 4 } };
//
//	//降序
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->double
//		{
//			return  g1._price > g2._price;
//		});
//
//	//升序
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->double
//		{
//			return  g1._price < g2._price;
//		});
//
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << (*it)._name;
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}

#include<functional>
//int f(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	function<int(int, int)> func1 = f;
//	cout << func1(2, 4) << endl;  //函数指针
//
//	//函数对象
//	function<int(int, int)> func2 = Functor();
//	cout << func2(2, 9) << endl;
//
//	//lambda表达式
//	function<int(int, int)> func3 = [](const int a, const int b) {return a + b; };
//	cout << func3(10, 100) << endl;
//
//	//类成员函数
//	function<int(int, int)> func4 = &Plus::plusi;
//	cout << func4(99, 99) << endl;
//
//	//非静态还要传类
//	function<double(Plus, double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 3.14, 3.14) << endl;
//
//	return 0;
//}

int Plus(int a, int b)
{
	return a + b;
}
class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b;
	}
};

using namespace placeholders;
int main()
{
	function<int(int, int)> fun1 = bind(Plus, _1, _2);
	cout << fun1(2, 4) << endl;

	function<int(int, int)> fun2 = bind(Plus, 1, 2);
	cout << fun2(2, 4) << endl;  //绑死 1，2

	//成员函数
	function<int(int, int)> fun3 = bind(&Sub::sub,Sub(), _2, _1);
	cout << fun2(10, 5) << endl;
	return 0;
}
