#define _CRT_SECURE_NO_WARNINGS 1

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{

	//����һ������
	WorkerManager wm;

	int input = 0;

	while (true)
	{
		wm.ShowMenu();
		cout << "��ѡ��> ";

		cin >> input; // �����û�ѡ��
		switch (input)
		{
		case 0:
			//�˳�����ϵͳ
			wm.exitSystem();
			break;
		case 1:
			//���ְ����Ϣ
			wm.AddEmp();
			break;
		case 2:
			wm.Show_Emp();
			//��ʾְ����Ϣ
			break;
		case 3:
			//ɾ����ְְ��
			wm.del_Emp();
			break;
		case 4:
			//�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5:
			//����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6:
			//ְ����Ϣ����
			wm.Sort_Emp();
			break;
		case 7:
			//��������ĵ�
			wm.Clear_File();
			break;
		default:
			cout << "������Ϣ�������������룡" << endl;
			break;
		}

	}

	system("pause");
	return 0;
}