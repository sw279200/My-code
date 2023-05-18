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

//find()�����Ĳ����㷨
void Test1()
{
	//�����������Ͳ���
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
		cout << "û���ҵ�" << endl;
	else
		cout << "�ҵ���:" << *it << endl;

	//�Զ����������Ͳ���
	vector<Person>v1;
	Person p1("С���", 25);
	Person p2("С����", 27);
	Person p3("С����", 28);
	Person p4("СС��", 19);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	Person p5("С���", 25);
	vector<Person>::iterator its = find(v1.begin(), v1.end(), p5);
	if (its==v1.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�������" << its->m_Name << " ���䣺" << its->m_Age << endl;
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
		cout << "û���ҵ�" << endl;
	else
		cout << "�ҵ���:"<<*it << endl;

	//�Զ�������������������
	vector<Person>v1;
	Person p1("С���", 25);
	Person p2("С����", 27);
	Person p3("С����", 28);
	Person p4("СС��", 19);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	vector<Person>::iterator its = find_if(v1.begin(), v1.end(), GreaterTwenty());
	if (its == v1.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�������" << its->m_Name << " ���䣺" << its->m_Age << endl;
	}

}

//���������ظ�Ԫ��
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
		cout << "û���ҵ��ظ�����Ԫ��" << endl;
	else
		cout << "�ҵ��������ظ�Ԫ�أ�" << *pos << endl;


	//���ֲ��ң�ע�⣺���ҵ����б�������
	vector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	bool ret = binary_search(v1.begin(), v1.end(), 9);
	if (!ret)
		cout << "û���ҵ�" << endl;
	else
		cout << "�ҵ���"<< endl;
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
	//��count�����������������͵ĸ���
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
	cout << "4�ĸ���Ϊ��" << num<<endl;


	//��count�������Զ����������͵ĸ���
	vector<Person0>v1;
	Person0 p1("����", 35);
	Person0 p2("����", 35);
	Person0 p3("�ŷ�", 35);
	Person0 p4("����", 30);
	Person0 p5("�ܲ�", 40);


	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	Person0 p("�����", 35);
	int nums = count(v1.begin(), v1.end(), p);
	cout << "�������������ͬ�������У�" <<nums<< endl;
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
	cout << "����5�����ĸ���Ϊ��" << num << endl;


	vector<Person>v1;
	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 20);
	Person p5("�ܲ�", 18);


	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	int nums = count_if(v1.begin(), v1.end(), GreaterTwenty());
	cout << "�������20�������У�" << nums << endl;
}

void print(int val)
{
	cout << val << " ";
}

//���������㷨 sort()
void Test6()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	cout << "����ǰ��" << endl;
	for_each(v.begin(), v.end(), print);
	cout << endl;
	cout << "�������" << endl;
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	cout << "�Ž����" << endl;
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), print);
	cout << endl;


	//��random_shuffle()��������˳��

	srand((unsigned int)time(NULL));

	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//ϴ�ƣ�����������
	cout << "����ǰ��" << endl;
	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	cout << "�������" << endl;
	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	cout << "�Ž����" << endl;
	sort(v1.begin(), v1.end(), greater<int>());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
}

//merge ������������Ԫ�������ϲ���һ��������
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

	//�����������ϲ�
	cout << "�ϲ���" << endl;
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

	cout << "��תǰ��" << endl;
	for_each(v.begin(), v.end(), print);
	cout << endl;
	cout << "��ת��" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	
}

//�º���
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


//���õĿ������滻�㷨
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

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	replace(v.begin(), v.end(), 20, 200);
	cout << "�滻��" << endl;
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

	cout << "�滻ǰ��" << endl;
	for_each(v3.begin(), v3.end(), MyPrint());
	cout << endl;
	replace_if(v3.begin(), v3.end(), Greater20(), 200);
	cout << "�滻��" << endl;
	for_each(v3.begin(), v3.end(), MyPrint());
	cout << endl;

}

//��������
void Test10()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(100 + i);
	}
	cout << "����ǰ��" << endl;
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	for_each(v2.begin(), v2.end(), print);
	cout << endl;

	cout << "������:" << endl;
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

	//��������������ʼ�ۼ�ֵ
	int sum = accumulate(v.begin(), v.end(), 0);
	cout <<"sum = "<< sum << endl;

	vector<int>v1;
	v1.resize(10);

	//�����������
	fill(v1.begin(), v1.end(), 20);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}

//���ü����㷨
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
	//���������ϵĽ��� set_intersection
	cout << "�������ϵĽ���:" << endl;
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, print);
	cout << endl;

	vector<int>v4;
	v4.resize(v1.size()+v2.size());
	//���������ϵĲ��� set_intersection
	cout << "�������ϵĲ���" << endl;
	vector<int>::iterator itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
	for_each(v4.begin(), itend, print);
	cout << endl;

	vector<int>v5;
	v5.resize(max(v1.size(),v2.size()));
	//���������ϵĲ set_intersection
	cout << "v1��v2�Ĳ" << endl;
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