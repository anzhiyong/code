#pragma once
#include<iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template <class K,class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _color;
	RBTreeNode(const pair<K,V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_color(RED)
	{}
};

template <class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	RBTree() = default;
	RBTree(const RBTree<K,V>& t)
	{
		_root = Copy(t._root);
	}

	RBTree<K, V>& operator=(RBTree<K, V> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	bool Insert(const pair<K, V>& kv)
	{
		//如果红黑树为空，直接插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
			
		}
		cur = new Node(kv);
		//新增红色节点
		cur->_color = RED;
		if (parent->_left > cur)
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
					//u存在且为红，
					// 把父亲和叔叔变黑，爷爷变红，继续向上处理
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;
					
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//u存在且为黑，或不存在 旋转+变色
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
					//u存在且为红，
					// 把父亲和叔叔变黑，爷爷变红，继续向上处理
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//u存在且为黑，或不存在 旋转+变色
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

		// 参考值
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
				cout << "存在黑色节点的数量不相等的路径" << endl;
				return false;
			}

			return true;
		}

		if (root->_color == RED && root->_parent->_color == RED)
		{
			cout << root->_kv.first << "存在连续的红色节点" << endl;
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