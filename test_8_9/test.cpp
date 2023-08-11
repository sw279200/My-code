#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>

using namespace std;

#include "vector.h"

void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 0);

	vector<int> v3(v2.begin(), v2.end());
	string str("hello world");
	vector<int> v4(str.begin(), str.end());
	vector<int> v5(v4);

	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	//vector<int>::iterator it = v4.begin();
	auto it = v4.begin();
	while (it != v4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	size_t sz;
	vector<int> v;
	v.reserve(100);
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector3()
{
	vector<int> v1;
	cout << v1.max_size() << endl;

	vector<int> v;
	//v.reserve(100);  // size = 0    capacity 100
	v.resize(100);     // size = 100  capacity 100

	for (size_t i = 0; i < 100; i++)
	{
		v[i] = i;
	}

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

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin(), 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	auto it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		v.insert(it, 30);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		v.erase(it);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.clear();
	v.shrink_to_fit();

	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

int main()
{
	//test_vector4();

	bit::test_vector8();

	return 0;
}