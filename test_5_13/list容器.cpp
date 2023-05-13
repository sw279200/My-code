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

//list�����Ĺ��캯���͸�ֵ�ͽ���
void Test1()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	printList(L);

	//���乹��
	list<int> L1(L.begin(), L.end());
	printList(L1);

	//n��elem�Ĺ��캯��
	list<int>L2(5, 1000);
	printList(L2);

	//��������
	list<int> L3(L2);
	printList(L3);


	//��ֵ
	//���صȺŸ�ֵ
	list<int>L4;
	L4 = L3;
	printList(L4);

	list<int>L5;
	L5.assign(L1.begin(), L1.end());
	printList(L5);

	list<int>L6;
	L6.assign(10, 8);
	printList(L6);

	cout << "����ǰ��" << endl;
	printList(L5);
	printList(L6);

	L5.swap(L6);
	cout << "������: " << endl;
	printList(L5);
	printList(L6);


}

//��С����
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
		cout << "LΪ��" << endl;
	}
	else
	{
		cout << "L��Ϊ��" << endl;
		cout << "L�Ĵ�СΪ��" << L.size() << endl;
	}

	//���ô�С
	L.resize(10, 1000);
	printList(L);

	L.resize(2);
	printList(L);
}

//list�����Ĳ����ɾ��
void Test3()
{
	list<int> L;
	//β��
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	printList(L);

	//ͷ��
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);

	//βɾ
	L.pop_back();
	printList(L);

	//ͷɾ
	L.pop_front();
	printList(L);

	//����
	L.insert(L.begin(), 10000);
	printList(L);

	L.insert(L.begin(), 10, 1000);
	printList(L);

	list<int>::iterator it = L.begin();
	//ɾ��
	L.erase(it);
	printList(L);

	//�Ƴ�����������ֵΪ1000��Ԫ��
	L.remove(1000);
	printList(L);

	it = L.begin();

	L.erase(++it);
	printList(L);


	cout << "��һ��Ԫ�أ�" << L.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << L.back() << endl;

	//֧��˫����ʣ���֧���������
	it++;
	it--;
}



bool cmp_int(int v1, int v2)
{
	return v1 > v2;
}

//����ͷ�ת
void Test4()
{
	list<int> L;
	//β��
	L.push_back(10);
	L.push_back(30);
	L.push_back(20);
	L.push_back(40);
	L.push_back(60);
	L.push_back(50);

	//����ǰ
	cout << "����ǰ��" << endl;
	printList(L);

	//����,Ĭ�������������
	L.sort();

	//�����
	cout << "�����" << endl;
	printList(L);

	//����
	cout << "�ųɽ���: " << endl;
	L.sort(cmp_int);
	printList(L);

	//��ת
	cout << "���������з�ת��" << endl;
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
	//���������ͬ������߽�������
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}

//������,��ÿ���˰���������������ͬ����߽�������
void Test5()
{
	list<Person>L;
	Person p1("����", 25, 190);
	Person p2("����", 35, 200);
	Person p3("�ŷ�", 34, 180);
	Person p4("����", 35, 198);
	Person p5("��Ȩ", 35, 188);
	Person p6("�ܲ�", 42, 178);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "----------------------------" << endl;
	cout << "����ǰ��" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " << it->m_Name << "  ���䣺 " << it->m_Age << "  ��ߣ� " << it->m_Height << endl;
	}

	cout << "----------------------------" << endl;
	cout << "�����" << endl;
	L.sort(comparePerson);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " << it->m_Name << "  ���䣺 " << it->m_Age << "  ��ߣ� " << it->m_Height << endl;
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