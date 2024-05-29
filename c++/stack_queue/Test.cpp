#include<iostream>
using namespace std;
#include<stack>
#include<queue>


#include"stack_queue.h"

void test_stack1()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while (!s.empty())  //栈不为空继续
	{
		//获取栈顶元素
		cout << s.top() << endl;
		//删除栈元素
		s.pop();
	}
}

//void test_stack2()
//{
//	an::stack<int, vector<int>> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	s.push(5);
//	
//	while (!s.empty())  //栈不为空继续
//	{
//		//获取栈顶元素
//		cout << s.top() << endl;
//		//删除栈元素
//		s.pop();
//	}
//}

void test_queue1()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	while (!q.empty())
	{
		cout << q.back();
		q.pop();
	}
}

void test_queue2()
{
	an::queue<int, vector<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front();
		q.pop();
	}
}
int main()
{
	
	test_queue2();
	return 0;
}