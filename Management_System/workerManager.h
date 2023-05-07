#pragma once

#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void ShowMenu();

	//退出管理系统
	void exitSystem();

	//职工人数
	int m_EmpNum;

	//员工数组指针
	Worker** m_EmpArray;

	//添加员工
	void AddEmp();

	//保存文件
	void Save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化职工信息
	void init_Emp();

	//显示职工信息
	void Show_Emp();

	//删除职工
	void del_Emp();

	//按照职工编号判断职工是否存在，如果存在，返回职工在数组中的位置，如果不存在，返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空所以文档
	void Clear_File();

	//析构函数
	~WorkerManager();
};
