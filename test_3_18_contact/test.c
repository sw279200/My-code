#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
#include"stdlib.h"
//ͨѶ¼
//1.ͨѶ¼���ܹ����1000���˵���Ϣ
//ÿ���˵���Ϣ��
//����+����+�Ա�+�绰+��ַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.����ָ���˵���Ϣ
//5.����ͨѶ¼����Ϣ
//6.�޸�ָ���˵���Ϣ
//7.��ӡͨѶ¼��Ϣ

void menu()
{
	printf("****************************\n");
	printf("****   1.add     2.del  ****\n");
	printf("****   3.search  4.sort ****\n");
	printf("****   5.modify  6.print****\n");
	printf("****   0.exit           ****\n");
	printf("****************************\n");
}

enum Option 
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	SORT,
	MODIFY,
	PRINT,

};
int main()
{
	int input =0;
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch(input) 
		{
		case EXIT:
			//�˳�ͨѶ¼
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		case ADD:
			//������ϵ��
			AddContact(&con);
			break;
		case DEL:
			//ɾ��ָ����ϵ��
			DelContact(&con);
			break;
		case SEARCH :
			//����ָ����ϵ��
			SearchContact(&con);
			break;
		case SORT:
			//��ͨѶ¼��������
			SortContact(&con);
			break;
		case MODIFY:
			//�޸�ָ����ϵ��
			ModifyContact(&con);
			break;
		case PRINT:
			//��ӡͨѶ¼��Ϣ
			PrintContact(&con);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while(input);
	
	
	return 0;
}
