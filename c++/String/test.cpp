//#include<iostream>
//#include<algorithm>
//
//using namespace std;


//void test1_string()
//{
//	string str1("an");
//	/*for (auto e = )
//	{
//		cout << e << endl;
//	}*/
//	string::iterator s = str1.begin();
//	while (s != str1.end())
//	{
//		cout << *s << endl;
//		++s;
//	}
//
//}
//
//void test2_sort()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//	sort(s1.begin(), s1.end());//按字典序排序
//	cout << s1 << endl;
//}
//
//
//void test_string()
//{
//	string st2("azjoi");
//	string::iterator i = st2.end();//end是最后一个有效元素的下一个
//	for (auto e : st2)
//	{
//		i--;
//		cout << *i << endl;
//		
//	}
//	
//}
//void test_rbegin()
//{
//	string str("anzhiyong");
//	string::reverse_iterator rit = str.rbegin();
//	for (auto e : str)
//	{
//		cout << *rit << endl;
//		rit++;
//	}
//}
//int main()
//{
//	//test1_string();
//	//test2_sort();
//	/*string s1("111111");
//	string s2("11111111111111111111111111111111111111111111111111111");*/
//	//test_string();
//	test_rbegin();
//
//	return 0;
//}


#include"String.h"

namespace an
{
	void test_string1()
	{
		string a("anzhiyong");
		string s1(a);
		string::iterator i = a.begin();
		/*for (auto e : a)
		{
			cout << e;
		}
		cout << endl;*/
		/*a.push_back('x');
		for (auto e : a)
		{
			cout << e;
		}*/
		//a.append("最厉害");
		a.insert(1,"xxx");
		for (auto e : a)
		{
			cout << e;
		}
		cout << endl;

		//cout << a[2] << endl;
	}
}

int main()
{
	an::test_string1();
	return 0;
}