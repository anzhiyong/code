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

		//迭代器实现
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

		//？
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//vector() = default;
		//构造并初始化n个val
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		//？
		vector(initializer_list<T> il)
		{
			reserve(il.size());
			for (auto e : il)
			{
				push_back(e);
			}
		}
		//拷贝构造，s1(s2)
		vector(const vector<T>& x)
		{
			reserve(x.capacity());
			for (auto e : x)
			{
				push_back(e);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finsh, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		//强制编译器生成默认的
		vector() = default;

		//s1=s2
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;//释放空间
				//置空

			}
		}
		//返回空间大小
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		//返回vector数据个数
		size_t size() const
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

		//扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t oldsize = size();
				if (_start)
				{
					for (size_t i = 0; i < oldsize; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finsh = _start + oldsize;
				_end_of_storage = _start + n;
			}
			
		}

		//插入数据
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

		void pop_back()
		{
			assert(size() > 0);
			_finsh--;
		}

		void insert(iterator pos, const T& x)
		{
			
			
			if (_finsh == _end_of_storage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);

				pos = _start + len;
			}

			iterator end = _finsh - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos= x;
			_finsh++;
		}

		//删除
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finsh);

			iterator it = pos + 1;
			while (it != _finsh)
			{
				*(it - 1) = *it;
				it++;
			}
			_finsh--;
		}

	private :
		iterator _start = nullptr;
		iterator _finsh = nullptr;
		iterator _end_of_storage = nullptr;
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

	void test_vector4()
	{
		an::vector<int> v5;
		v5.push_back(1);
		v5.push_back(2);
		v5.push_back(3);
		v5.push_back(4);
		//v5.push_back(5);
		//vector<int>::iterator it = v5.begin();
		v5.insert(v5.begin(), 3);

		for (auto e : v5)
		{
			cout << e << endl;
		}
		cout << endl;
	}

	void test_vector5()
	{
		an::vector<int> v5;
		v5.push_back(1);
		v5.push_back(2);
		v5.push_back(3);
		v5.push_back(4);
		//v5.push_back(5);
		//vector<int>::iterator it = v5.begin();
		v5.erase(v5.begin());

		for (auto e : v5)
		{
			cout << e << endl;
		}
		cout << endl;
	}

}



