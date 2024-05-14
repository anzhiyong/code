#include"String.h"

namespace an
{
	const size_t string::npos = -1;
	
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}

	string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
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

	string::const_iterator string::begin() const
	{
		return _str;
	}
	string::const_iterator string::end() const
	{
		return _str + _size;
	}
	
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		_str[_size] = ch;
		_str[_size + 1] = '\0';
		_size++;
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (len + _size > _capacity)
		{
			reserve(len + _size);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	void string::insert(size_t pos,const char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		size_t end = _size-1;
		while (end>=pos)
		{
			_str[end + 1] = _str[end];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}
	void string::insert(size_t pos,const char* str)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		size_t len = strlen(str);
		size_t end = _size +len-1;
		
		while (pos+len<=end)
		{
			_str[end ] = _str[end-len];
			end--;
		}
		memcpy(_str + pos, str, len);
		_size += len;
	}
	void string::erase(size_t pos, size_t len)
	{
		if (len > _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str + pos, _str + pos + len);
			_size -= len;
		}
		
	}





}