#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


//枚举  ：黑  白
enum Color
{
	RED,
	BLACK
};

//创建树节点，存储三叉链：父亲，左节点，右节点
template <class T>
struct RBTreeNode
{
	T _data;  //数据 泛型化
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Color _color;   //存储颜色
	RBTreeNode(const T& data)
		:_data(data)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{}
};

//迭代器
template <class T ,class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;//传入的节点指针
	Node* _root;
	//初始化
	RBTreeIterator(Node* node, Node* root)
		:_node(node)
		,_root(root)
	{}

	Self& operator++()
	{
		if (_node->_right)
		{
			//右不为空，右子树的最左节点
			Node* leftMost = _node->_right;
			while (leftMost->_left)
			{
				leftMost = leftMost->_left;
			}
			_node = leftMost;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;

		}
		
		return *this;
	}

	Self& operator--()
	{
		if (_node == nullptr)
		{
			Node* rightMost = _root;
			while (rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else if (_node->_left)
		{
			//左不为空，左子树的最右节点
			Node* rightMost = _node->_left;
			while (rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;

		}

		return *this;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!= (const Self& s)
	{
		return _node != s._node;
	}

	bool operator== (const Self& s)
	{
		return _node == s._node;
	}

};

template <class K,class T,class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	RBTree() = default;
	RBTree(const RBTree& t)
	{
		_root = Copy(t._root);
	}

	Iterator Begin()
	{
		Node* lastleft = _root;
		while (lastleft && lastleft->_left)
		{
			lastleft = lastleft->_left;
		}
		return Iterator(lastleft,_root);
	}

	Iterator End()
	{
		return Iterator(nullptr,_root);
	}

	ConstIterator Begin() const
	{
		Node* leftMost = _root;
		while (leftMost && leftMost->_left)
		{
			leftMost = leftMost->_left;
		}

		return ConstIterator(leftMost, _root);
	}

	ConstIterator End() const
	{
		return ConstIterator(nullptr, _root);
	}

	RBTree& operator=(RBTree t)
	{
		swap(_root, t._root);
		return *this;
	}

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	
	pair<Iterator, bool> Insert(const T& data)
	{
		//如果红黑树为空，直接插入
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_color = BLACK;
			return make_pair(Iterator(_root, _root), true);
		}
		KeyOfT kot;
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
				return make_pair(Iterator(cur, _root), false);
			}
			
		}
		cur = new Node(data);
		Node* newnode = cur;
		//新增红色节点
		cur->_color = RED;
		if (kot(parent->_data) > kot(data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
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
		return make_pair(Iterator(newnode, _root), true);
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
	Node* _root = nullptr;
};