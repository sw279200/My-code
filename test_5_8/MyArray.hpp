#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		//cout << "MyArray的有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	
	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray的拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];

		//将array中的数据全部拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		//先判断原来的堆区是否有数据，如果有，先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//重载[] 操作符
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//尾插法
	void Push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//获取数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		//cout << "MyArray的析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	//数组大小
	int m_Size;
	//数组容量
	int m_Capacity;

	//指针指向堆区真实开辟的数组
	T* pAddress;
	
};