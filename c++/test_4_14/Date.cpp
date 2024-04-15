#include "Date.h"

bool Date::CheckDate()
{
	if (_month < 1 || _month>12 || _day<1 || _day>GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!(CheckDate()))
	{
		cout << "日期输入错误！！" <<endl;
	}
}

void Date::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}

	return false;
}

bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator==(const Date& d) const
{
	return _year == d._day 
		&& _month == d._month 
		&& _day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}