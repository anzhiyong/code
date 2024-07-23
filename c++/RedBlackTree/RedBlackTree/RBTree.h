#pragma once
#include<iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template <class T>
struct RBTreeNode
{
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Color _color;
	RBTreeNode(const T& data)
		:_data(data)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_color(RED)
	{}
};

template <class T>
class RBTreeIterator
{
	typedef RBTreeNode Node;
	typedef RBTreeIterator Self;

	Node* _node;
	RBTreeIterator(Node* node)
		:_node(node)
	{}

	Self& operator++()
	{
		return *this;
	}

	Self& operator*
	{
		return _node->_data;
	}

	bool operator!= (const Self& s)
	{
		return _node != s._node;
	}

};

template <class K,class T,class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree() = default;
	RBTree(const RBTree<K,T, KeyOfT>& t)
	{
		_root = Copy(t._root);
	}

	RBTree<K, T, KeyOfT>& operator=(RBTree<K, T, KeyOfT> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	KeyOfT kot;
	bool Insert(const T& data)
	{
		//��������Ϊ�գ�ֱ�Ӳ���
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_color = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
			
		}
		cur = new Node(data);
		//������ɫ�ڵ�
		cur->_color = RED;
		if (dot(parent->_data) > dot(data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		while (parent && parent->_color == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//     g
				//   p   u
				// c
				if (uncle&& uncle->_color == RED)
				{
					//u������Ϊ�죬
					// �Ѹ��׺������ڣ�үү��죬�������ϴ���
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;
					
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//u������Ϊ�ڣ��򲻴��� ��ת+��ɫ
					//     g
					//   p   u
					// c
					if (parent->_left == cur)
					{
						RotateRight(grandfather);
						parent->_color = BLACK;
						grandfather->_color = RED;

					}
					else
					{
						//     g
						//   p   u
						//	   c
						RotateLeft(parent);
						RotateRight(grandfather);

						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}
				
			}
			else
			{
				Node* uncle = grandfather->_right;
				if (uncle&& uncle->_color == RED)
				{
					//u������Ϊ�죬
					// �Ѹ��׺������ڣ�үү��죬�������ϴ���
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//u������Ϊ�ڣ��򲻴��� ��ת+��ɫ
					//     g
					//   u   p
					//         c
					if (parent->_right == cur)
					{
						RotateLeft(grandfather);
						parent->_color = BLACK;
						grandfather->_color = RED;

					}
					else
					{
						//     g
						//   u   p
						//	   c
						RotateRight(parent);
						RotateLeft(grandfather);

						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}
			}
		}
		_root->_color = BLACK;
		return true;
	}

	bool IsBalance()
	{
		if (_root == nullptr)
			return true;

		if (_root->_color == RED)
		{
			return false;
		}

		// �ο�ֵ
		int refNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_color == BLACK)
			{
				++refNum;
			}

			cur = cur->_left;
		}

		return Check(_root, 0, refNum);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:

	bool Check(Node* root, int blackNum, const int refNum)
	{
		if (root == nullptr)
		{
			//cout << blackNum << endl;
			if (refNum != blackNum)
			{
				cout << "���ں�ɫ�ڵ����������ȵ�·��" << endl;
				return false;
			}

			return true;
		}

		if (root->_color == RED && root->_parent->_color == RED)
		{
			cout << root->_kv.first << "���������ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		if (root->_color == BLACK)
		{
			blackNum++;
		}

		return Check(root->_left, blackNum, refNum)
			&& Check(root->_right, blackNum, refNum);
	}

	void RotateLeft(Node* parent)
	{
		//_rotateNum++;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent;
		}
	}

	void  RotateRight(Node* parent)
	{
		//_rotateNum++;

		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parentParent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		}

	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
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
	Node* _root;
};