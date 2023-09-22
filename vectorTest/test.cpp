#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

//void Test_vector1()
//{
//	vector<int> v;
//	for (size_t i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	cout << "尾插数据后：" << endl;
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";//像数组一样用[]访问vector中的元素
//	}
//	cout << endl;
//
//	v.pop_back();
//	v.pop_back();
//	cout << "尾删两个数据后：" << endl;
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	cout << "在下标为3的前面插入一个30" << endl;
//	vector<int>::iterator it = v.begin();
//	v.insert(it+3, 30);//在下标为3的前面插入一个30
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	cout << "删除it位置的数" << endl;
//	it = v.erase(it+3);//删除it位置的数，并把该位置被删除的后面的数的迭代器返回给it
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//}
//
//void Test_vector2()
//{
//	size_t sz;
//	vector<int> v;
//	sz = v.capacity();
//	cout << "making v grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//void Test_vector3()
//{
//	vector<int> v;
//	size_t sz = v.capacity();
//	v.reserve(100); // 提前将容量设置好，可以避免一遍插入一遍扩容
//	cout << "making bar grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//
//void Test_vector4()
//{
//	vector<int> v;
//	for (size_t i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	cout << "第一种用[]进行遍历：" << endl;
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//
//	cout << endl;
//
//	cout << "第二种用迭代器进行遍历：" << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	cout << "第三种用范围for进行遍历：" << endl;
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}


#include"vector.h"
void test_vector1()
{
	simulation::vector<int> v;
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

	simulation::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{

		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	simulation::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);

	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin() + 3, 40);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin(), 100);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.end(), 1000);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.end() - 1);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	simulation::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	simulation::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector4()
{
	simulation::vector<string> v;
	v.push_back("666666666666666");
	v.push_back("666666666666666");
	v.push_back("666666666666666");
	v.push_back("666666666666666");
	v.push_back("666666666666666");

	for (auto s : v)
	{
		cout << s << " ";
	}
	cout << endl;

	simulation::vector<string> v1(v);
	for (auto s : v1)
	{
		cout << s << " ";
	}
	cout << endl;
	simulation::vector<int> v2;

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	for (auto s : v2)
	{
		cout << s << " ";
	}
	cout << endl;
	simulation::vector<int> v3;
	v3 = v2;
	for (auto s : v3)
	{
		cout << s << " ";
	}
	cout << endl;


	simulation::vector<int> v4(10, 0);
	for (auto s : v4)
	{
		cout << s << " ";
	}
	cout << endl;

	simulation::vector<string> v5(10, "xxx");
	for (auto s : v5)
	{
		cout << s << " ";
	}
	cout << endl;
}


int main()
{
	test_vector2();
	return 0;
}
