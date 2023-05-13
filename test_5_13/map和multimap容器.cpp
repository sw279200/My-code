#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

#include <map>

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key :" << it->first << " value :" << it->second << endl;
	}
	cout << endl;
}

//map容器构造和赋值
void Test1()
{
	//默认构造
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	cout << "-------------------" << endl;
	//拷贝构造
	map<int, int>m1(m);
	printMap(m1);
	cout << "-------------------" << endl;

	//等号赋值
	map<int, int>m2;
	m2 = m1;
	printMap(m2);
	
}

//大小和交换
void Test2()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为：" << m.size() << endl;
	}

	map<int, int>m0;
	m0.insert(pair<int, int>(5, 100));
	m0.insert(pair<int, int>(6, 200));
	m0.insert(pair<int, int>(7, 300));
	m0.insert(pair<int, int>(8, 400));

	//交换前
	cout << "交换前：" << endl;
	printMap(m);
	printMap(m0);

	//交换后
	cout << "交换后：" << endl;
	m.swap(m0);
	printMap(m);
	printMap(m0);

}

//map容器插入和删除
void Test3()
{
	map<int, int>m;
	//插入
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));

	//第二种插入方式
	m.insert(make_pair(2, 20));

	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));

	//第四种插入方式
	m[4] = 40; //不建议使用[]的方式来进行插入，[]适合用在通过key来找出对应的value

	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//清空
	//m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}


//map容器的查找和统计
void Test4()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	map<int, int>::iterator pos = m.find(4);

	if (pos != m.end())
	{
		cout << "找到了，key = " << pos->first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "未找到该元素" << endl;
	}


	//统计，map不允许插入重复key元素，count统计而言，结果要么为0，要么为1
	//multimap的count统计可能大于1
	int num = m.count(3);
	cout << "num = " << num << endl;
}

class MyCmp
{
public:
	bool operator()(int v1, int v2) const
	{
		//降序
		return v1 > v2;
	}
};

void Test5()
{
	
	map<int, int,MyCmp>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	for (map<int, int, MyCmp>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	return 0;
}

#endif