#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

//template<class T,size_t N>
//class Stack
//{
//private:
//	T _a[N];
//};
//
//int main()
//{
//	Stack<int,10> st1; //10
//	Stack<int,10000> st2;  //10000
//	
//	return 0;
//}


//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////特化
//template<>
//class Data<int, double>
//{
//public:
//	Data() { cout << "Data<int, double>" << endl; }
//private:
//	int _d1;
//	double _d2;
//};
//
//
//int main()
//{
//	Data<int, int>d1;
//	Data<int, double>d2;
//	return 0;
//}


class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    bool operator<(const Date& d) const
    {
        return (_year < d._year) ||
            (_year == d._year && _month < d._month) ||
            (_year == d._year && _month == d._month && _day < d._day);
    }

    bool operator>(const Date& d) const
    {
        return (_year > d._year) ||
            (_year == d._year && _month > d._month) ||
            (_year == d._year && _month == d._month && _day > d._day);
    }

    friend ostream& operator<<(ostream& _cout, const Date& d);
private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
    _cout << d._year << "-" << d._month << "-" << d._day;
    return _cout;
}

struct PDateCompare
{
    bool operator()(Date* p1, Date* p2)
    {
        return *p1 > *p2;
    }
};

// 函数模板 -- 参数匹配
template<class T>
bool Less(T left, T right)
{
	return left < right;
}
//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//	return 0;
//}

#include"Stack.h"

int main()
{
    Add(1, 2);
    func();
    return 0;
}