#pragma once

#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	
	//显示个人信息
	virtual void ShowInfo() = 0;

	//获取岗位名称
	virtual string get_Name() = 0;

	//职工姓名
	string m_Name;

	//职工编号
	int m_Id;

	//部门编号
	int DeptId;

};


