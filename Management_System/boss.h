#pragma once

#include "worker.h"
#include <iostream>
using namespace std;
#include <string>

class Boss : public Worker
{
public:
	//���캯��
	Boss(int id, string name, int Did);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string get_Name();
};
