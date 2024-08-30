#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()
	{

	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
//private:
	int _year=2024;
	int _month=4;
	int _day=10;

};
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}
int main()
{
	/*Date d1;
	d1.print();
	Date d2(d1);
	d2.print();*/
	Date d1(2024, 4, 10);
	Date d2(2024, 4, 10);
	cout << (d1 == d2) << endl;
	return 0;
}

