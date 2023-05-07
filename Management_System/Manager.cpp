#define _CRT_SECURE_NO_WARNINGS 1

#include"manager.h"
//构造函数
Manager::Manager(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = Did;
}

//显示个人信息
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t部门编号：" << this->DeptId
		<< "\t岗位：" << this->get_Name()
		<< "\t岗位职责：听从老板安排，给员工分配任务" << endl;
}

//获取岗位名称
string Manager::get_Name()
{
	return string("经理");
}
