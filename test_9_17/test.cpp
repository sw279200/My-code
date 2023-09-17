#define _CRT_SECURE_NO_WARNINGS 1

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void test_vector1()
{
	vector<int> v1(10, 0);
	vector<int> v2(v1);
	string str("hello world");

	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(str.begin(), str.end());

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;


	for (int a : v3)
	{
		cout << a << " ";
	}
	cout << endl;

	for (int b : v4)
	{
		cout << b << " ";
	}
	cout << endl;
}

void test_vector2()
{
	vector<int> v;
	//v.reserve(100);直接控制容量，就不需要再扩容
	//v.resize(100);还需要扩容
	size_t sz = v.capacity();
	cout << "making v grow:" << endl;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "after changing capacity:" << v.capacity() << endl;
		}

	}

} 

void test_vector3()
{
	vector<int> v1;
	cout << v1.max_size() << endl;

	//v1.reserve(100);  size = 0 , capacity = 100
	v1.resize(100); // size  = 100 , capacity = 100;

	for (int i = 0; i < 100; i++)
	{
		v1[i] = i;
	}

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector4()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);

	for (int x : v1)
	{
		cout << x << " ";
	}
	cout << endl;

	v1.insert(v1.begin(), 10);
	for (int x : v1)
	{
		cout << x << " ";
	}
	cout << endl;

	vector<int>::iterator it = find(v1.begin(), v1.end(), 5);
	if (it != v1.end())
	{
		v1.insert(it, 50);
	}

	for (int x : v1)
	{
		cout << x << " ";
	}
	cout << endl;

	it = find(v1.begin(), v1.end(), 5);
	if (it != v1.end())
	{
		v1.erase(it);
	}

	for (int x : v1)
	{
		cout << x << " ";
	}
	cout << endl;


	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	//v1.clear();//capacity 不变 size = 0
	v1.shrink_to_fit(); //把capacity缩容到size大小;
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;


}
int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	test_vector4();
	return 0;
}