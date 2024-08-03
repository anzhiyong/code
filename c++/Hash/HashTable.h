#pragma once
#include<iostream>
#include<vector>
using namespace std;



template <class K>
struct HashFun
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//特化
template <>
struct HashFun<string>
{
	size_t operator()(const string& s)
	{
		size_t hashi = 0;
		for (auto e : s)
		{
			hashi *= 31;
			hashi += e;
		}
		return hashi;
	}
};



//开放定址法 
namespace open_address
{
	//状态
	enum State
	{
		EXIST,  //存在
		EMPTY,  //空
		DELETE  //删除
	};

	template <class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};


	//除留余数法
	template <class K, class V, class Hash = HashFun<K> >
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V> kv)
		{
			//不允许冗余
			if (Find(kv.first))
				return false;
			//扩容
			if (_n * 10 / _tables.size() >= 7)
			{
				//vector<HashData<K, V>> newTables(_tables.size() * 2);
				HashTable<K, V> newHT;
				newHT._tables.resize(_tables.size() * 2);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}
				_tables.swap(newHT._tables);
			}
			Hash hs;
			//计算hashi位置
			size_t hashi = hs(kv.first) % _tables.size();
			//哈希冲突,线性探测
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			//计算hashi位置	用取余！！！！
			size_t hashi = hs(key) % _tables.size();
			//哈希冲突,线性探测
			while (_tables[hashi]._state == EXIST
				&& _tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				++hashi;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				return true;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;  //当前表中存的数据个数
	};

	void TestHt1()
	{
		HashTable<int, int> ht1;
		int a[] = { 11,23,4,13,25,15,9 ,10 };
		for (auto e : a)
		{
			ht1.Insert({ e,e });
		}
		ht1.Insert({ 11,11 });
		ht1.Erase(15);
		cout << ht1.Find(15) << endl;


	}


	void TestHt2()
	{
		HashTable<string, string> ht2;
		ht2.Insert({ "left","左边" });
		/*cout << stringHashFun()("abcd") <<endl;
		cout << stringHashFun()("bacd") <<endl;
		cout << stringHashFun()("cdba") <<endl;*/
	}
}


//哈希桶
namespace hash_bucket
{
	template <class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	template <class K, class T, class KeyOfT, class Hash = HashFun<K>>
	class HashTable;

	template <class K, class T, class Ptr, class Ref, class KeyOfT, class Hash>
	struct HTIterator
	{
		typedef HTIterator<K, T, Ptr, Ref, KeyOfT, Hash> Self;
		typedef HashNode<T> Node;


		const HashTable<K, T, KeyOfT, Hash>* _pht;
		Node* _node;

		HTIterator(Node* node, const HashTable<K, T, KeyOfT, Hash>* pht)
			:_node(node)
			,_pht(pht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				Hash hs;
				KeyOfT kot;
				size_t hashi = hs(kot(_node->_data)) % _pht->_tables.size();
				++hashi;
				while (hashi < _pht->_tables.size())
				{
					if (_pht->_tables[hashi])
					{
						break;
					}

					++hashi;
				}
				if (hashi == _pht->_tables.size())
				{
					_node = nullptr; // end()
				}
				else
				{
					_node = _pht->_tables[hashi];
				}

			}

			

			return *this;
		}
	};

	template <class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		template <class K, class T, class Ptr, class Ref, class KeyOfT, class Hash>
		friend struct HTIterator;

		typedef HashNode<T> Node;
	public:
		typedef HTIterator<K, T, T*, T&, KeyOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T*, const T&, KeyOfT, Hash> ConstIterator;

		Iterator Begin()
		{
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					return Iterator(cur, this);
				}
			}
			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		ConstIterator Begin() const
		{
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					return Iterator(cur, this);
				}
			}
			return End();
		}

		ConstIterator End() const
		{
			return Iterator(nullptr, this);
		}

		HashTable()
		{
			_tables.resize(10, nullptr);
		}

		~HashTable()
		{
			//依次把每个桶释放掉
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					--_n;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		pair<Iterator, bool> Insert(const T& data)
		{
			Hash hs;
			KeyOfT kot;
			Iterator it = Find(kot(data));
			if (it != End())
				return make_pair(it, false);
	
			//计算位置
			size_t hashi = hs(kot(data)) % _tables.size();
			//负载因子==1 扩容
			if (_n == _tables.size())
			{
				/*HashTable<K, V> newHT;
				newHT._tables.resize(_tables.size() * 2);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						newHT.Insert(cur->_kv);
						cur = cur->_next;
					}
				}
				_tables.swap(newHT._tables);*/

				vector<Node*> newtables(_tables.size() * 2, nullptr);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						//算新表中映射的位置
						size_t hashi = hs(kot(cur->_data)) % newtables.size();
						//把旧表数据头插在新表
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						//旧表继续往后走
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);

			}

			//头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return make_pair(Iterator(newnode, this), true);
			
		}

		Iterator Find(const K& key)
		{
			Hash hs;
			KeyOfT kot;
			size_t hashi = hs(key) % _tables.size();
			//遍历原表
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					if (kot(cur->_data) == key)
					{
						return Iterator(cur,this);
					}
					cur = cur->_next;
				}
			}
			return End();

		}

		bool Erase(const K& key)
		{
			Hash hs;
			KeyOfT kot;
			size_t hashi = hs(kot(key)) % _tables.size();
			//遍历原表
			Node* prev = nullptr;
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					if (cur->_kv.first == key)
					{
						if (prev == nullptr)
						{
							_tables[hashi] = cur->_next;
						}
						else
						{
							prev->_next = cur->_next;
						}
						delete cur;
						--_n;
						return true;
					}
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};

	//void TestHt1()
	//{
	//	HashTable<int, int> ht1;
	//	int a[] = { 11,21,4,14,24,15,19};
	//	for (auto e : a)
	//	{
	//		ht1.Insert({ e,e });
	//	}
	//	//ht1.Insert({ 11,11 });
	//	for (auto e : a)
	//	{
	//		ht1.Erase(e);
	//	}

	//}

	/*void TestHt2()
	{
		HashTable<string, string> ht2;
		ht2.Insert({ "left","左边" });
		ht2.Insert({ "right","右边" });
		
	}*/


}

