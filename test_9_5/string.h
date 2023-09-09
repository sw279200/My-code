#pragma once
#include <assert.h>
namespace xiaobai
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

		char& operator[](size_t n)
		{
			assert(n < _size);
			return _str[n];
		}

		const char& operator[](size_t n) const
		{
			assert(n < _size);
			return _str[n];
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
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
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			_size++;
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


		// 在pos位置上插入字符c/字符串str，并返回该字符的位置

		string& insert(size_t pos, char c)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			size_t end = _size + 1;

			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = c;
			_size++;

			return *this;

		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			
			size_t len = strlen(str);
			size_t end = _size +len +1;
			if (end> _capacity)
			{
				reserve(end);
			}
			while (end > pos)
			{
				_str[end] = _str[end - strlen(str)-1];
				end--;
			}

			// 拷贝插入
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;

		}

		string& erase(size_t pos, size_t len = npos)
		{
			if (len == npos || pos + len >= _size)    //pos开始到结尾都要删除
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				memmove(_str + pos, _str + pos + len, len);
				_size -= len;
			}
			return *this;
		}

		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator<=(const string& s) const
		{
			return (*this < s)||(*this==s);
		}

		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator!=(const string& s) const
		{
			return (!(*this == s));
		}



		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t  _size;
		size_t _capacity;
		const static size_t npos;
	};

	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& str)
	{
		for (auto ch : str)
		{
			out << ch;
		}

		return out;
	}

	istream& operator>>(istream& in,string& str)
	{
		str.clear();
		char ch;
		ch = in.get();
		str.reserve(128);
		while (ch != ' ' && ch != '\n')
		{
			if (str.size() == str.capacity())
			{
				str.reserve(str.capacity() * 2);
			}
			str += ch;
		}


		return in;
	}

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

	void test_string3()
	{
		string s1("hello bit!");
		cout<<s1.insert(5, '#')<<endl;
		cout << s1 << endl;
		cout << s1.insert(3, "hello xiaobai") << endl;
		cout << s1 << endl;
		cout<<s1.erase(2)<<endl;
		cout << s1 << endl;
		cout << (s1 > "hello world") << endl;
		cout << (s1 < "hello world") << endl;
		cout << (s1 <= "hello world") << endl;
		cout << (s1 >= "hello world") << endl;
		cout << (s1 == "hello world") << endl;
		cout << (s1 != "hello world") << endl;
		cout << s1.insert(1,'#')<<endl;
		cout << s1 << endl;
	}
}
