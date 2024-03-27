#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void add(int a, int b)
{
	cout << "add1" << endl;
}
void add(char a, int b)
{
	cout << "add2" << endl;

}
void Swap(int& a, int& b)
{
	int tem = a;
	a = b;
	b = tem;
}
int main()
{
	add('s', 3);
	int a = 0;
	int x = 9;
	int& b = a;
	int& c = a;
	int& d = a;
	d++;
	Swap(a, x);
	cout << a << ':' << x << endl;
	return 0;
}

