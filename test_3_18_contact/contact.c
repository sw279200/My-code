#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


//初始化通讯录
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
//输入一个电话号码验证该电话号码是否已存在

//实现添加指定联系人
void AddContact(Contact* pc)
{
	if (pc->sz == MAX_DATA)
	{
		printf("通讯录已满，无法添加!\n");
		return;
	}
	printf("请输入姓名:>\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话:>\n");
	scanf("%s", pc->data[pc->sz].tele);
	//优化时加一个判断条件
	printf("请输入地址:>\n");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功!\n");
}


//通过姓名查找联系人
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
//删除指定联系人
void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除!\n");
		return;
	}
	char name[MAX_NAME] = {0};
	printf("请输入你想要删除的联系人的姓名:>\n");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("抱歉，你要删除的联系人不存在!\n");
		return;
	}
	int i = 0;
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}


//打印联系人信息
void PrintContact(Contact* pc)
{	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	//打印信息
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
//查找指定联系人
void SearchContact(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入你要查找的联系人姓名:>\n");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("抱歉，你要查找的联系人不存在!\n");
		return;
	}
	printf("找到了!\n");
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	//打印查找到的人的信息
	printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[ret].name,
												pc->data[ret].sex,
												pc->data[ret].age,
												pc->data[ret].tele,
												pc->data[ret].addr);


}


//修改指定联系人信息
void ModifyContact(Contact* pc)
{
	//先输入一个想修改的联系人的姓名
	printf("请输入你想要修改的联系人的姓名:>\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("抱歉，你想要修改的练习人的姓名不存在!\n");
		return;
	}
	printf("请输入姓名:>\n");
	scanf("%s", pc->data[ret].name);
	printf("请输入性别:>\n");
	scanf("%s", pc->data[ret].sex);
	printf("请输入年龄:>\n");
	scanf("%d", &(pc->data[ret].age));
	printf("请输入电话:>\n");
	scanf("%s", pc->data[ret].tele);
	//优化时加一个判断条件
	printf("请输入地址:>\n");
	scanf("%s", pc->data[ret].addr);
	printf("修改成功!\n");
}


//对通讯录的联系人进行排序
int cmp_name(const void* p1,const void* p2)
{
	return strcmp(((Contact*)p1)->data->name, ((Contact*)p2)->data->name);
}
void SortContact(Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_name);
	printf("排序成功!\n");
}