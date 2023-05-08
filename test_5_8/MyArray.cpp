#define _CRT_SECURE_NO_WARNINGS 1

#include"MyArray.hpp"

#include <iostream>
#include <string>
using namespace std;

void printInArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


//�����Զ�����������

class Person
{
public:
	Person(){}
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++)
	{
		cout << "������ " << personArr[i].m_Name << "����: " << personArr[i].m_Age << endl;
	}
}

void Test2()
{
	MyArray<Person>pArray(10);
	Person p1("�����", 999);
	Person p2("����", 20);
	Person p3("���", 23);
	Person p4("������", 26);
	Person p5("��ľ��", 28);

	//��������
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);

	//��ӡ����
	printPersonArray(pArray);

	cout << "pArray�Ĵ�С:" << pArray.getSize() << endl;
	cout << "pArray������:" << pArray.getCapacity() << endl;


}

//����������������
void Test1()
{
	/*MyArray<int>arr1(5);

	MyArray<int>arr2(arr1);

	MyArray<int>arr3(100);

	arr3 = arr1;*/

	MyArray<int>array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1��ӡ�����" << endl;
	printInArray(array1);
	cout << "array1�Ĵ�С:" << array1.getSize() << endl;
	cout << "array1������:" << array1.getCapacity() << endl;
	cout << "---------------------" << endl;
	MyArray<int>array2(array1);
	array2.Pop_back();
	cout << "array2��ӡ�����" << endl;
	printInArray(array2);
	cout << "array2�Ĵ�С:" << array2.getSize() << endl;
	cout << "array2������:" << array2.getCapacity() << endl;
}


int main()
{
	//Test1();
	Test2();
	return 0;
}