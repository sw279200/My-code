#pragma once

#include "worker.h"
#include <iostream>
using namespace std;
#include <string>

class Boss : public Worker
{
public:
	//构造函数
	Boss(int id, string name, int Did);

	//显示个人信息
	virtual void ShowInfo();

	//获取岗位名称
	virtual string get_Name();
};
