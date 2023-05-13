#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include <map>
#include <vector>
#include <ctime>

#define PLAN 0  //�߻�����
#define PAINT 1 //��������
#define RESEARCH 2 //�з�����

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

//����Ա��
void CreatWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "Ա��";
		name += nameSeed[i];

		int salary = rand() % 10001 + 10000;
		Worker worker;
		worker.m_Name = name;
		worker.m_Salary = salary;
		v.push_back(worker);
	}
}

//Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����һ�������
		int group = rand() % 3;

		//��Ա�����뵽������
		m.insert(make_pair(group, *it));

	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	//�߻�����
	cout << "--------------------------" << endl;
	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::iterator pos = m.find(PLAN);
	int index = 0;
	int count = m.count(PLAN);
	for ( ; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << "--------------------------" << endl;
	//��������
	cout << "�������ţ�" << endl;
	pos = m.find(PAINT);
	index = 0;
	count = m.count(PAINT);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << "--------------------------" << endl;
	//�з�����
	cout << "�з����ţ�" << endl;
	pos = m.find(RESEARCH);
	index = 0;
	count = m.count(RESEARCH);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
}

int main()
{

	srand((unsigned int)time(NULL));
	//1.����Ա��
	vector<Worker>vWorker;
	CreatWorker(vWorker);

	//2.Ա������
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

	//3.��ʾ������Ϣ
	showWorkerByGroup(mWorker);

	return 0;
}