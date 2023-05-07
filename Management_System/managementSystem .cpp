#define _CRT_SECURE_NO_WARNINGS 1

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{

	//创建一个对象
	WorkerManager wm;

	int input = 0;

	while (true)
	{
		wm.ShowMenu();
		cout << "请选择：> ";

		cin >> input; // 接收用户选项
		switch (input)
		{
		case 0:
			//退出管理系统
			wm.exitSystem();
			break;
		case 1:
			//添加职工信息
			wm.AddEmp();
			break;
		case 2:
			wm.Show_Emp();
			//显示职工信息
			break;
		case 3:
			//删除离职职工
			wm.del_Emp();
			break;
		case 4:
			//修改职工信息
			wm.Mod_Emp();
			break;
		case 5:
			//查找职工信息
			wm.Find_Emp();
			break;
		case 6:
			//职工信息排序
			wm.Sort_Emp();
			break;
		case 7:
			//清空所有文档
			wm.Clear_File();
			break;
		default:
			cout << "输入信息有误，请重新输入！" << endl;
			break;
		}

	}

	system("pause");
	return 0;
}