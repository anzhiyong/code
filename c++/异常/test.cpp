#include<iostream>
using namespace std;


double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	int* arr = new int[10];
	try
	{
		int a, b;
		cin >> a >> b;
		Division(a, b);
	}
	catch (const char* s)
	{
		delete[] arr;
		throw;


	}
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	catch (...)
	{
		cout << "�����쳣" << endl;
	}
	return 0;
}