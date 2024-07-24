#pragma once

#include"RBTree.h"

namespace an
{
	template <class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::Iterator iterator;

		iterator begin()
		{
			return _rb.Begin();
		}

		iterator end()
		{
			return _rb.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _rb.Insert(key);
		}

		iterator find(const K& key)
		{
			return _rb.Find(key);
		}



	private:

		RBTree<K, K, SetKeyOfT> _rb;
	};

	void test_MySet()
	{
		set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		for (auto e : a)
		{
			s.insert(e);
		}

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;

		set<int>::iterator it = s.end();
		while (it != s.begin())
		{
			--it;

			cout << *it << " ";
		}
		cout << endl;

		it = s.begin();
		//*it += 10;
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//Print(s);
	}

}

