#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

////静态版本
////初始化通讯录
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

int CheckCapacity(Contact* pc);
void LoadContact(Contact* pc)
{
	//打开文件
	FILE* pf = fopen("test.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//加载文件内容到通讯录中
	PeoInfo temp = { 0 };
	while (fread(&temp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		pc->data[pc->sz] = temp;
		pc->sz++;

	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}
//动态版本的通讯录初始化
void InitContact(Contact* pc)
{
	PeoInfo* ptr = (PeoInfo*)malloc(DAFAULT_SZ * sizeof(PeoInfo));
	if (NULL == ptr)
	{
		printf("通讯录初始化失败:%s\n", strerror(errno));
		return;
	}
	pc->data = ptr;
	pc->capacity = DAFAULT_SZ;
	pc->sz = 0;

	//加载文件到通讯录中
	LoadContact(pc);
}
//销毁通讯录
void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("释放内存\n");
}
////静态版本
////实现添加指定联系人
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX_DATA)
//	{
//		printf("通讯录已满，无法添加!\n");
//		return;
//	}
//	printf("请输入姓名:>\n");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入性别:>\n");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入年龄:>\n");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入电话:>\n");
//	scanf("%s", pc->data[pc->sz].tele);
//	//优化时加一个判断条件
//	printf("请输入地址:>\n");
//	scanf("%s", pc->data[pc->sz].addr);
//	pc->sz++;
//	printf("添加成功!\n");
//}

int CheckCapacity(Contact* pc)
{
	if (pc->capacity == pc->sz)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, INC_SZ * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("扩容失败:%s\n", strerror(errno));
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
			printf("当前容量为:%d\n", pc->capacity);
			return 1;
		}
	}
	return 1;
}
void AddContact(Contact* pc)
{
	if (CheckCapacity == 0)
	{
		printf("空间不够，扩容失败\n");
		return;
	}
	else
	{
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


void SaveContact(Contact* pc)
{
	//打开文件
	FILE* pf = fopen("test.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//写数据
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(struct PeoInfo), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
	printf("保存成功\n");
}