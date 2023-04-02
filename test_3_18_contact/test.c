#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
#include"stdlib.h"
//通讯录
//1.通讯录中能够存放1000个人的信息
//每个人的信息：
//名字+年龄+性别+电话+地址
//2.增加人的信息
//3.删除指定人的信息
//4.查找指定人的信息
//5.排序通讯录的信息
//6.修改指定人的信息
//7.打印通讯录信息

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
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input) 
		{
		case EXIT:
			//退出通讯录
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		case ADD:
			//增加联系人
			AddContact(&con);
			break;
		case DEL:
			//删除指定联系人
			DelContact(&con);
			break;
		case SEARCH :
			//查找指定联系人
			SearchContact(&con);
			break;
		case SORT:
			//给通讯录进行排序
			SortContact(&con);
			break;
		case MODIFY:
			//修改指定联系人
			ModifyContact(&con);
			break;
		case PRINT:
			//打印通讯录信息
			PrintContact(&con);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while(input);
	
	
	return 0;
}
