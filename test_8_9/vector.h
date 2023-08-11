#pragma once

#include<assert.h>
#include<iostream>
#include<vector>
#include<string>

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
		{}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		// v2(v1)
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		// v1 = v3
		vector<T>& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();

				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		// T int
		// T string
		// T vector<int>
		//void resize(size_t n, T val = T())
		void resize(size_t n, const T& val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void push_back(const T& x)
		{/*
			if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			++_finish;*/

			insert(end(), x);
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}


		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			*it *= 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		int i = 0;
		int j(1);
		int k = int(2);

		vector<int*> v1;
		v1.resize(10);

		vector<string> v2;
		//v2.resize(10, string("xxx"));
		v2.resize(10, "xxx");

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin() + 2;
		v.insert(it, 30);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		//v.insert(v.begin(), 30);
		v.insert(v.begin() + 3, 30);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = v.begin();
		v.erase(pos);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin() + 3);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	//void test_vector5()
	//{
	//	// 1 2 3 4 5
	//	// 1 2 3 4 5 6
	//	// 2 2 3 4 5
	//	std::vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);
	//	//v.push_back(6);

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//	auto it = v.begin();
	//	while (it != v.end())
	//	{
	//		// vs2019进行强制检查，erase以后认为it失效了，不能访问，访问就报错
	//		if (*it % 2 == 0)
	//		{
	//			v.erase(it);
	//		}

	//		++it;
	//	}

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}

	void test_vector5()
	{
		//std::vector<int> v;
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<string> v;
		v.push_back("111111111111111111111");
		v.push_back("111111111111111111111");
		v.push_back("111111111111111111111");
		v.push_back("111111111111111111111");
		v.push_back("111111111111111111111");


		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void test_vector7()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);

		vector<int> v2(v1);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);
		v3.push_back(40);

		v1 = v3;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector8()
	{
		//vector<int> v0(10, 0);
		vector<string> v1(10, "xxxx");

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2;
		v2.push_back(10);
		v2.push_back(20);
		v2.push_back(30);
		v2.push_back(40);

		vector<int> v3(v2.begin(), v2.end());

		string str("hello world");
		vector<int> v4(str.begin(), str.end());
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
