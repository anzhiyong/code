#include"String.h"

namespace an
{
	
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}
	string::~string()
	{
		delete [] _str;
		_size = _capacity = 0;

	}
	const char* string::c_str() const
	{
		return _str;
	}
	size_t string::size() const
	{
		return _size;
	}
	char& string::operator[](size_t pos)
	{
		return _str[pos];
	}

	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
}