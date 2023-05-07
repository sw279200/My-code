#pragma once

#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void ShowMenu();

	//�˳�����ϵͳ
	void exitSystem();

	//ְ������
	int m_EmpNum;

	//Ա������ָ��
	Worker** m_EmpArray;

	//���Ա��
	void AddEmp();

	//�����ļ�
	void Save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ������
	int get_EmpNum();

	//��ʼ��ְ����Ϣ
	void init_Emp();

	//��ʾְ����Ϣ
	void Show_Emp();

	//ɾ��ְ��
	void del_Emp();

	//����ְ������ж�ְ���Ƿ���ڣ�������ڣ�����ְ���������е�λ�ã���������ڣ�����-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//��������ĵ�
	void Clear_File();

	//��������
	~WorkerManager();
};
