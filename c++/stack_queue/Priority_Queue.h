#pragma once
#include<vector>



namespace an
{
	template<class T, class Container = vector(T)>
	class priority_queue
	{
		void AdjustUp()
		{

		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);


		}

		void pop()
		{
			_con.pop_back();
			AdjustDown();
		}

	private:
		Container _con;

	};
}
