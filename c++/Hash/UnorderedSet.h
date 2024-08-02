#pragma once
#include"HashTable.h"

namespace an
{
	template <class K, class Hash = HashFun<K>>
	class unoedered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		bool insert(const K& key)
		{
			_ht.Insert(key);
		}


	private:
		hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;


	};
}