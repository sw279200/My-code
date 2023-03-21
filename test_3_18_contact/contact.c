#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
//����һ���绰������֤�õ绰�����Ƿ��Ѵ���

//ʵ�����ָ����ϵ��
void AddContact(Contact* pc)
{
	if (pc->sz == MAX_DATA)
	{
		printf("ͨѶ¼�������޷����!\n");
		return;
	}
	printf("����������:>\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�:>\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������:>\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰:>\n");
	scanf("%s", pc->data[pc->sz].tele);
	//�Ż�ʱ��һ���ж�����
	printf("�������ַ:>\n");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�!\n");
}


//ͨ������������ϵ��
int FindName(Contact*pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//ɾ��ָ����ϵ��
void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��!\n");
		return;
	}
	char name[MAX_NAME] = {0};
	printf("����������Ҫɾ������ϵ�˵�����:>\n");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("��Ǹ����Ҫɾ������ϵ�˲�����!\n");
		return;
	}
	int i = 0;
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}


//��ӡ��ϵ����Ϣ
void PrintContact(Contact* pc)
{	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	//��ӡ��Ϣ
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name,
													pc->data[i].sex, 
													pc->data[i].age, 
													pc->data[i].tele, 
													pc->data[i].addr);
	}
}
//����ָ����ϵ��
void SearchContact(Contact* pc)
{
	char name[MAX_NAME];
	printf("��������Ҫ���ҵ���ϵ������:>\n");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("��Ǹ����Ҫ���ҵ���ϵ�˲�����!\n");
		return;
	}
	printf("�ҵ���!\n");
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	//��ӡ���ҵ����˵���Ϣ
	printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[ret].name,
												pc->data[ret].sex,
												pc->data[ret].age,
												pc->data[ret].tele,
												pc->data[ret].addr);


}


//�޸�ָ����ϵ����Ϣ
void ModifyContact(Contact* pc)
{
	//������һ�����޸ĵ���ϵ�˵�����
	printf("����������Ҫ�޸ĵ���ϵ�˵�����:>\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("��Ǹ������Ҫ�޸ĵ���ϰ�˵�����������!\n");
		return;
	}
	printf("����������:>\n");
	scanf("%s", pc->data[ret].name);
	printf("�������Ա�:>\n");
	scanf("%s", pc->data[ret].sex);
	printf("����������:>\n");
	scanf("%d", &(pc->data[ret].age));
	printf("������绰:>\n");
	scanf("%s", pc->data[ret].tele);
	//�Ż�ʱ��һ���ж�����
	printf("�������ַ:>\n");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ�!\n");
}


//��ͨѶ¼����ϵ�˽�������
int cmp_name(const void* p1,const void* p2)
{
	return strcmp(((Contact*)p1)->data->name, ((Contact*)p2)->data->name);
}
void SortContact(Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_name);
	printf("����ɹ�!\n");
}