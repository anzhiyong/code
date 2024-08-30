#include<iostream>
using namespace std;

class Date
{
	int _year;
	int _month;
	int _day;
public:

	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	void Print()
	{
		cout << _year << _month << _day << endl;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}
};


int main()
{
	
	shared_ptr<Date> pd;
	pd = make_shared<Date>();
	
	pd->Print();
	return 0;
}