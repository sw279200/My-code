#pragma once
#include <assert.h>
namespace xiaobai
{
	class string
	{
	public:

		typedef char* iterator;
			
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		char operator[](size_t n)
		{
			return _str[n];
		}

		string(const char* str = "")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		size_t size() const
		{
			return _size;
		}

		const char* c_str() const
		{
			return _str;
		}

		void reserve(size_t n)
		{

			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;

			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';

		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size +len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;

		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

	private:
		char* _str;
		size_t  _size;
		size_t _capacity;
	};

	void test_string1()
	{
		string str1("hello world");
		cout << str1.c_str()<< endl;

		for (size_t i = 0; i < str1.size(); i++)
		{
			cout << str1[i] << " ";
		}
		cout << endl;

		string::iterator it = str1.begin();
		while (it != str1.end())
		{
			cout << *it << " ";
			it++;

		}
		cout << endl;


		for (auto ch : str1)
		{
			cout << ch << " ";

		}
		cout << endl;


	}

	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		s1.push_back(' ');
		s1.append("hello bit");
		s1 += '#';
		s1 += "hello linux";
		cout << s1.c_str() << endl;
	}
}
