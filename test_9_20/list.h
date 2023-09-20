#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;
namespace mylist 
{
	template<class T>
	struct list_node 
	{
		T _data;
		list_node<T>* _prev;
		list_node<T>* _next;

		list_node(const T& val = T())
			:_data(val)
			, _prev(nullptr)
			, _next(nullptr)
		{ }
	};

	// T T& T*
	// T cosnt T& const T*
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> _self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{

		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		_self& operator++()
		{
			_node = _node->_next;
			return (*this);
		}

		_self& operator--()
		{
			_node = _node->_prev;
			return (*this);
		}

		_self operator++(int)
		{
			Node* tmp(_node);
			_node = _node->_next;

			return tmp;
		}

		_self operator--(int)
		{
			Node* tmp(_node);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const _self& n)
		{
			return this->_node != n._node;
		}

		bool operator==(const _self& n)
		{
			return this->_node == n._node;
		}

	};


	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:

		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;


		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
			
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return (_head->_next);
		}

		iterator end()
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}

		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list()
		{
			empty_init();
		}

		//lt1(lt2)
		list(const list<T>& lt)
		{

			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}


		list<int>& operator=(list<int>lt)
		{
			swap(lt);
			return *this;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}


		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back(const T& x)
		{
			erase(--end());
		}


		void pop_front(const T& x)
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;
			return iterator(newnode);

		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;
			prev->_next = next;
			next->_prev = prev;
			--_size;
			return iterator(next);
		}


		size_t size()
		{
			return _size;
		}


	private:
		Node* _head;
		size_t _size;

	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		// 封装屏蔽底层差异和实现细节
		// 提供统一的访问修改遍历方式
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it += 20;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		/*set<int> s;
		s.insert(1);
		s.insert(3);
		s.insert(2);
		s.insert(4);

		set<int>::iterator sit = s.begin();
		while (sit != s.end())
		{
			cout << *sit << " ";
			++sit;
		}
		cout << endl;*/
	}

	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int> lt1(lt);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2;
		lt2.push_back(10);
		lt2.push_back(200);
		lt2.push_back(30);
		lt2.push_back(40);
		lt2.push_back(50);

		lt1 = lt2;
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	struct AA
	{
		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}

		int _a1;
		int _a2;
	};

	void test_list3()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));

		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1<<" "<<(*it)._a2 << endl;
			cout << it->_a1 << " " << it->_a2 << endl;
			cout << it.operator->()->_a1 << " " << it.operator->()->_a1 << endl;


			++it;
		}
		cout << endl;

		int* p = new int;
		*p = 1;

		AA* ptr = new AA;
		ptr->_a1 = 1;

	}

	//void print_list(const list<int>& lt)
	//{
	//	list<int>::const_iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		//*it = 10;
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;

	//	for (auto e : lt)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}


	//void print_list(const list<int>& lt)
	//{
	//	list<int>::const_iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		//*it = 10;
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;

	///*	for (auto e : lt)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;*/
	//}

	// 实例化
	//template<typename T>
	////template<class T>
	//void print_list(const list<T>& lt)
	//{
	//	// list<T>未实例化的类模板，编译器不能去他里面去找
	//	// 编译器就无法list<T>::const_iterator是内嵌类型，还是静态成员变量
	//	// 前面加一个typename就是告诉编译器，这里是一个类型，等list<T>实例化
	//	// 再去类里面去取
	//	typename list<T>::const_iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;
	//}

	// 模板(泛型编程)本质，本来应该由我们干的活交给编译器
	template<typename Container>
	void print_container(const Container& con)
	{
		typename Container::const_iterator it = con.begin();
		while (it != con.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		//print_list(lt);
		print_container(lt);

		list<string> lt1;
		lt1.push_back("1111111111111");
		lt1.push_back("1111111111111");
		lt1.push_back("1111111111111");
		lt1.push_back("1111111111111");
		lt1.push_back("1111111111111");
		//print_list(lt1);
		print_container(lt1);

		vector<string> v;
		v.push_back("222222222222222222222");
		v.push_back("222222222222222222222");
		v.push_back("222222222222222222222");
		v.push_back("222222222222222222222");
		//print_list(v);
		print_container(v);
	}

}