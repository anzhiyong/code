#pragma once
#include<assert.h>
//#include<iostream>
//using namespace std;
namespace an
{

	
	template <class T>

	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finsh;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finsh;
		}
		vector() = default;
		//构造并初始化n个val
		vector(size_t n, const T& val)
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//拷贝构造
		vector(const vector<T>& x)
		{
			reserve(x.capacity());
			for (auto e : x)
			{
				push_back(e);
			}
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size()
		{
			return _finsh - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i) const
		{
			assert(i < size());

			return _start[i];
		}

		void reserve(size_t n)
		{
			T* tmp = new T[n];
			size_t oldsize = size();
			if (_start)
			{
				for (size_t i = 0; i <oldsize ; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;
			_finsh = _start + oldsize;
			_end_of_storage = _start + n;
		}
		void push_back(const T& x)
		{
			if (_finsh == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finsh = x;
			_finsh++;
		}

		void erase(iterator pos)
		{
			for (size_t i = 0; i < size(); i++)
			{
				if (_start[i] = _start + pos)
				{
					
				}
			}
		}

	private :
		iterator _start;
		iterator _finsh;
		iterator _end_of_storage;
	};

	void test_vector1()
	{
		an::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		for (auto e : v1)
		{
			cout << e << endl;
		}
		cout << endl;
	}

	void test_vector2()
	{
		an::vector<int> v2;
		v2.push_back(3);
		v2.push_back(6);
		v2.push_back(9);
		an::vector<int> v3(v2);

		for (auto e : v3)
		{
			cout << e << endl;
		}
		cout << endl;
	}

	void test_vector3()
	{
		an::vector<int> v3(5, 1);
		
		

		for (auto e : v3)
		{
			cout << e << endl;
		}
		cout << endl;
	}





}


