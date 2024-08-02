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

//�ػ�
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



//���Ŷ�ַ�� 
namespace open_address
{
	//״̬
	enum State
	{
		EXIST,  //����
		EMPTY,  //��
		DELETE  //ɾ��
	};

	template <class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};


	//����������
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
			//����������
			if (Find(kv.first))
				return false;
			//����
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
			//����hashiλ��
			size_t hashi = hs(kv.first) % _tables.size();
			//��ϣ��ͻ,����̽��
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
			//����hashiλ��	��ȡ�࣡������
			size_t hashi = hs(key) % _tables.size();
			//��ϣ��ͻ,����̽��
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
		size_t _n = 0;  //��ǰ���д�����ݸ���
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
		ht2.Insert({ "left","���" });
		/*cout << stringHashFun()("abcd") <<endl;
		cout << stringHashFun()("bacd") <<endl;
		cout << stringHashFun()("cdba") <<endl;*/
	}
}


//��ϣͰ
namespace hash_bucket
{
	template <class K,class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K,V>* _next;

		HashNode(const pair<K,V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template <class K, class V, class KeyOfT, class Hash = HashFun<K>>
	class HashTable
	{
		typedef HashNode<K,V> Node;
	public:

		HashTable()
		{
			_tables.resize(10, nullptr);
		}

		~HashTable()
		{
			//���ΰ�ÿ��Ͱ�ͷŵ�
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

		bool Insert(const pair<K, V>& kv)
		{
			Hash hs;
			//����λ��
			size_t hashi = hs(kv.first) % _tables.size();
			//��������==1 ����
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
						//���±���ӳ���λ��
						size_t hashi = hs(cur->_kv.first) % newtables.size();
						//�Ѿɱ�����ͷ�����±�
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						//�ɱ����������
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);

			}

			//ͷ��
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
			
		}

		Node* Find(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			//����ԭ��
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					if (cur->_kv.first == key)
					{
						return cur;
					}
					cur = cur->_next;
				}
			}
			return nullptr;

		}

		bool Erase(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			//����ԭ��
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
		ht2.Insert({ "left","���" });
		ht2.Insert({ "right","�ұ�" });
		
	}*/


}

