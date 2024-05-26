#pragma once
#include<assert.h>

namespace an
{
	template <class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;

		T _data;

		ListNode(const T& data = T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(data)
		{}
	};

	//µü´úÆ÷
	template <class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator Self;
	

		list_iterator(Node* node)
			:_node(node)
		{}
	
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		/*Self& operator--(int)
				{
					Self tmp(*this);
					_node = _node->_prev;

					return tmp;
				}*/

		T& operator*()
		{
			return _node->_data;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

	
		Node* _node;
	};


	template <class T>
	class list
	{
		typedef ListNode<T> Node;
		
	public:
		typedef list_iterator<T> iterator;

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		iterator begin()
		{
			iterator it(_head);
			++it;
			return it;
		}
		
		iterator end()
		{
			
			return iterator(_head);
		}


		void push_back(const T& x)
		{
			//Î²²å   tail  newnode
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end(), x);
		}

		/*bool empty() const
		{
			return _head->_next == _head;
		}*/

		void pop_back()
		{
			erase(--end());
			
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			
			//  prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			// prev cur next
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}
	private:
		Node* _head;
	};



	void test_list1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);

		//l1.insert(l1.begin(), 9);

		l1.erase(--l1.end());

		//
		//l1.pop_back();

		//l1.push_front(3);
		//l1.pop_front();
		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << endl;
			++it;
		}
		cout << endl;
	}
}
