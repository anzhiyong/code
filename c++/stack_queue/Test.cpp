#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while (!s.empty())  //ջ��Ϊ�ռ���
	{
		//��ȡջ��Ԫ��
		cout << s.top() << endl;
		//ɾ��ջԪ��
		s.pop();
	}

	return 0;
}