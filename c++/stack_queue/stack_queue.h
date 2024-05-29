#pragma once
#include<vector>
#include<list>

namespace an
{
	
	template<class T, class Container>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			_con.size();
		}
	private:
		Container _con;
	};

	template <class T, class C>
	class queue
	{
	private :
		C _c;
	public:
		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{

			_c.erase(_c.begin());
		}

		T& back()
		{
			return _c.back();
		}
		
		T& front()
		{
			return _c.front();
		}
		bool empty()
		{
			return _c.empty();
		}

		size_t size()
		{
			_c.size();
		}

		
	};
}