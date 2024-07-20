#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

template <class K,class V>
//����AVL���ڵ�
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;		
	int _bf; // balance factor		ƽ������	

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}

};

template <class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	AVLTree() = default;
	AVLTree(const AVLTree<K, V>& t)
	{
		_root = Copy(t._root);
	}


	AVLTree<K, V>& operator=(AVLTree<K, V> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~AVLTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//����ƽ������
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//�������ϸ���ƽ������
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//��ƽ���ˣ���Ҫ��ת��
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					//ͬ�ŵ���
					//����
					RotateLeft(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					//����
					RotateRight(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					//���˫��
					RotateRL(parent);
				}
				else
				{
					RotateLR(parent);
				}
				break;
			}
			else
			{
				assert(false);
			}
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

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

private:

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		// ����Ҳ��AVL��
		if (nullptr == root) return true;

		// ����pRoot�ڵ��ƽ�����ӣ���pRoot���������ĸ߶Ȳ�
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
			
			// ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
			// pRootƽ�����ӵľ���ֵ����1����һ������AVL��
			if (diff != root->_bf || (diff > 1 || diff < -1))
				return false;
		// pRoot��������������AVL���������һ����AVL��
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}


	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		
		Node* parentparent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parentparent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentparent->_left == parent)
			{
				parentparent->_left = subR;
			}
			else
			{
				parentparent->_right = subR;
				
			}
			subR->_parent = parentparent;
		}
		//����ƽ������
		subR->_bf = parent->_bf = 0;
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentparent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parentparent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentparent->_left == parent)
			{
				parentparent->_left = subL;
			}
			else
			{
				parentparent->_right = subL;
			}
			subL->_parent = parentparent;
		}

		//����ƽ������
		subL->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateLeft(parent->_left);
		RotateRight(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;

		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		
		

		RotateRight(parent->_right);
		RotateLeft(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;

		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv .first << ":" << root->_kv.second << endl;
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