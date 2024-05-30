#include<iostream>

using namespace std;
#include<list>
#include<vector>

#include"list.h"
//void test_list1()
//{
//	int array[] = { 1,23,4,5,6,7,8,8, };
//	list<int> l1(array, array + sizeof(array) / sizeof(int));
//	list<int>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//}
//
//void test_list2()
//{
//	int array[] = { 1,23,4,5,6,7,8,8, };
//	list<int> l1(array, array + sizeof(array) / sizeof(int));
//	list<int>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	list<char> l2;
//	cout << l2.empty() << endl;
//}
//
//void test_list3()
//{
//	int array[] = { 1,23,4,5,6,7,8,8, };
//	list<int> l1(array, array + sizeof(array) / sizeof(int));
//	list<int>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	list<char> l2;
//	cout << l1.size() << endl;
//}
//
//void test_list4()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(5);
//
//	list<int>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	//l1.front() -= l1.back();
//	cout << l1.front() << endl;
//	cout << l1.back() << endl;
//}
//
//void test_list5()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(5);
//	l1.pop_back();
//	list<int>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	l1.pop_back();
//	cout << endl;
//	it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	l1.clear();
//	it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it<< endl;
//		it++;
//	}
//}
//int main()
//
//{
//
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//
//	int n = sizeof(ar) / sizeof(int);
//
//	vector<int> v(ar, ar + n);
//
//	vector<int>::iterator it = v.begin();
//
//	while (it != v.end())
//
//	{
//
//		if (*it != 0)
//
//			cout << *it;
//
//		else
//
//			v.erase(it);
//
//		it++;
//
//	}
//
//	return 0;
//
//}


//int main()
//{
//	int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };
//
//	int n = sizeof(ar) / sizeof(int);
//
//	list<int> mylist(ar, ar + n);
//
//	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
//
//	reverse(mylist.begin(), pos);
//
//	reverse(pos, mylist.end());
//
//	list<int>::const_reverse_iterator crit = mylist.crbegin();
//
//	while (crit != mylist.crend())
//
//	{
//
//		cout << *crit << " ";
//
//		++crit;
//
//	}
//
//	cout << endl;
//	return 0;
//}

int main()
{
	an::test_iterator();

	return 0;
}