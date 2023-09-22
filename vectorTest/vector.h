#pragma once

#include<assert.h>
#include<string.h>
#include<iostream>
using namespace std;
namespace  simulation
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

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
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


		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{

		}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		vector<T>& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}



		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];

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

		void resize(size_t n, const T& val = T())
		{
			if (n <= _finish)
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (n + _start > _finish)
				{
					*_finish = val;
					_finish++;
				}
			}
		}


		void  push_back(const T& x)
		{

			if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			_finish++;
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
				end--;
			}

			*pos = x;
			_finish++;

		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			_finish--;

			return pos;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}