#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

namespace an
{
	int i = 2000;
	int a = 100;
}
using namespace an;
int main()
{
	//int i = 0;
	int a = 0;
	double d = 3.454;
	cout << i << ' ' << d << endl;
	cin >> d >> a;
	cout << d << ' ' << a << endl;
	return 0;
}