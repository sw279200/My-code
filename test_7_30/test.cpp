#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <iostream>
using namespace std;
#if 0
struct SeqList
{
public:
	void push_back(int x)
	{
		_a[_size++] = x;
	}

	//读
	const int& operator[](size_t i)const
	{
		assert(i < _size);
		return _a[i];
	}
	//构成函数重载
	//写
	int& operator[](size_t i)
	{
		assert(i < _size);
		return _a[i];
	}

	size_t size() const
	{
		return this->_size;
	}

	
private:
	int* _a = (int*)malloc(sizeof(int) * 10);
	size_t _size = 0;
	size_t _capacity = 0;
};

void PrintArr(const SeqList &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		//cout << s.operator[](i) << " ";
		cout << s[i] << " ";
	}
	cout << endl;
}

int main()
{
	SeqList s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	PrintArr(s);

	for (size_t i = 0; i < s.size(); i++)
	{
		s[i]++;
	}
	PrintArr(s);

	
	return 0;
}
#endif


class Date
{
public:

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in,  Date& d);

	Date(int year, int month, int day,int& i)
		//初始化列表
		:_year(year)
		,_month(month)
		,_x(1)
		,refi(i)
	{
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
	const int _x;
	int& refi;
};


ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}


int main()
{
	int m = 0;
	int& i = m;
	Date d1(2023, 7, 30,m);
	Date d2(1,1,1,m);
	cout << "请输入一个日期：" << endl;
	cin >> d2;
	cout << d2;
	cout << d1;
	return 0;
}