#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>
#include <ctime>
#include <numeric>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:	
	bool operator ==(const Person& p)
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}
public:
	string m_Name;
	int m_Age;
};

//find()函数的查找算法
void Test1()
{
	//内置数据类型查找
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
		cout << "没有找到" << endl;
	else
		cout << "找到了:" << *it << endl;

	//自定义数据类型查找
	vector<Person>v1;
	Person p1("小李白", 25);
	Person p2("小韩信", 27);
	Person p3("小赵云", 28);
	Person p4("小小澜", 19);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	Person p5("小李白", 25);
	vector<Person>::iterator its = find(v1.begin(), v1.end(), p5);
	if (its==v1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了，姓名：" << its->m_Name << " 年龄：" << its->m_Age << endl;
	}
}


class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class GreaterTwenty
{

public:

	bool operator ()(const Person& p)
	{
		return p.m_Age > 20;
	}

};

void Test2()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
		cout << "没有找到" << endl;
	else
		cout << "找到了:"<<*it << endl;

	//自定义数据类型条件查找
	vector<Person>v1;
	Person p1("小李白", 25);
	Person p2("小韩信", 27);
	Person p3("小赵云", 28);
	Person p4("小小澜", 19);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	vector<Person>::iterator its = find_if(v1.begin(), v1.end(), GreaterTwenty());
	if (its == v1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了，姓名：" << its->m_Name << " 年龄：" << its->m_Age << endl;
	}

}

//查找相邻重复元素
void Test3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());

	if (pos == v.end())
		cout << "没有找到重复相邻元素" << endl;
	else
		cout << "找到了相邻重复元素：" << *pos << endl;


	//二分查找，注意：查找的序列必须有序
	vector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	bool ret = binary_search(v1.begin(), v1.end(), 9);
	if (!ret)
		cout << "没有找到" << endl;
	else
		cout << "找到了"<< endl;
}


class Person0
{
public:
	Person0(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	bool operator ==(const Person0& p)
	{
		return this->m_Age == p.m_Age;
	}
public:
	string m_Name;
	int m_Age;
};
void Test4()
{
	//用count函数求内置数据类型的个数
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);
	cout << "4的个数为：" << num<<endl;


	//用count函数求自定义数据类型的个数
	vector<Person0>v1;
	Person0 p1("刘备", 35);
	Person0 p2("关羽", 35);
	Person0 p3("张飞", 35);
	Person0 p4("赵云", 30);
	Person0 p5("曹操", 40);


	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	Person0 p("诸葛亮", 35);
	int nums = count(v1.begin(), v1.end(), p);
	cout << "与诸葛亮年龄相同的人数有：" <<nums<< endl;
}


void Test5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(6);
	v.push_back(6);
	v.push_back(6);
	v.push_back(5);

	int num = count_if(v.begin(), v.end(), GreaterFive());
	cout << "大于5的数的个数为：" << num << endl;


	vector<Person>v1;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 20);
	Person p5("曹操", 18);


	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	int nums = count_if(v1.begin(), v1.end(), GreaterTwenty());
	cout << "年龄大于20的人数有：" << nums << endl;
}

void print(int val)
{
	cout << val << " ";
}

//常用排序算法 sort()
void Test6()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	cout << "排序前：" << endl;
	for_each(v.begin(), v.end(), print);
	cout << endl;
	cout << "排升序后：" << endl;
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	cout << "排降序后：" << endl;
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), print);
	cout << endl;


	//用random_shuffle()函数打乱顺序

	srand((unsigned int)time(NULL));

	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//洗牌，将其变成乱序
	cout << "排序前：" << endl;
	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	cout << "排升序后：" << endl;
	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	cout << "排降序后：" << endl;
	sort(v1.begin(), v1.end(), greater<int>());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
}

//merge 将两个容器的元素排序后合并到一个容器里
void Test7()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int>v3;
	v3.resize(v1.size() + v2.size());

	//将两个容器合并
	cout << "合并后：" << endl;
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), print);
	cout << endl;
}

void Test8()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), print);
	cout << endl;
	cout << "反转后：" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	
}

//仿函数
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class Greater20
{
public:
	bool operator()(int val)
	{
		return val >= 20;
	}
};


//常用的拷贝和替换算法
void Test9()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1:" << endl;
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	vector<int>v2;
	v2.resize(v1.size());
	cout << "v2:" << endl;
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print);
	cout << endl;

	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	replace(v.begin(), v.end(), 20, 200);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(40);
	v3.push_back(20);
	v3.push_back(30);
	v3.push_back(50);
	v3.push_back(30);
	v3.push_back(20);
	v3.push_back(30);
	v3.push_back(40);
	v3.push_back(20);

	cout << "替换前：" << endl;
	for_each(v3.begin(), v3.end(), MyPrint());
	cout << endl;
	replace_if(v3.begin(), v3.end(), Greater20(), 200);
	cout << "替换后：" << endl;
	for_each(v3.begin(), v3.end(), MyPrint());
	cout << endl;

}

//容器交换
void Test10()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(100 + i);
	}
	cout << "交换前：" << endl;
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	for_each(v2.begin(), v2.end(), print);
	cout << endl;

	cout << "交换后:" << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	for_each(v2.begin(), v2.end(), print);
	cout << endl;


}

void Test11()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	//第三个参数是起始累加值
	int sum = accumulate(v.begin(), v.end(), 0);
	cout <<"sum = "<< sum << endl;

	vector<int>v1;
	v1.resize(10);

	//后期重新填充
	fill(v1.begin(), v1.end(), 20);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}

//常用集合算法
void Test12()
{
	
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(5 + i);
	}

	vector<int>v3;
	v3.resize(min(v1.size(), v2.size()));
	//求两个集合的交集 set_intersection
	cout << "两个集合的交集:" << endl;
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, print);
	cout << endl;

	vector<int>v4;
	v4.resize(v1.size()+v2.size());
	//求两个集合的并集 set_intersection
	cout << "两个集合的并集" << endl;
	vector<int>::iterator itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
	for_each(v4.begin(), itend, print);
	cout << endl;

	vector<int>v5;
	v5.resize(max(v1.size(),v2.size()));
	//求两个集合的差集 set_intersection
	cout << "v1和v2的差集" << endl;
	vector<int>::iterator it = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v4.begin());
	for_each(v4.begin(), it, print);
	cout << endl;
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
	//Test8();
	//Test9();
	//Test10();
	//Test11();
	Test12();
	return 0;
}

#endif