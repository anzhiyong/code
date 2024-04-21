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
			perror("malloc����ռ�ʧ��!!!");
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

	// ��������...
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
//	// Stack���߱�Ĭ�Ϲ��졣MyQueueҲ�޷�����Ĭ�Ϲ���
//	// ��ʼ���б�
//	// ��ʼ���б��ʿ������Ϊÿ�������г�Ա����ĵط�
//	// ���еĳ�Ա��������ڳ�ʼ���б��ʼ����Ҳ�����ں������ڳ�ʼ��
//	// 1������ 2��const 3��û��Ĭ�Ϲ����Զ������ͳ�Ա(������ʾ���ε�����)
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
//	// ����
//	Stack _pushst;
//	Stack _popst;
//	int _size;
//
//	// �����ڶ���ʱ��ʼ��
//	const int _x;
//
//	// �����ڶ���ʱ��ʼ��
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
	// ��ʼ���б�������д��д��ÿ����Ա������������һ��
	// �Զ������͵ĳ�Ա�����Ĭ�Ϲ��죨û��Ĭ�Ϲ���ͱ��뱨��
	// ����������ȱʡֵ��ȱʡֵ��û�еĻ�����ȷ����Ҫ�����������еı������ᴦ���еĲ��ᴦ��
	// ���߳�ʼ���б� + ���ߺ�����
	// ʵ���У�������ʹ�ó�ʼ���б��ʼ������������ʹ�ú������ʼ��
	MyQueue()
		:_size(1)
		, _ptr((int*)malloc(40))
	{
		memset(_ptr, 0, 40);
	}

private:
	// ����
	Stack _pushst;
	Stack _popst;

	// ȱʡֵ  ����ʼ���б��õ�
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
//	// ���������캯��
//	//explicit A(int a)
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	// ��������캯��
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
////	// ��������
////	A aa2 = aa1;
////
////	// ��ʽ����ת��
////	// ��������ת��Ϊ�Զ�������
////	// 3����һ��A����ʱ�������������ʱ���󿽱�����aa3
////	// ������������������+��������->�Ż�Ϊֱ�ӹ���
////	A aa3 = 3;
////
////	// raa ���õ�������ת������3�������ʱ���� 
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
//	// ������ȱʡֵ
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
//	// 21��15
//	// û��thisָ�룬ֻ�ܷ��ʾ�̬��Ա
//	static int GetCount()
//	{
//		//_a1 = 1;
//
//		return _scount;
//	}
//
//private:
//	// ����
//	int _a1 = 1;
//	int _a2 = 1;
//
//// public:
//	// ����
//	// ��̬���������ڶ�����
//	// ���ܸ�ȱʡֵ����Ϊȱʡֵ�Ǹ���ʼ���б�
//	// ���ھ�̬�����ڶ����У����߳�ʼ���б�
//	// �������������࣬�������ж���
//	static int _scount;
//};
//
//// ����
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
//	// ���� Date��Time����Ԫ
//	// Date�п��Է���Time��˽��
//	// ����Time�в��ܷ���Date��˽��
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
	// �ڲ���
	// �������࣬�ŵ�A����
	// �����ܵ���������
	class B // B��������A����Ԫ
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