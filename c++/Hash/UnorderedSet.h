#pragma once
#include"HashTable.h"

namespace an
{
	template <class K, class Hash = HashFun<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:

		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT, Hash>::Iterator iterator;

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator Find(const K& key)
		{
			return _ht.Find(key);
		}

		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}


	private:
		hash_bucket::HashTable<K, K, SetKeyOfT, Hash> _ht;


	};

	
	void test_set()
	{
		unordered_set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3,3,15 };
		for (auto e : a)
		{
			s.insert(e);
		}

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;

		//unordered_set<int>::iterator it = s.begin();
		//while (it != s.end())
		//{
		//	//*it += 1;

		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;

		/*unordered_set<Date, HashDate> us;
		us.insert({ 2024, 7, 25 });
		us.insert({ 2024, 7, 26 });

		Print(s);*/
	}


}