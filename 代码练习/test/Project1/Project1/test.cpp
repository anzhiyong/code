#include<iostream>
#include<string>
using namespace std;
//class student
//{
//public:
//	void eat()
//	{
//		cout << "³Ô" << endl;
//	}
//
//	void learn()
//	{
//		cout << "Ñ§Ï°" << endl;
//	}
//
//private :
//	string name;
//	int age;
//};
//int main()
//{
//	student s1;
//	s1.eat();
//	s1.learn();
//
//	return 0;
//}
//
//struct a
//{
//	short s;//2
//	double d;//8
//	char c;//1
//	
//};
//
//int main()
//{
//	
//	printf("%d\n", sizeof(struct a));
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int L, R;
//	cin >> L >> R;
//	int c = 0;
//	for (int i = L; i <=R;i++)
//	{
//		if (i % 10 == 2)
//			c++;
//		if (i % 10 == 0)
//		{
//			if (i / 10 == 2)
//				c++;
//		}
//		if (i % 10 != 0)
//		{
//			if (i / 10 == 2)
//				c++;
//		}
//		
//	}
//	cout << c << endl;
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;
#include<algorithm>
int main()
{
	string s;
	char c;
	while (cin >> c)
	{
		s.push_back(c);
	}
	sort(s.begin(), s.end());
	
	for (size_t i = 0; i < s.length(); i++)
	{
		
		if (s[i] == s[i + 1])
		{
			s.erase(i,i+1);
		}
	}
	


	return 0;
}