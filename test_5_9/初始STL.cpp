#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print(int val)
{
	cout << val << endl;
}

//vector存放内置数据类型
void Test1()
{
	//创建vector 容器对象，并且通过模板参数指定容器中存放的数据类型
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//v.begin()返回迭代器，这个迭代器指向容器中第一个元素
	//v.end()返回迭代器，这个迭代器指向容器中最后一个元素的下一个
	//vector<int>::iterator 拿到vector<int>这种容器的迭代类型


	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//遍历数组中的所有元素
	//第一种遍历方式
	cout << "第一种遍历方式：" << endl;
	while (pBegin != pEnd)
	{
		cout << *pBegin << endl;
		pBegin++;
	}

	//第二种遍历方式
	cout << "第二种遍历方式：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种遍历方式
	cout << "第三种遍历方式：" << endl;
	for_each(v.begin(), v.end(), print);
}

//vector存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};


void Test2()
{
	vector<Person> v;
	Person p1("李白", 25);
	Person p2("猴子", 999);
	Person p3("韩信", 26);
	Person p4("诸葛亮", 32);
	Person p5("凯", 27);
	Person p6("澜", 24);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}

}

void Test3()
{
	//容器存放自定义数据类型的指针
	vector<Person*> v;
	Person p1("李白", 25);
	Person p2("猴子", 999);
	Person p3("韩信", 26);
	Person p4("诸葛亮", 32);
	Person p5("凯", 27);
	Person p6("澜", 24);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->m_Name << " 年龄：" << (*it)->m_Age << endl;
	}

}

//容器嵌套容器
void Test4()
{
	vector<vector<int>>v;

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}


}



int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}