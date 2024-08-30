#pragma once
#include<iostream>
using namespace std;
#include<string>

namespace key
{
	template<class K>
	struct BSTNode
	{
		K _key;
		BSTNode<K>* _left;
		BSTNode<K>* _right;

		BSTNode(const K& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTNode<K> Node;
	public:
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool Erase(const K& key)
		{
			//�����Ϊ�գ�ɾ��ʧ��
			if (_root == nullptr)
			{
				return false;
			}
			//����Ҫɾ����key�ڵ�
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					break;
				}
			}
			//���curΪ�գ���Ҫɾ���Ľڵ㲻����
			if (cur == nullptr)
			{
				return false;
			}

			//���û�����ӣ�ֻ���Һ���ֱ��ɾ��
			if (cur->_left == nullptr)
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_right;
				}
				else
				{
					parent->_right = cur->_right;
				}
				delete cur;
				return true;
			}
			else if (cur->_right == nullptr)
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_left;
				}
				else
				{
					parent->_right = cur->_left;
				}
				delete cur;
				return true;
			}
			else
			{
				//�����Ӷ��ڣ���һ������ڵ�
				//����������С�ڵ�
				Node* rightMinP = cur;
				Node* rightMin = cur->_right;
				while (rightMin->_left)
				{
					rightMinP = rightMin;
					rightMin = rightMin->_left;
				}
				cur->_key = rightMin->_key;

				if (rightMinP->_left == rightMin)
					rightMinP->_left = rightMin->_right;
				else
					rightMinP->_right = rightMin->_right;
				delete rightMin;
				return true;

			}


		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);

		}

	private:
		Node* _root = nullptr;
	};
}

namespace keyValue
{
	template<class K,class V>
	struct BSTNode
	{
		K _key;
		V _value;
		BSTNode<K, V>* _left;
		BSTNode<K, V>* _right;

		BSTNode(const K& key,const V& value)
			:_key(key)
			,_value(value)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<class K,class V>
	class BSTree
	{
		typedef BSTNode<K, V> Node;
	public:
		BSTree() = default;
		BSTree(const BSTree<K, V>& t)
		{
			_root = Copy(t._root);
		}
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		bool Insert(const K& key,const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,value);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			//�����Ϊ�գ�ɾ��ʧ��
			if (_root == nullptr)
			{
				return false;
			}
			//����Ҫɾ����key�ڵ�
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					break;
				}
			}
			//���curΪ�գ���Ҫɾ���Ľڵ㲻����
			if (cur == nullptr)
			{
				return false;
			}

			//���û�����ӣ�ֻ���Һ���ֱ��ɾ��
			if (cur->_left == nullptr)
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_right;
				}
				else
				{
					parent->_right = cur->_right;
				}
				delete cur;
				return true;
			}
			else if (cur->_right == nullptr)
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_left;
				}
				else
				{
					parent->_right = cur->_left;
				}
				delete cur;
				return true;
			}
			else
			{
				//�����Ӷ��ڣ���һ������ڵ�
				//����������С�ڵ�
				Node* rightMinP = cur;
				Node* rightMin = cur->_right;
				while (rightMin->_left)
				{
					rightMinP = rightMin;
					rightMin = rightMin->_left;
				}
				cur->_key = rightMin->_key;

				if (rightMinP->_left == rightMin)
					rightMinP->_left = rightMin->_right;
				else
					rightMinP->_right = rightMin->_right;
				delete rightMin;
				return true;

			}


		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);

		}
		void Destroy(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Node* newRoot = new Node(root->_key, root->_value);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);

			return newRoot;
		}

	private:
		Node* _root = nullptr;
	};
}
