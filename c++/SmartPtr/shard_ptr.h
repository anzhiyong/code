#pragma once

namespace an
{
	template <class T>
	class shard_ptr
	{
	public:
		shard_ptr(T* ptr)
			:_ptr(ptr)
			,_pconst(new int(1))
		{}

		shard_ptr(const shard_ptr<T>& sp)
		{

		}

	private:
		T* _ptr;
		int* _pconst;

	};
}