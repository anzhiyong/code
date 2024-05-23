#include<iostream>

using namespace std;
#include<list>


void test_list1()
{
	int array[] = { 1,23,4,5,6,7,8,8, };
	list<int> l1(array, array + sizeof(array) / sizeof(int));
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
}

void test_list2()
{
	int array[] = { 1,23,4,5,6,7,8,8, };
	list<int> l1(array, array + sizeof(array) / sizeof(int));
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
	list<char> l2;
	cout << l2.empty() << endl;
}

void test_list3()
{
	int array[] = { 1,23,4,5,6,7,8,8, };
	list<int> l1(array, array + sizeof(array) / sizeof(int));
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
	list<char> l2;
	cout << l1.size() << endl;
}

void test_list4()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);

	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
	//l1.front() -= l1.back();
	cout << l1.front() << endl;
	cout << l1.back() << endl;
}

void test_list5()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.pop_back();
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << endl;
		it++;
	}
	l1.pop_back();
	cout << endl;
	it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << endl;
		it++;
	}
	l1.clear();
	it = l1.begin();
	while (it != l1.end())
	{
		cout << *it<< endl;
		it++;
	}
}
int main()
{
	test_list5();
	return 0;
}