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


//set�������캯���͸�ֵ
void Test1()
{
	set<int>st;
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);

	//����Ԫ��ʱ��Ĭ���ų�����
	printSet(st);

	//��������
	set<int> s1(st);
	printSet(s1);

	set<int> s2;
	s2 = s1;
	printSet(s2);

}

//set������С������
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
		cout << "stΪ��" << endl;
	}
	else
	{
		cout << "st��Ϊ��" << endl;
		cout << "st�Ĵ�СΪ��" << st.size() << endl;

	}

	//����
	set<int> s;
	s.insert(100);
	s.insert(500);
	s.insert(300);
	s.insert(400);
	s.insert(200);
	s.insert(300);
	printSet(s);

	cout << "����ǰ��" << endl;
	printSet(st);
	printSet(s);

	cout << "������" << endl;
	st.swap(s);
	printSet(st);
	printSet(s);
}

//�����ɾ��
void Test3()
{
	
	set<int>st;
	//����
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);
	//����
	printSet(st);

	//ɾ��
	st.erase(st.begin());
	printSet(st);

	st.erase(40);
	printSet(st);
	//���
	//st.erase(st.begin(), st.end());
	st.clear();
	printSet(st);

}

//���Һ�ͳ��
void Test4()
{
	set<int>st;
	//����
	st.insert(10);
	st.insert(50);
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(30);

	set<int>::iterator pos = st.find(30);
	if (pos != st.end())
	{
		cout << "�ҵ��ˣ�Ԫ��Ϊ��" << *pos << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

	//ͳ��
	int num = st.count(20);
	cout << "num = " << num << endl;
}

//set��multiset������
void Test5()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��" << endl;
	}

	ret = s.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
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


//pair ����Ĵ���
void Test6()
{
	//��һ�ִ�����ʽ
	pair<string, int>p("Tom", 28);
	cout << "������" << p.first << " ���䣺" << p.second << endl;

	//�ڶ��ִ�����ʽ
	pair<string, int>p1 = make_pair("Eric", 25);
	cout << "������" << p1.first << " ���䣺" << p1.second << endl;
}


class MyCompare
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;
	}
};

//set��������,��������ָ���������
void Test7()
{
	set<int>st;
	//����
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

//����ʽ
class PeopleCmp
{
public:
	bool operator()(const People& p1, const People& p2) const
	{
		//�������併������
		return p1.m_Age > p2.m_Age;
	}
};

//set��������,�Զ�����������ָ���������
void Test8()
{
	set<People,PeopleCmp>s1;
	People p1("����", 29);
	People p2("����", 28);
	People p3("�ŷ�", 27);
	People p4("����", 26);
	People p5("�����", 30);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);

	for (set<People, PeopleCmp>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "������" << it->m_Name << " ���䣺 " << it->m_Age << endl;
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