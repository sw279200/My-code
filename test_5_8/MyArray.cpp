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


//测试自定义类型数据

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
		cout << "姓名： " << personArr[i].m_Name << "年龄: " << personArr[i].m_Age << endl;
	}
}

void Test2()
{
	MyArray<Person>pArray(10);
	Person p1("孙悟空", 999);
	Person p2("韩信", 20);
	Person p3("李白", 23);
	Person p4("夏洛特", 26);
	Person p5("花木兰", 28);

	//插入数据
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);

	//打印数组
	printPersonArray(pArray);

	cout << "pArray的大小:" << pArray.getSize() << endl;
	cout << "pArray的容量:" << pArray.getCapacity() << endl;


}

//测试内置类型数据
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
	cout << "array1打印输出：" << endl;
	printInArray(array1);
	cout << "array1的大小:" << array1.getSize() << endl;
	cout << "array1的容量:" << array1.getCapacity() << endl;
	cout << "---------------------" << endl;
	MyArray<int>array2(array1);
	array2.Pop_back();
	cout << "array2打印输出：" << endl;
	printInArray(array2);
	cout << "array2的大小:" << array2.getSize() << endl;
	cout << "array2的容量:" << array2.getCapacity() << endl;
}


int main()
{
	//Test1();
	Test2();
	return 0;
}