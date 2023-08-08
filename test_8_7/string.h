#pragma once
#include<assert.h>
#include <cstring>
#include<iostream>
using namespace std;
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		/*string()
			:_str(new char[1]{'\0'})
			,_size(0)
			,_capacity(0)
		{}*/

		// 16:05
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 传统写法
		// s2(s1)
		//string(const string& s)
		//{
		//	_str = new char[s._capacity+1];
		//	strcpy(_str, s._str);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}


		//// s2 = s3
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);

		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		// s2 = s3
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		//this->swap(tmp);
		//		swap(tmp);
		//	}

		//	return *this;
		//}

		// s2 = s3
		string& operator=(string tmp)
		{
			swap(tmp);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
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

		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				while (_size < n)
				{
					_str[_size] = ch;
					++_size;
				}

				_str[_size] = '\0';
			}
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* sub, size_t pos = 0)
		{
			const char* p = strstr(_str + pos, sub);
			if (p)
			{
				return p - _str;
			}
			else
			{
				return npos;
			}
		}

		string substr(size_t pos, size_t len = npos)
		{
			string s;
			size_t end = pos + len;
			if (len == npos || pos + len >= _size) // 有多少取多少
			{
				len = _size - len;
				end = _size;
			}

			s.reserve(len);
			for (size_t i = pos; i < end; i++)
			{
				s += _str[i];
			}

			return s;
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
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

		// insert(0, 'x')
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			// 17:17
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// 挪动数据
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t begin = pos + len;
				while (begin <= _size)
				{
					_str[begin - len] = _str[begin];
					++begin;
				}
				_size -= len;
			}
		}

		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		//const static size_t npos = -1;  // 特例
		//const static double npos = 1.1;  // 不支持
	public:
		const static size_t npos;
	};

	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		/*for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}*/
		for (auto ch : s)
			out << ch;

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		// 17:15继续
		s.clear();
		//s.reserve(128);

		char buff[129];
		size_t i = 0;

		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 128)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			//s += ch;

			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	void test_string1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)++;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto& ch : s1)
		{
			ch++;
			cout << ch << " ";
		}
		cout << endl;

		cout << s1.c_str() << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		s1.push_back(' ');
		s1.append("hello bit hello bit");

		cout << s1.c_str() << endl;

		s1 += '#';
		s1 += "*********************";
		cout << s1.c_str() << endl;

		string s2;
		s2 += '#';
		s2 += "*********************";
		cout << s2.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.insert(5, '%');
		cout << s1.c_str() << endl;

		s1.insert(s1.size(), '%');
		cout << s1.c_str() << endl;

		s1.insert(0, '%');
		cout << s1.c_str() << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		string s2("hello world");

		cout << (s1 >= s2) << endl;

		s1[0] = 'z';
		cout << (s1 >= s2) << endl;

		cout << s1 << endl;
		cin >> s1;
		cout << s1 << endl;

		/*char ch1, ch2;
		cin >> ch1 >> ch2;*/
	}

	void test_string5()
	{
		string s1("hello world");
		s1.insert(5, "abc");
		cout << s1 << endl;

		s1.insert(0, "xxx");
		cout << s1 << endl;

		s1.erase(0, 3);
		cout << s1 << endl;

		s1.erase(5, 100);
		cout << s1 << endl;

		s1.erase(2);
		cout << s1 << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		cout << s1 << endl;

		s1.resize(5);
		cout << s1 << endl;

		s1.resize(25, 'x');
		cout << s1 << endl;
	}

	void test_string7()
	{
		string s1("test.cpp.tar.zip");
		//size_t i = s1.find('.');
		//size_t i = s1.rfind('.');

		//string s2 = s1.substr(i);
		//cout << s2 << endl;

		string s3("https://legacy.cplusplus.com/reference/string/string/rfind/");
		//string s3("ftp://www.baidu.com/?tn=65081411_1_oem_dg");
		// 协议
		// 域名
		// 资源名

		string sub1, sub2, sub3;
		size_t i1 = s3.find(':');
		if (i1 != string::npos)
			sub1 = s3.substr(0, i1);
		else
			cout << "没有找到i1" << endl;

		size_t i2 = s3.find('/', i1 + 3);
		if (i2 != string::npos)
			sub2 = s3.substr(i1 + 3, i2 - (i1 + 3));
		else
			cout << "没有找到i2" << endl;

		sub3 = s3.substr(i2 + 1);

		cout << sub1 << endl;
		cout << sub2 << endl;
		cout << sub3 << endl;
	}

	void test_string8()
	{
		string s1("hello world");
		string s2 = s1;
		cout << s1 << endl;
		cout << s2 << endl;

		string s3("xxxxxxxxxxxxxxxxxxx");
		s2 = s3;

		cout << s2 << endl;
		cout << s3 << endl;
	}

	void test_string9()
	{
		string s1("hello world");
		cin >> s1;
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
	}
}