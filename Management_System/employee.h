#pragma once

#include "worker.h"
#include <iostream>
using namespace std;
#include <string>

class Employee : public Worker
{
public:
	//���캯��
	Employee(int id , string name, int Did);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string get_Name();
};
