#define _CRT_SECURE_NO_WARNINGS 1

#include"manager.h"
//���캯��
Manager::Manager(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = Did;
}

//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t���ű�ţ�" << this->DeptId
		<< "\t��λ��" << this->get_Name()
		<< "\t��λְ�������ϰ尲�ţ���Ա����������" << endl;
}

//��ȡ��λ����
string Manager::get_Name()
{
	return string("����");
}
