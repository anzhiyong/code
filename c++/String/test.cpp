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
		
		for (auto e : a)
		{
			cout << e;
		}
		cout << endl;

		//cout << a[2] << endl;
		string s1("anzhiyong");
		s1.erase(1, 2);
		for (auto e : s1)
		{
			cout << e;
		}
		cout << endl;

		string s2("anzhiyong");
		cout << s2.find("zhi");
		/*for (auto e : s2)
		{
			cout << e;
		}*/
		cout << endl;
	}

	void test_string2()
	{
		string s1("anz");
		s1 += "hiyong";
		s1 += 'x';
		string::const_iterator i = s1.begin();
		while ( i !=s1.end())
		{
			cout << *i;
			i++;
		}
	}

	void test_string3()
	{
		string s1("anzhiyong");
		
		string s = s1.substr(2, 3);
		string::const_iterator i = s.begin();
		while (i != s.end())
		{
			cout << *i;
			i++;
		}
		
	}

	void test_string4()
	{
		string s1("anzhiyong");
		string s2("aljajka");
		cout << s1 << endl;
		s1 = s2;
		cout << s1 << endl;

	}
	void test_string5()
	{
		string s1("anzhiyong");
		string s2(s1);
		//cout << s1 << endl;
		//s1 = s2;
		string s3;
		s3 = s1;
		cout << s3 << endl;
		

	}
}

int main()
{
	an::test_string5();
	return 0;
}