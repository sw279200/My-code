#define _CRT_SECURE_NO_WARNINGS 1

#include"boss.h"
//���캯��
Boss::Boss(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = Did;
}

//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t���ű�ţ�" << this->DeptId
		<< "\t��λ��" << this->get_Name()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

//��ȡ��λ����
string Boss::get_Name()
{
	return string("�ܲ�");
}
