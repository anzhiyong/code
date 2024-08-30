#include<iostream>
using namespace std;

//int main()
//{
//    char c;
//    cin >> c;
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            if (i == 0 && j == 2)
//            {
//                cout << c;
//            }
//            else if (i == 1 && (j == 1 || j == 2 || j == 3))
//            {
//                cout << c;
//            }
//            else if (i == 2)
//            {
//                cout << c;
//            }
//            else
//            {
//                cout << " ";
//            }
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

//int main()
//{
//	int num = 0, people = 0;
//	cin >> num;
//	cin >> people;
//	cout << num * people;
//
//	return 0;
//}

//int main()
//{
//	char c;
//	cin >> c;
//	cout << char(c - 32);
//
//	return 0;
//}


//字符串反转
//#include<algorithm>
//#include<cstring>
//int main()
//{
//	string s;
//	
//	cin >> s;
//	reverse(s.begin(),s.end());
//	//_strrev(s.c_str());  //strrev已经弃用，_strrev _strrev 对string无效
//	cout << s;
//	return 0;
//}
//
//int main()
//{
//	char s[] = "hello";
//
//	_strrev(s);
//
//	cout << s << endl;
//
//	return 0;
////}
//
//#include<stdio.h>
//int main()
//{
//	double t = 0.0;
//	double p = 0.0;
//	cin >> t;
//	cin >> p;
//	//cout << t / p <<endl ;
//	printf("%.2f", t / p);
//	cout << p * 2 << endl;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//int main()
//{
//    double t = 0.0;
//	double p = 0.0;
//	cin >> t;
//	cin >> p;
//	//cout << t / p <<endl ;
//	double o = t / p;
//	printf("%.3f\n", o);
//	printf("%d", (int)(p * 2));
//    return 0;
//}

//三角形面积
//#include<math.h>
//int main()
//{
//	double a, b, c, p;
//	cin >> a >> b >> c;
//	p = (a + b + c) / 2;
//	printf("%.1f", sqrt(p * (p - a) * (p - b) * (p - c)));
//
//
//	return 0;
//}

//P5707 【深基2.例12】上学迟到
//#include<iostream>
//using namespace std;
//#include<math.h>
//int main()
//{
//	double s, v;
//	cin >> s >> v;
//	int ce = ceil(s / v);
//	int time = ce + 10;;
//	int o = 60 - time;
//	int hours = 8;
//	if (60 - time > 0)
//	{
//		cout << "07:" << o;
//	}
//	else
//	{
//		hours = hours - time / 60;
//		if (time % 60 == 0)
//		{
//			cout << "0" << hours + 1 << ":" << "00";
//		}
//		else if (time > 0 && time < 10)
//		{
//			cout << "0" << hours + 1 << ":" << "0"<< 60 - time % 60;
//		}
//		else
//		{
//			cout << "0" << hours+1 << ":" << 60 - time % 60;
//		}
//		
//	}
//
//	return 0;
//}

//#include<vector>
//int main()
//{
//	int n, m;
//	vector<int> num = {0};
//	vector<int> s = {0};
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//		num.push_back(a);
//	}
//	
//	for (int i = 0; i < m; i++)
//	{
//		int a;
//		cin >> a;
//		s.push_back(a);
//	}
//
//	for (int i = 1; i <= m; i++)
//	{
//		int a = num[s[i] ];
//	
//		cout << a << endl;
//	}
//
//}


//P1271 【深基9.例1】选举学生会
//#include<vector>
//#include<algorithm>
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> x;
//	for (int i = 0; i < m; i++)
//	{
//		int a;
//		cin >> a;
//		x.push_back(a);
//	}
//	sort(x.begin(), x.end());
//	for (int i = 0; i < m; i++)
//	{
//		cout << x[i] <<" ";
//	}
//
//	return 0;
//}


//P1177 【模板】排序
//#include<vector>
//#include<algorithm>
//int main()
//{
//	int N;
//	vector<int> num;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int a;
//		cin >> a;
//		num.push_back(a);
//	}
//	sort(num.begin(), num.end());
//	for (size_t i = 0; i < num.size(); i++)
//	{
//		cout << num[i] << " ";
//	}
//
//
//	return 0;
//}


//P1923 【深基9.例4】求第 k 小的数
//#include<vector>
//#include<algorithm>
//int TKSN(vector<int>& nums, int k)
//{
//	return nums[k];
//}
//int main()
//{
//	int n, k;
//	vector<int> nums;
//	cin >> n >> k;
//	for (size_t i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//		nums.push_back(a);
//	}
//	sort(nums.begin(), nums.end());
//	cout<<TKSN(nums, k);
//
//	return 0;
//}

//P1059 [NOIP2006 普及组] 明明的随机数
#include<vector>
#include<algorithm>
int main()
{
	int M;
	vector<int> nums;
	vector<int> nums2;
	cin >> M;
	for (size_t i = 0; i <M; i++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());

	for (size_t i = 0; i < M; i++)
	{
		int a = nums[i];
		
		if (nums2.empty())
		{
			nums2.push_back(nums[i]);
		}
		if(a==nums2.back())
		{
			continue;
			
		}
		else
		{
			nums2.push_back(a);
		}
		
	}
	
	cout << nums2.size() << endl;
	for (size_t i = 0; i < nums2.size(); i++)
	{
		cout << nums2[i] << " ";
	}


	return 0;
}