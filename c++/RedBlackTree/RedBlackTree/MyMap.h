#pragma once

#include"RBTree.h"

namespace an
{
	template <class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::ConstIterator const_iterator;

		iterator begin()
		{
			return _rb.Begin();
		}

		const_iterator begin() const
		{
			return _rb.Begin();
		}

		iterator end()
		{
			return _rb.End();
		}
		const_iterator end() const
		{
			return _rb.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _rb.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _rb.Find(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:

		RBTree<K, pair<const K,V>, MapKeyOfT> _rb;
	};

	void test_MyMap()
	{
		map<string, string> dict;
		dict.insert({ "sort", "≈≈–Ú" });
		dict.insert({ "left", "◊Û±ﬂ" });
		dict.insert({ "right", "”“±ﬂ" });

		/*dict["left"] = "◊Û±ﬂ£¨ £”‡";
		dict["insert"] = "≤Â»Î";
		dict["string"];*/

		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			// ≤ªƒ‹–ﬁ∏ƒfirst£¨ø…“‘–ﬁ∏ƒsecond
			//it->first += 'x';
			//it->second += 'x';

			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}

}