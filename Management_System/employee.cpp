#define _CRT_SECURE_NO_WARNINGS 1

#include"employee.h"

//���캯��
Employee::Employee(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = Did;
}

//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		 << "\tְ��������" << this->m_Name
		 << "\t���ű�ţ�" << this->DeptId
		 << "\t��λ��" << this->get_Name()
	     <<"\t��λְ����ɾ���ַ�������" << endl;
}

//��ȡ��λ����
string Employee::get_Name()
{
	return string("Ա��");
}
