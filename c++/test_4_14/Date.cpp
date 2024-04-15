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
		cout << "����������󣡣�" <<endl;
	}
}

void Date::Print() const
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
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
	return _year == d._year 
		&& _month == d._month 
		&& _day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//d1 +=100;
Date& Date::operator+=(int day)
{
	*this = *this + day;
	return *this;
}
Date Date::operator+(int day)
{
	Date tem = *this;
	tem._day += day;
	while (tem._day > GetMonthDay(tem._year,tem._month))
	{
		tem._day -= GetMonthDay(tem._year, tem._month);
		++tem._month;
		if (tem._month == 13)
		{
			++tem._year;
			tem._month = 1;
		}
	}
	return tem;

}
//d1 -=100;

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}

		// ����һ���µ�����
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp = *this;
	tmp -= day;

	return tmp;
}
//Date& Date::operator-=(int day)
//{
//	*this = *this - day;
//	return *this;
//}
////d1-100;
//Date Date::operator-(int day)
//{
//	Date tem = *this;
//	tem._day = tem._day - day;
//	while (tem._day < GetMonthDay(tem._year, tem._month))
//	{
//		tem._day = tem._day - GetMonthDay(tem._year, tem._month);
//		--tem._month;
//		if (tem._month == 0)
//		{
//			tem._month = 12;
//			--tem._year;
//		}
//	}
//
//	return tem;
//}


//d1-d2
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (max != min)
	{
		min++;
		n++;
	}
	return n * flag;
}

//++d1-->> d1.operator++()
//ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;

}
//����++
Date Date::operator++(int)
{
	Date tem = *this;
	*this += 1;
	return tem;
}
//ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//����--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "����������������:>";
	in >> d._year >> d._month >> d._day;

	if (!d.CheckDate())
	{
		cout << "���ڷǷ�" << endl;
	}

	return in;
}