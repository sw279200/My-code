#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include <map>
#include <vector>
#include <ctime>

#define PLAN 0  //策划部门
#define PAINT 1 //美术部门
#define RESEARCH 2 //研发部门

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

//创建员工
void CreatWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "员工";
		name += nameSeed[i];

		int salary = rand() % 10001 + 10000;
		Worker worker;
		worker.m_Name = name;
		worker.m_Salary = salary;
		v.push_back(worker);
	}
}

//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生一个随机数
		int group = rand() % 3;

		//将员工插入到分组中
		m.insert(make_pair(group, *it));

	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	//策划部门
	cout << "--------------------------" << endl;
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(PLAN);
	int index = 0;
	int count = m.count(PLAN);
	for ( ; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << "--------------------------" << endl;
	//美术部门
	cout << "美术部门：" << endl;
	pos = m.find(PAINT);
	index = 0;
	count = m.count(PAINT);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << "--------------------------" << endl;
	//研发部门
	cout << "研发部门：" << endl;
	pos = m.find(RESEARCH);
	index = 0;
	count = m.count(RESEARCH);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
}

int main()
{

	srand((unsigned int)time(NULL));
	//1.创建员工
	vector<Worker>vWorker;
	CreatWorker(vWorker);

	//2.员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

	//3.显示分组信息
	showWorkerByGroup(mWorker);

	return 0;
}