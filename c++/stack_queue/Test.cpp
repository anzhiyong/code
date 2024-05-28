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
	while (!s.empty())  //栈不为空继续
	{
		//获取栈顶元素
		cout << s.top() << endl;
		//删除栈元素
		s.pop();
	}

	return 0;
}