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
//	//ͳһ���б��ʼ��
//	int arry1[] = { 2,54,3,2,3,52,34,2,4,43 };  //  {}
//	int arry2[10]{ 2,54,3,2,3,52,34,2,4,43 };  //����ʡ��  =
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
//	// C++11֧�ֵ��б��ʼ�����������ù��캯����ʼ��
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}


//initializer_list  ��ʲô���ͣ�
//int main()
//{
//	// the type of il is an initializer_list
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}


//auto :�Զ��ƶ�����
//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	return 0;
//}


// decltype��һЩʹ��ʹ�ó���
//�ؼ���decltype����������������Ϊ���ʽָ�������͡�
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
//	decltype(x * y) ret; // ret��������double
//	decltype(&x) p; // p��������int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}


////��ֵ �� ��ֵ
//int main()
//{
//	// ���µ�p��b��c��*p������ֵ
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// ���¼����Ƕ�������ֵ����ֵ����
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
//	cout << "��ֵ����" << endl;
//}
//
//void Fun(const int& i)
//{
//	cout << "��ֵ����" << endl;
//}
//
//void Fun(int&& i)
//{
//	cout << "��ֵ����" << endl;
//}
//
//void Fun(const int&& i)
//{
//	cout << "��ֵ����" << endl;
//}
//
//template <class T>
//void perfectForward(T&& t)
//{
//	Fun(forward<T>(t));//����ת��   forward<T>(t)
//}
//int main()
//{
//	
//	perfectForward(10);//��ֵ����
//
//	int a;
//	perfectForward(a);//��ֵ����
//
//	perfectForward(move(a)); // ��ֵ
//
//	const int b  = 1;
//	perfectForward(b);  //��
//	perfectForward(move(b));  //��ֵ
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



//lambda ���ʽ
//��д��ʽ��[capture-list] (parameters) mutable -> return-type { statement}

struct Goods
{
	string _name; // ����
	double _price; // �۸�
	int _evaluate; // ����
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


//ͨ���º������ıȽϹ���
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,
//	3 }, { "����", 1.5, 4 } };
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

//��lambda
//��д��ʽ��[capture-list] (parameters) mutable -> return-type { statement}
//         ��׽�б�         �����б�      ȡ������    ����ֵ����    ������

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,
//	3 }, { "����", 1.5, 4 } };
//
//	//����
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->double
//		{
//			return  g1._price > g2._price;
//		});
//
//	//����
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
//	cout << func1(2, 4) << endl;  //����ָ��
//
//	//��������
//	function<int(int, int)> func2 = Functor();
//	cout << func2(2, 9) << endl;
//
//	//lambda���ʽ
//	function<int(int, int)> func3 = [](const int a, const int b) {return a + b; };
//	cout << func3(10, 100) << endl;
//
//	//���Ա����
//	function<int(int, int)> func4 = &Plus::plusi;
//	cout << func4(99, 99) << endl;
//
//	//�Ǿ�̬��Ҫ����
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
	cout << fun2(2, 4) << endl;  //���� 1��2

	//��Ա����
	function<int(int, int)> fun3 = bind(&Sub::sub,Sub(), _2, _1);
	cout << fun2(10, 5) << endl;
	return 0;
}
