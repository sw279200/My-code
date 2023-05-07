#define _CRT_SECURE_NO_WARNINGS 1

#include"employee.h"

//构造函数
Employee::Employee(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = Did;
}

//显示个人信息
void Employee::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		 << "\t职工姓名：" << this->m_Name
		 << "\t部门编号：" << this->DeptId
		 << "\t岗位：" << this->get_Name()
	     <<"\t岗位职责：完成经理分发的任务" << endl;
}

//获取岗位名称
string Employee::get_Name()
{
	return string("员工");
}
