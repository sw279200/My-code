#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include <vector>
#include <algorithm>

//常用遍历算法

//普通函数
void Print(int val)
{
	cout << val<<" ";
}

//仿函数
class Print1
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//遍历算法
void Test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), Print);
	cout << endl;
	for_each(v.begin(), v.end(), Print1());
	cout << endl;
}

class TransForm
{
public:
	int operator()(int v)
	{
		return v;
	}
};

class Print3
{
public:
	void operator()(int val)
	{
		cout << val <<" ";
	}
};


void Test2()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int> vDest;//目标容器
	vDest.resize(v.size());//目标容器需要提前开空间

	transform(v.begin(), v.end(), vDest.begin(), TransForm());
	for_each(vDest.begin(), vDest.end(), Print3());

}

int main()
{
	//Test1();
	Test2();
	return 0;
}