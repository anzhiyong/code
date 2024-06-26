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


	//���������
	template <class T, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef ListNode<T>* Iterator;
		typedef Reverse_iterator<T, Ref, Ptr> Self;
		Iterator _it;

		Reverse_iterator(Iterator it)
			: _it(it) 
		{}

		Ref operator*() {
			Iterator tmp = _it;
			return tmp->_prev->_data;
		}

		Ptr operator->() {
			return &(operator*());
		}

		Self& operator++() {
			_it = _it->_prev;
			return *this;
		}

		Self operator++(int) {
			Self tmp = *this;
			_it = _it->_prev;
			return tmp;
		}

		Self& operator--() {
			_it = _it->_next;
			return *this;
		}

		Self operator--(int) {
			Self tmp = *this;
			_it = _it->_next;
			return tmp;
		}

		bool operator==(const Self& other) const {
			return _it == other._it;
		}

		bool operator!=(const Self& other) const {
			return _it != other._it;
		}
	};
	


	//������
	template<class T, class Ref, class Ptr>
	//template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
	

		list_iterator(Node* node)
			:_node(node)
		{}
	
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator++(int)
		{
			Self tmp = *this;
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self& operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		/*Self& operator--(int)
				{
					Self tmp(*this);
					_node = _node->_prev;

					return tmp;
				}*/

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	
		Node* _node;
	};


	template <class T>
	class list
	{
		typedef ListNode<T> Node;
		
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		typedef Reverse_iterator<T, T&, T*> reverse_iterator;


		

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		iterator begin()
		{
			iterator it(_head->_next);
			return it;
		}

		reverse_iterator rbegin()
		{
			
			return reverse_iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		
		iterator end()
		{
			
			return iterator(_head);
		}

		reverse_iterator rend()
		{

			return reverse_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void push_back(const T& x)
		{
			//β��   tail  newnode
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

	void test_list2()
	{
		list<int> l2;
		l2.push_back(1);
		l2.push_back(2);
		l2.push_back(3);
		l2.push_back(4);

		list<int>::iterator it = l2.begin();
		while (it != l2.end())
		{
			cout << *it << endl;
			it++;
		}
	}

	void test_list3()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);

		list<int>::iterator it = --l1.end();
		while (it != --l1.begin())
		{
			cout << *it << endl;
			it--;
		}
	}
	void test_iterator()
	{
		list<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

	

	

		list<int>::reverse_iterator it = vec.rbegin();
		
		//it++;
		//cout << *it << endl;//3
		//it++;
		//cout << *it << endl;//2
		//it++;
		//cout << *it << endl;//1
		//it++;
		//cout << *it << endl;//
		//it++;
		//cout << *it << endl;
		//it++;
		while (it != vec.rend())
		{
			cout << *it << endl;
			++it;
		}
		
		cout << endl;


	}
}
