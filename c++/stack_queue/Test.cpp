#include<iostream>
using namespace std;
#include<stack>
#include<queue>


//#include"stack_queue.h"
//
//void test_stack1()
//{
//	stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	s.push(5);
//	while (!s.empty())  //ջ��Ϊ�ռ���
//	{
//		//��ȡջ��Ԫ��
//		cout << s.top() << endl;
//		//ɾ��ջԪ��
//		s.pop();
//	}
//}

//void test_stack2()
//{
//	an::stack<int, vector<int>> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	s.push(5);
//	
//	while (!s.empty())  //ջ��Ϊ�ռ���
//	{
//		//��ȡջ��Ԫ��
//		cout << s.top() << endl;
//		//ɾ��ջԪ��
//		s.pop();
//	}
//}

//void test_queue1()
//{
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	
//	while (!q.empty())
//	{
//		cout << q.back();
//		q.pop();
//	}
//}
//
//void test_queue2()
//{
//	an::queue<int, vector<int>> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	while (!q.empty())
//	{
//		cout << q.front();
//		q.pop();
//	}
//}

#include"Priority_Queue.h"


void TestPriorityQueue()
{
	// ��ѣ���Ҫ�û����Զ����������ṩ<������
	an::priority_queue<int, vector<int>, an::mygreater<int>> q1;
	q1.push(8);
	q1.push(9);
	q1.push(2);
	q1.push(5);
	

	while (!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
}
int main()
{
	
	TestPriorityQueue();
	return 0;
}