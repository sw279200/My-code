#define _CRT_SECURE_NO_WARNINGS 1

#include "workerManager.h"
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

//构造函数
WorkerManager::WorkerManager()
{
	ifstream ifs;
	//以读的形式打开文件
	ifs.open(FILENAME, ios::in);

	//1.文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化员工人数
		this->m_EmpNum = 0;
		//初始化员工数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		//关闭文件
		ifs.close();
		return;

	}

	//2.文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		//初始化员工人数
		this->m_EmpNum = 0;
		//初始化员工数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		//关闭文件
		ifs.close();
		return;
	}

	//3.文件存在，并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工个数为：" << num << endl;
	//更新职工人数
	this->m_EmpNum = num;

	//根据职工数创建数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//初始化职工
	init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工号：" << this->m_EmpArray[i]->m_Id
			<< "职工姓名：" << this->m_EmpArray[i]->m_Name
			<< "部门编号：" << this->m_EmpArray[i]->DeptId << endl;
	}*/
}

//展示菜单
void WorkerManager::ShowMenu()
{
	cout << "***************************************" << endl;
	cout << "******   欢迎使用职工管理系统！  ******" << endl;
	cout << "********    0.退出管理系统    *********" << endl;
	cout << "********    1.添加职工信息    *********" << endl;
	cout << "********    2.显示职工信息    *********" << endl;
	cout << "********    3.删除离职职工    *********" << endl;
	cout << "********    4.修改职工信息    *********" << endl;
	cout << "********    5.查找职工信息    *********" << endl;
	cout << "********    6.职工信息排序    *********" << endl;
	cout << "********    7.清空所有文档    *********" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}

//退出管理系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次光临" << endl;
	system("pause");
	exit(0);
}

//添加员工
void WorkerManager::AddEmp()
{

	cout << "请输入需要添加的员工数量：>" << endl;
	
	int addCount = 0;
	cin >> addCount;//接收用户需要添加的人数

	int num = 0;
	string name;
	if (addCount > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addCount;

		//申请一块新空间
		Worker** newSpace = new Worker * [newSize];

		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addCount; i++)
		{
			cout << "请输入职工编号： " << endl;
			cin >> num;

			cout << "请输入职工姓名：  " << endl;
			cin >> name;

			int dSelect = 0;
			cout << "1.员工 " << endl;
			cout << "2.经理 " << endl;
			cout << "3.总裁 " << endl;
			cout << "请选择职工部门： ";
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1://员工
				 worker = new Employee(num, name, 1);
				break;
			case 2://经理
				worker = new Manager(num, name, 2);
				break;
			case 3://总裁
				 worker = new Boss(num, name, 3);
				break;
			default:
				break;
			}

			newSpace[i + this->m_EmpNum] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更新新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的员工数量
		this->m_EmpNum = newSize;

		//更新文件不为空的情况
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "添加" << addCount << "名员工成功" << endl;

		//保存数据到文件中
		this->Save();
	}
	else
	{
		cout << "该输入不合法，添加失败！" << endl;
	}

	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::Save()
{
	ofstream ofs;
	//打开文件，以写文件的方式
	ofs.open(FILENAME, ios::out);

	//把职工信息写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

//统计人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	//以读的形式打开文件
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int Did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		num++;
	}

	ifs.close();

	return num;
}

//初始化职工信息
void WorkerManager::init_Emp()
{
	ifstream ifs;
	//以读的形式打开文件
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int Did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		Worker* worker = NULL;
		if (Did == 1)
		{
			worker = new Employee(id, name, Did);

		}
		else if (Did == 2)
		{
			worker = new Manager(id, name, Did);

		}
		else if (Did == 3)
		{
			worker = new Boss(id, name, Did);

		}

		this->m_EmpArray[index] = worker;
		index++;	
	}

}

//显示职工信息
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//调用多态接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}

	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		//说明职工存在 ,并且要删除index 位置上的职工
		if (index != -1)
		{
			//数据前移
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新职工人员个数
			this->m_EmpNum--;
			//将数据同步更新到文件中
			this->Save();
			cout << "删除成功" << endl;

		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
		system("pause");
		system("cls");
	}
}

//按照职工编号判断职工是否存在，如果存在，返回职工在数组中的位置，如果不存在，返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{

		cout << "请输入想要修改的职工编号:" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		//说明职工存在 ,并且要删除index 位置上的职工
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到" << id << "号职工，请重新输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入职工新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;

			cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			}

			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << this->m_EmpArray[ret]->DeptId << endl;

			//保存到文件中
			this->Save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
		system("pause");
		system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按职工编号查找"<<endl;
		cout << "2.按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)//按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号："<<endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下:" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;

			}

		}
		else if(select==2)//按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;//查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id
						<< "号的信息如下：" << endl;

					flag = true;
					this->m_EmpArray[i]->ShowInfo();

				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1.按升序排序" << endl;
		cout << "2.按降序排序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_EmpNum; i++)
		{
			int maxOrMin = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[maxOrMin]->m_Id > m_EmpArray[j]->m_Id)
					{
						maxOrMin = j;
					}
				}
				else
				{
					if (m_EmpArray[maxOrMin]->m_Id < m_EmpArray[j]->m_Id)
					{
						maxOrMin = j;
					}
				}
			}

			if (i != maxOrMin)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[maxOrMin];
				m_EmpArray[maxOrMin] = temp;
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->Save();
		this->Show_Emp();
	}
}

//清空所以文档
void WorkerManager::Clear_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;

		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
WorkerManager:: ~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
