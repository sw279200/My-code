#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι���
	MyArray(int capacity)
	{
		//cout << "MyArray���вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	
	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray�Ŀ����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[arr.m_Capacity];

		//��array�е�����ȫ����������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator ��ֹǳ��������
	MyArray& operator=(const MyArray& arr)
	{
		//���ж�ԭ���Ķ����Ƿ������ݣ�����У����ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//����[] ������
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//β�巨
	void Push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//��ȡ��������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}

	//��������
	~MyArray()
	{
		//cout << "MyArray��������������" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	//�����С
	int m_Size;
	//��������
	int m_Capacity;

	//ָ��ָ�������ʵ���ٵ�����
	T* pAddress;
	
};