#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;
#include <set>

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//set容器构造函数和赋值
void Test1()
{
	set<int>st;
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);

	//插入元素时，默认排成升序
	printSet(st);

	//拷贝构造
	set<int> s1(st);
	printSet(s1);

	set<int> s2;
	s2 = s1;
	printSet(s2);

}

//set容器大小和排序
void Test2()
{
	set<int>st;
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);

	printSet(st);

	if (st.empty())
	{
		cout << "st为空" << endl;
	}
	else
	{
		cout << "st不为空" << endl;
		cout << "st的大小为：" << st.size() << endl;

	}

	//交换
	set<int> s;
	s.insert(100);
	s.insert(500);
	s.insert(300);
	s.insert(400);
	s.insert(200);
	s.insert(300);
	printSet(s);

	cout << "交换前：" << endl;
	printSet(st);
	printSet(s);

	cout << "交换后：" << endl;
	st.swap(s);
	printSet(st);
	printSet(s);
}

//插入和删除
void Test3()
{
	
	set<int>st;
	//插入
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);
	//遍历
	printSet(st);

	//删除
	st.erase(st.begin());
	printSet(st);

	st.erase(40);
	printSet(st);
	//清空
	//st.erase(st.begin(), st.end());
	st.clear();
	printSet(st);

}

//查找和统计
void Test4()
{
	set<int>st;
	//插入
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);

	set<int>::iterator pos = st.find(30);
	if (pos != st.end())
	{
		cout << "找到了，元素为：" << *pos << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	//统计
	int num = st.count(20);
	cout << "num = " << num << endl;
}

//set和multiset的区别
void Test5()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	ret = s.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}


	cout << "-------------------------------" << endl;
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(40);
	ms.insert(20); 
	ms.insert(30);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	int num = ms.count(10);
	cout << "num = " << num << endl;
}


//pair 对组的创建
void Test6()
{
	//第一种创建方式
	pair<string, int>p("Tom", 28);
	cout << "姓名：" << p.first << " 年龄：" << p.second << endl;

	//第二种创建方式
	pair<string, int>p1 = make_pair("Eric", 25);
	cout << "姓名：" << p1.first << " 年龄：" << p1.second << endl;
}


class MyCompare
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;
	}
};

//set容器排序,内置类型指定排序规则
void Test7()
{
	set<int>st;
	//插入
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);

	printSet(st);

	set<int, MyCompare>st0;
	st0.insert(10);
	st0.insert(50);
	st0.insert(30);
	st0.insert(40);
	st0.insert(20);

	for (set<int, MyCompare>::const_iterator it = st0.begin(); it != st0.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

class People
{
public:
	People(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	int m_Age;
	string m_Name;
};

//排序方式
class PeopleCmp
{
public:
	bool operator()(const People& p1, const People& p2) const
	{
		//按照年龄降序排序
		return p1.m_Age > p2.m_Age;
	}
};

//set容器排序,自定义数据类型指定排序规则
void Test8()
{
	set<People,PeopleCmp>s1;
	People p1("刘备", 29);
	People p2("关羽", 28);
	People p3("张飞", 27);
	People p4("赵云", 26);
	People p5("诸葛亮", 30);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);

	for (set<People, PeopleCmp>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	Test8();
	return 0;
}

#endif