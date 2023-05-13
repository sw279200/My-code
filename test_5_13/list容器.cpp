#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;
#include<list>
#include<string>

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//list容器的构造函数和赋值和交换
void Test1()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	printList(L);

	//区间构造
	list<int> L1(L.begin(), L.end());
	printList(L1);

	//n个elem的构造函数
	list<int>L2(5, 1000);
	printList(L2);

	//拷贝构造
	list<int> L3(L2);
	printList(L3);


	//赋值
	//重载等号赋值
	list<int>L4;
	L4 = L3;
	printList(L4);

	list<int>L5;
	L5.assign(L1.begin(), L1.end());
	printList(L5);

	list<int>L6;
	L6.assign(10, 8);
	printList(L6);

	cout << "交换前：" << endl;
	printList(L5);
	printList(L6);

	L5.swap(L6);
	cout << "交换后: " << endl;
	printList(L5);
	printList(L6);


}

//大小操作
void Test2()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	printList(L);

	if (L.empty())
	{
		cout << "L为空" << endl;
	}
	else
	{
		cout << "L不为空" << endl;
		cout << "L的大小为：" << L.size() << endl;
	}

	//重置大小
	L.resize(10, 1000);
	printList(L);

	L.resize(2);
	printList(L);
}

//list容器的插入和删除
void Test3()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	printList(L);

	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);

	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	//插入
	L.insert(L.begin(), 10000);
	printList(L);

	L.insert(L.begin(), 10, 1000);
	printList(L);

	list<int>::iterator it = L.begin();
	//删除
	L.erase(it);
	printList(L);

	//移除容器中所有值为1000的元素
	L.remove(1000);
	printList(L);

	it = L.begin();

	L.erase(++it);
	printList(L);


	cout << "第一个元素：" << L.front() << endl;
	cout << "最后一个元素为：" << L.back() << endl;

	//支持双向访问，不支持随机访问
	it++;
	it--;
}



bool cmp_int(int v1, int v2)
{
	return v1 > v2;
}

//排序和反转
void Test4()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(30);
	L.push_back(20);
	L.push_back(40);
	L.push_back(60);
	L.push_back(50);

	//排序前
	cout << "排序前：" << endl;
	printList(L);

	//排序,默认排序规则：升序
	L.sort();

	//排序后
	cout << "排序后：" << endl;
	printList(L);

	//降序
	cout << "排成降序: " << endl;
	L.sort(cmp_int);
	printList(L);

	//反转
	cout << "将降序排列反转后：" << endl;
	L.reverse();
	printList(L);
}

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
public:
	string m_Name;
	int m_Age;
	int m_Height;
};

bool comparePerson(Person& p1, Person& p2)
{
	//如果年龄相同，按身高降序排序
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}

//排序案例,将每个人按年龄排序，年龄相同按身高降序排序
void Test5()
{
	list<Person>L;
	Person p1("赵云", 25, 190);
	Person p2("关羽", 35, 200);
	Person p3("张飞", 34, 180);
	Person p4("刘备", 35, 198);
	Person p5("孙权", 35, 188);
	Person p6("曹操", 42, 178);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "----------------------------" << endl;
	cout << "排序前：" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_Name << "  年龄： " << it->m_Age << "  身高： " << it->m_Height << endl;
	}

	cout << "----------------------------" << endl;
	cout << "排序后：" << endl;
	L.sort(comparePerson);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_Name << "  年龄： " << it->m_Age << "  身高： " << it->m_Height << endl;
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