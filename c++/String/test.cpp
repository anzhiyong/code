#include<iostream>
#include<algorithm>

using namespace std;


void test1_string()
{
	string str1("an");
	/*for (auto e = )
	{
		cout << e << endl;
	}*/
	string::iterator s = str1.begin();
	while (s != str1.end())
	{
		cout << *s << endl;
		++s;
	}

}

void test2_sort()
{
	string s1("hello world");
	cout << s1 << endl;
	sort(s1.begin(), s1.end());//°´×ÖµäÐòÅÅÐò
	cout << s1 << endl;
}
int main()
{
	//test1_string();
	test2_sort();
	return 0;
}