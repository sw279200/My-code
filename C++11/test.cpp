#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<array>
#include<algorithm>
#include<functional>
using namespace std;

#include<assert.h>

struct Point
{
	int _x;
	int _y;
};

// 列表初始化
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

// 一切都可以用列表初始化
// 并且可以省略掉=
//int main()
//{
//	int i = 0;
//	int j = { 0 };
//	int k{ 0 };
//
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//
//	Date d1(2023, 11, 25);
//
//	// 类型转换  构造+拷贝构造-》优化直接构造
//	Date d2 = { 2023, 11, 25 };
//	Date d3{ 2023, 11, 25 };
//
//	string s1 = "xxxx";
//
//	const Date& d4 = { 2023, 11, 25 };
//
//	Date* p1 = new Date[3]{ d1, d2, d3 };
//	Date* p2 = new Date[3]{ {2022, 11, 25}, {2022, 11, 26}, {2022, 11, 27} };
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1,2,3,4 };
//	vector<int> v2 = { 1,2,3,4,5,6};
//
//	v1 = { 10,20,30 };
//
//	list<int> lt = { 10,20,30 };
//
//	// 多参数构造类型转换  构造+拷贝构造-》优化直接构造
//	// 跟对应构造函数参数个数匹配
//	Date d2 = { 2023, 11, 25 };
//
//	// the type of il is an initializer_list 
//	auto il1 = { 10, 20, 30, 40, 50 };
//	cout << typeid(il1).name() << endl;
//
//	initializer_list<int> il2 = { 10, 20, 30};
//
//	initializer_list<int>::iterator it2 = il2.begin();
//	while (it2 != il2.end())
//	{
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//	
//	//for (int e : il2)
//	for (auto e : il2)
//	{
//		cout << e << " ";
//	}
//	cout<< endl;
//
//	pair<string, string> kv1("sort", "排序");
//	map<string, string> dict = {{"insert", "插入"}, {"get","获取"} };
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	Date dd2 = { 2023, 11, 25 };
//	//Date dd3 = { 2023, 11, 25, 20};
//
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	double d = 2.2;
//
//	// 类型以字符串形式获取到
//	cout << typeid(i).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	// typeid(i).name() j;
//	auto j = i;
//
//	auto ret = i * d;
//	decltype(ret) x;
//
//	// 16:06继续
//	// 用ret的类型去实例化vector
//	// decltype可以推导对象的类型。这个类型是可以用
//	// 用来模板实参，或者再定义对象
//	vector<decltype(ret)> v;
//	v.push_back(1);
//	v.push_back(1.1);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}

//int main()
//{
//	array<int, 10> a1;
//	cout << sizeof(a1) << endl;
//	//a1[10];
//
//	vector<int> v(10, 0);
//	cout << sizeof(v) << endl;
//
//	int i = 0;
//	int j = i;
//
//	// 以下几个都是常见的右值
//	10;
//	i + j;
//	fmin(i, j);
//}

//int main()
//{
//	int i = 0;
//	int j = i;
//	
//	// 左值引用能否给右值取别名？不能，但是const左值引用可以
//	const int& r1 = 10;
//	const int& r2 = i + j;
//
//	int&& rr1 = 10;
//	int&& rr2 = i+j;
//
//	// 右值引用能否给左值取别名？不能，但是右值引用可以给move(左值)取别名
//	int&& rr3 = move(i);
//
//	return 0;
//}

namespace bit
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

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str) -- 构造" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			/*string tmp(s._str);
			swap(tmp);*/
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
		}

		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动拷贝" << endl;

			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 深拷贝" << endl;
			/*string tmp(s);
			swap(tmp);*/
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);

				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s)-- 移动赋值" << endl;

			swap(s);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
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
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0; // 不包含最后做标识的\0
	};

	bit::string to_string(int x)
	{
		bit::string ret;
		while (x)
		{
			int val = x % 10;
			x /= 10;
			ret += ('0' + val);
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
}

//int main()
//{
//	//bit::string s = bit::to_string(1234);
//
//	bit::string s1("hello world");
//	bit::string s2 = s1;
//
//	move(s1);
//	bit::string s3 = s1;
//
//	return 0;
//}

//#include"list.h"

//int main()
//{
//	bit::list<bit::string> lt;
//
//	bit::string s1("hello world");
//	lt.push_back(s1);
//	
//	lt.push_back(bit::to_string(12334));
//
//	lt.push_back("111111");
//
//	return 0;
//}

// 20:00继续
void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }

void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

// 函数模板：万能引用
template<typename T>
void PerfectForward(T&& t)
{
	// 期望保持实参的属性呢！
	// 完美转发
	Fun(forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
//
//	return 0;
//}

// 以下代码在vs2013中不能体现，在vs2019下才能演示体现上面的特性。
class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	/*Person(const Person& p)
		:_name(p._name)
		,_age(p._age)
	{}*/

	/*Person& operator=(const Person& p)
	{
		if(this != &p)
		{
			_name = p._name;
			_age = p._age;
		}
		return *this;
	}*/

	// 不让生成实现
	//Person(Person&& p) = delete;

	// 强制编译器生成
	Person(Person&& p) = default;
	Person(const Person& p) = default;

	~Person()
	{
		cout << "~Person()" << endl;
	}
private:
	bit::string _name;
	int _age;
};

//int main()
//{
//	Person s1;
//	Person s2 = s1;			   // 默认的拷贝构造
//	Person s3 = std::move(s1); // 默认的移动构造
//
//	//Person s4;
//	//s4 = std::move(s2);
//
//	return 0;
//}

 // Args是一个模板参数包，args是一个函数形参参数包
 // 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// 不支持这么玩
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " ";
//	}
//	cout << endl;
//}

//void _ShowList()
//{
//	cout << endl;
//}
//// 21:07继续
//// 编译时的递归推演
//// 第一个模板参数依次解析获取参数值
//template <class T, class ...Args>
//void _ShowList(const T& val, Args... args)
//{
//	cout << val << " ";
//	_ShowList(args...);
//}
//
//template <class ...Args>
//void ShowList(Args... args)
//{
//	_ShowList(args...);
//}
//
//int main()
//{
//	ShowList(1);
//	ShowList(1, 2);
//	ShowList(1, 2, 3);
//	ShowList(1, 2.2, 'x', 3.3);
//
//	return 0;
//}

template <class T>
int PrintArg(T&& t)
{
	cout << t << " ";
	return 0;
}

//展开函数
template <class ...Args>
void ShowList(Args&&... args)
{
	// 要初始化arr，强行让解析参数包，参数包有一个参数，PrintArg就依次推演生成几个
	int arr[] = { PrintArg(args)... };
	cout << endl;
}

//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

//int main()
//{
//	std::list<bit::string> lt;
//	bit::string s1("1111");
//	lt.push_back(s1);
//	lt.push_back(move(s1));
//
//	bit::string s2("1111");
//	lt.emplace_back(s2);
//	lt.emplace_back(move(s2));
//
//	cout << endl;
//	lt.push_back("xxxx");
//	lt.emplace_back("xxxx");
//
//	return 0;
//}

//int main()
//{
//	std::list<pair<bit::string, int>> lt;
//	lt.push_back(make_pair("1111", 1));
//
//	lt.emplace_back("2222", 2);
//	//lt.emplace_back(make_pair("1111", 1));
//
//	//pair<bit::string, int> kv("1111", 1);
//	//lt.emplace_back(kv);
//
//	return 0;
//}

//int main()
//{
//	bit::list<pair<bit::string, int>> lt
//	cout << endl;
//
//	lt.push_back(make_pair("1111", 1));
//	lt.emplace_back("2222", 2);
//
//	return 0;
//}

struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	//...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};


struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	//sort(v.begin(), v.end(), ComparePriceLess());
//	//sort(v.begin(), v.end(), ComparePriceGreater());
//
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate < g2._evaluate; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate > g2._evaluate; });
//
//	return 0;
//}

//int main()
//{
//	// 匿名函数对象
//	// class <lambda_ba37a3eb9b8e2495e3aae6ef76d9eed2>
//	// <lambda_uuid>
//	auto f1 = [](int x)->int {cout << x << endl; return 0; };
//	f1(1);
//	cout << typeid(f1).name() << endl;
//
//	//class <lambda_8c5f46db939004e569f343c4f7d08c27>
//	auto f2 = [](int x)
//	{
//		cout << x << endl;
//		return 0;
//	};
//	f2(2);
//
//	//f1 = f2;
//
//	cout << typeid(f2).name() << endl;
//
//	ComparePriceGreater f3;
//	cout << typeid(f3).name() << endl;
//
//	return 0;
//}

//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//
//	auto f1 = [](int& r1, int& r2) {
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	};
//
//	f1(x, y);
//	cout << x << " " << y << endl << endl;
//
//
//	cout << x << " " << y << endl;
//	cout << &x << ":" << &y << endl;
//
//	// <lambda_uuid>
//	// 10:35继续
//	auto f2 = [x, y]() mutable {
//		cout << &x << ":" << &y << endl;
//
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	f2();
//	cout << x << " " << y << endl << endl;
//
//	cout << x << " " << y << endl;
//	cout << &x << ":" << &y << endl;
//	auto f3 = [&x, &y]() {
//		cout << &x << ":" << &y << endl;
//
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	f3();
//	cout << x << " " << y << endl << endl;
//	return 0;
//}

//class AA
//{
//public:
//	void func()
//	{
//		/*auto f1 = [this]() {
//			cout << a1 << endl;
//			cout << a2 << endl;
//		};*/
//		auto f1 = [=]() {
//			cout << a1 << endl;
//			cout << a2 << endl;
//		};
//
//		f1();
//	}
//private:
//	int a1 = 1;
//	int a2 = 1;
//};
//
//
//int main()
//{
//	int x = 0, y = 1, z = 2;
//
//	auto f1 = [=, &z]() {
//		z++;
//
//		cout << x << endl;
//		cout << y << endl;
//		cout << z << endl;
//	};
//
//	f1();
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////
// 包装器
void swap_func(int& r1, int& r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

struct Swap
{
	void operator()(int& r1, int& r2)
	{
		int tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
};

//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//
//	auto swaplambda = [](int& r1, int& r2) {
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	};
//
//	function<void(int&, int&)> f1 = swap_func;
//	f1(x, y);
//	cout << x << " " << y << endl << endl;
//
//	function<void(int&, int&)> f2 = Swap();
//	f2(x, y);
//	cout << x << " " << y << endl << endl;
//
//	function<void(int&, int&)> f3 = swaplambda;
//	f3(x, y);
//	cout << x << " " << y << endl << endl;
//
//	// 11:40继续
//	map<string, function<void(int&, int&)>> cmdOP = {
//		{"函数指针", swap_func},
//		{"仿函数", Swap()},
//		{"lambda", swaplambda},
//	};
//
//	cmdOP["函数指针"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	cmdOP["仿函数"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	cmdOP["lambda"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	return 0;
//}

int f(int a, int b)
{
	return a + b;
}

struct Functor
{
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a + b;
	}
};

int main()
{
	// 成员函数取地址，比较特殊，要加一个类域和&
	function<int(int, int)> f1 = &Plus::plusi;
	cout << f1(1, 2) << endl;

	function<double(Plus*, double, double)> f2 = &Plus::plusd;
	Plus ps;
	cout << f2(&ps, 1.1, 2.2) << endl;

	function<double(Plus, double, double)> f3 = &Plus::plusd;
	cout << f3(Plus(), 1.11, 2.22) << endl;

	function<double(double, double)> f4 = bind(&Plus::plusd, Plus(), placeholders::_1, placeholders::_2);
	cout << f4(1.11, 2.22) << endl;

	return 0;
}

int Sub(int a, int b)
{
	return a - b;
}

//int main()
//{
//	function<int(int, int)> f1 = Sub;
//	cout << f1(10, 5) << endl;
//
//	// 调整参数顺序
//	function<int(int, int)> f2 = bind(Sub, placeholders::_2, placeholders::_1);
//	cout << f2(10, 5) << endl;
//
//	// 调整参数个数，有些参数可以bind时写死
//	function<int(int)> f3 = bind(Sub, 20, placeholders::_1);
//	cout << f3(5) << endl;
//
//	return 0;
//}