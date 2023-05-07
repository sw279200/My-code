#define _CRT_SECURE_NO_WARNINGS 1

#include "workerManager.h"
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

//���캯��
WorkerManager::WorkerManager()
{
	ifstream ifs;
	//�Զ�����ʽ���ļ�
	ifs.open(FILENAME, ios::in);

	//1.�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ��Ա������
		this->m_EmpNum = 0;
		//��ʼ��Ա������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		//�ر��ļ�
		ifs.close();
		return;

	}

	//2.�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		//��ʼ��Ա������
		this->m_EmpNum = 0;
		//��ʼ��Ա������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		//�ر��ļ�
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	//����ְ������
	this->m_EmpNum = num;

	//����ְ������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//��ʼ��ְ��
	init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ���ţ�" << this->m_EmpArray[i]->m_Id
			<< "ְ��������" << this->m_EmpArray[i]->m_Name
			<< "���ű�ţ�" << this->m_EmpArray[i]->DeptId << endl;
	}*/
}

//չʾ�˵�
void WorkerManager::ShowMenu()
{
	cout << "***************************************" << endl;
	cout << "******   ��ӭʹ��ְ������ϵͳ��  ******" << endl;
	cout << "********    0.�˳�����ϵͳ    *********" << endl;
	cout << "********    1.���ְ����Ϣ    *********" << endl;
	cout << "********    2.��ʾְ����Ϣ    *********" << endl;
	cout << "********    3.ɾ����ְְ��    *********" << endl;
	cout << "********    4.�޸�ְ����Ϣ    *********" << endl;
	cout << "********    5.����ְ����Ϣ    *********" << endl;
	cout << "********    6.ְ����Ϣ����    *********" << endl;
	cout << "********    7.��������ĵ�    *********" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}

//�˳�����ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´ι���" << endl;
	system("pause");
	exit(0);
}

//���Ա��
void WorkerManager::AddEmp()
{

	cout << "��������Ҫ��ӵ�Ա��������>" << endl;
	
	int addCount = 0;
	cin >> addCount;//�����û���Ҫ��ӵ�����

	int num = 0;
	string name;
	if (addCount > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addCount;

		//����һ���¿ռ�
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
			cout << "������ְ����ţ� " << endl;
			cin >> num;

			cout << "������ְ��������  " << endl;
			cin >> name;

			int dSelect = 0;
			cout << "1.Ա�� " << endl;
			cout << "2.���� " << endl;
			cout << "3.�ܲ� " << endl;
			cout << "��ѡ��ְ�����ţ� ";
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1://Ա��
				 worker = new Employee(num, name, 1);
				break;
			case 2://����
				worker = new Manager(num, name, 2);
				break;
			case 3://�ܲ�
				 worker = new Boss(num, name, 3);
				break;
			default:
				break;
			}

			newSpace[i + this->m_EmpNum] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�Ա������
		this->m_EmpNum = newSize;

		//�����ļ���Ϊ�յ����
		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "���" << addCount << "��Ա���ɹ�" << endl;

		//�������ݵ��ļ���
		this->Save();
	}
	else
	{
		cout << "�����벻�Ϸ������ʧ�ܣ�" << endl;
	}

	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::Save()
{
	ofstream ofs;
	//���ļ�����д�ļ��ķ�ʽ
	ofs.open(FILENAME, ios::out);

	//��ְ����Ϣд���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	//�Զ�����ʽ���ļ�
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

//��ʼ��ְ����Ϣ
void WorkerManager::init_Emp()
{
	ifstream ifs;
	//�Զ�����ʽ���ļ�
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

//��ʾְ����Ϣ
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬�ӿ�
			this->m_EmpArray[i]->ShowInfo();
		}
	}

	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ�����:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		//˵��ְ������ ,����Ҫɾ��index λ���ϵ�ְ��
		if (index != -1)
		{
			//����ǰ��
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//����ְ����Ա����
			this->m_EmpNum--;
			//������ͬ�����µ��ļ���
			this->Save();
			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		system("pause");
		system("cls");
	}
}

//����ְ������ж�ְ���Ƿ���ڣ�������ڣ�����ְ���������е�λ�ã���������ڣ�����-1
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

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{

		cout << "��������Ҫ�޸ĵ�ְ�����:" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		//˵��ְ������ ,����Ҫɾ��index λ���ϵ�ְ��
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽" << id << "��ְ����������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "������ְ����������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;

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

			cout << "�޸ĳɹ�" << this->m_EmpArray[ret]->DeptId << endl;

			//���浽�ļ���
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
		system("pause");
		system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.��ְ����Ų���"<<endl;
		cout << "2.��ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)//��ְ���Ų���
		{
			int id;
			cout << "��������ҵ�ְ����ţ�"<<endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;

			}

		}
		else if(select==2)//����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id
						<< "�ŵ���Ϣ���£�" << endl;

					flag = true;
					this->m_EmpArray[i]->ShowInfo();

				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����������ʽ��" << endl;
		cout << "1.����������" << endl;
		cout << "2.����������" << endl;

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
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->Save();
		this->Show_Emp();
	}
}

//��������ĵ�
void WorkerManager::Clear_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

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
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//��������
WorkerManager:: ~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
