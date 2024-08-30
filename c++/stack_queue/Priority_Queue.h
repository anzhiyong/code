#pragma once
#include<vector>



namespace an
{
	template<class T>
	class myless
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	class mygreater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
		

	template<class T, class Container = vector<T> , class Comapre = myless<T>>
	class priority_queue
	{
	public:

		priority_queue() = default;

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// 
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}

		void AdjustUp(int child)
		{
			Comapre comfunc;
			int parent = (child - 1) / 2;

			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (comfunc(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
				
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(int parent)
		{
			Comapre comfunc;
			int child = (parent * 2) + 1;

			while (child < _con.size())
			{
				//if (child+1< _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && comfunc(_con[child], _con[child + 1]))
				{
					child++;
				}
				//if (_con[parent] < _con[child])
				if (comfunc(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = (parent * 2) + 1;
				}
				else
				{
					break;
				}
			
			}
			
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top() const
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};


	void test_priority()
	{
		priority_queue<int> pq;
		pq.push(1);
		pq.push(2);
		pq.push(3); 
		pq.push(4);

		pq.pop();

	}




}
