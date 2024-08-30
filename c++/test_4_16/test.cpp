#include<iostream>
using namespace std;

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 4)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	// 其他方法...
	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	DataType* _array;
	int _capacity;
	int _size;
};
//class MyQueue
//{
//public:
//	// Stack不具备默认构造。MyQueue也无法生成默认构造
//	// 初始化列表
//	// 初始化列表本质可以理解为每个对象中成员定义的地方
//	// 所有的成员，你可以在初始化列表初始化，也可以在函数体内初始化
//	// 1、引用 2、const 3、没有默认构造自定义类型成员(必须显示传参调构造)
//	MyQueue(int n, int& rr)
//		:_pushst(n)
//		,_popst(n)
//		,_x(1)
//		,_ref(rr)
//	{
//		_size = 0;
//		//_x = 1;
//	}
//
//private:
//	// 声明
//	Stack _pushst;
//	Stack _popst;
//	int _size;
//
//	// 必须在定义时初始化
//	const int _x;
//
//	// 必须在定义时初始化
//	int& _ref;
//};
//int main()
//{
//	int xx = 0;
//	MyQueue q1(10, xx);
//	//MyQueue q2;
//
//	const int y = 1;
//
//	int& ry = xx;
//
//
//	return 0;
//}
// 
class MyQueue
{
public:
	// 初始化列表，不管你写不写，每个成员变量都会先走一遍
	// 自定义类型的成员会调用默认构造（没有默认构造就编译报错）
	// 内置类型有缺省值用缺省值，没有的话，不确定，要看编译器，有的编译器会处理，有的不会处理
	// 先走初始化列表 + 再走函数体
	// 实践中：尽可能使用初始化列表初始化，不方便再使用函数体初始化
	MyQueue()
		:_size(1)
		, _ptr((int*)malloc(40))
	{
		memset(_ptr, 0, 40);
	}

private:
	// 声明
	Stack _pushst;
	Stack _popst;

	// 缺省值  给初始化列表用的
	int _size = 0;
	const int _x = 10;

	int* _ptr;
};

//int main()
//{
//	MyQueue q;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() 
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() 
//{
//	A aa(1);
//	aa.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	// 单参数构造函数
//	//explicit A(int a)
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	// 多参数构造函数
//	A(int a1, int a2)
//		:_a(0)
//		,_a1(a1)
//		,_a2(a2)
//	{}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//	int _a1;
//	int _a2;
//};
//
////int main()
////{
////	A aa1(1);
////	// 拷贝构造
////	A aa2 = aa1;
////
////	// 隐式类型转换
////	// 内置类型转换为自定义类型
////	// 3构造一个A的临时对象，在用这个临时对象拷贝构造aa3
////	// 编译器遇到连续构造+拷贝构造->优化为直接构造
////	A aa3 = 3;
////
////	// raa 引用的是类型转换中用3构造的临时对象 
////	const A& raa = 3;
////
////	
////	A aaa1(1, 2);
////	A aaa2 = { 1, 2 };
////	const A& aaa3 = { 1, 2 };
////
////	return 0;
////}
//
//class Stack
//{
//public:
//	void Push(const A& aa)
//	{
//		//...
//	}
//
//	//...
//};
//
////class string
////{
////public:
////	string(const char* str)
////	{}
////};
//
//int main()
//{
//	Stack st;
//
//	A a1(1);
//	st.Push(a1);
//
//	A a2(2);
//	st.Push(a2);
//
//	st.Push(2);
//	st.Push(4);
//
//	A aa1(1, 2);
//	st.Push(aa1);
//
//	st.Push({ 1,2 });
//
//	list<string> lt;
//	string s1("111");
//	lt.push_back(s1);
//
//	lt.push_back("1111");
//
//	return 0;
//}

//////////////////////////////////////////////////////////
// 

//class BB
//{
//public:
//	BB()
//	{
//
//	}
//
//private:
//	// 声明给缺省值
//	int _b1 = 1;
//	int* _ptr = (int*)malloc(40);
//	Stack _pushst = 10;
//	A _a1 = 1;
//	A _a2 = { 1,2 };
//	A _a3 = _a2;
//};
//
//int main()
//{
//
//	BB bb;
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	A() 
//	{ 
//		++_scount;
//	}
//
//	A(const A & t) 
//	{ 
//		//GetCount();
//
//		++_scount;
//	}
//
//	~A()
//	{ 
//		//--_scount;
//	}
//	
//	// 21：15
//	// 没有this指针，只能访问静态成员
//	static int GetCount()
//	{
//		//_a1 = 1;
//
//		return _scount;
//	}
//
//private:
//	// 声明
//	int _a1 = 1;
//	int _a2 = 1;
//
//// public:
//	// 声明
//	// 静态区，不存在对象中
//	// 不能给缺省值，因为缺省值是给初始化列表
//	// 他在静态区不在对象中，不走初始化列表
//	// 属于所有整个类，属于所有对象
//	static int _scount;
//};
//
//// 定义
//int A::_scount = 0;
//
//A func()
//{
//	A aa4;
//	return aa4;
//}
//
//int main()
//{
//	A aa1;
//	cout << sizeof(aa1) << endl;
//
//	A aa2;
//	A aa3(aa1);
//
//	func();
//
//	//aa1._scount++;
//	//cout << A::_scount << endl;
//	cout << A::GetCount() << endl;
//
//	return 0;
//}

//class Time
//{
//	// 声明 Date是Time的友元
//	// Date中可以访问Time的私有
//	// 但是Time中不能访问Date的私有
//	friend class Date;
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour++;
//	}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};

class A
{
private:
	static int k;
	int h;
public:
	void func()
	{}
private:
	// 内部类
	// 独立的类，放到A里面
	// 仅仅受到类域限制
	class B // B天生就是A的友元
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}

	private:
		int _b;
	};
};


int main()
{
	cout << sizeof(A) << endl;

	A a1;
	//A::B b1;

	return 0;
}