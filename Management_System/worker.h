#pragma once

#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string get_Name() = 0;

	//ְ������
	string m_Name;

	//ְ�����
	int m_Id;

	//���ű��
	int DeptId;

};


