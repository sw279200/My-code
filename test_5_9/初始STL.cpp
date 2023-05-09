#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print(int val)
{
	cout << val << endl;
}

//vector���������������
void Test1()
{
	//����vector �������󣬲���ͨ��ģ�����ָ�������д�ŵ���������
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//v.begin()���ص����������������ָ�������е�һ��Ԫ��
	//v.end()���ص����������������ָ�����������һ��Ԫ�ص���һ��
	//vector<int>::iterator �õ�vector<int>���������ĵ�������


	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//���������е�����Ԫ��
	//��һ�ֱ�����ʽ
	cout << "��һ�ֱ�����ʽ��" << endl;
	while (pBegin != pEnd)
	{
		cout << *pBegin << endl;
		pBegin++;
	}

	//�ڶ��ֱ�����ʽ
	cout << "�ڶ��ֱ�����ʽ��" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//�����ֱ�����ʽ
	cout << "�����ֱ�����ʽ��" << endl;
	for_each(v.begin(), v.end(), print);
}

//vector����Զ�����������
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
	Person p1("���", 25);
	Person p2("����", 999);
	Person p3("����", 26);
	Person p4("�����", 32);
	Person p5("��", 27);
	Person p6("��", 24);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "������" << (*it).m_Name << " ���䣺" << (*it).m_Age << endl;
		cout << "������" << it->m_Name << " ���䣺" << it->m_Age << endl;
	}

}

void Test3()
{
	//��������Զ����������͵�ָ��
	vector<Person*> v;
	Person p1("���", 25);
	Person p2("����", 999);
	Person p3("����", 26);
	Person p4("�����", 32);
	Person p5("��", 27);
	Person p6("��", 24);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it)->m_Name << " ���䣺" << (*it)->m_Age << endl;
	}

}

//����Ƕ������
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