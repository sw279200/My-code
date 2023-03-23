#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define MAX_NAME 40
#define MAX_SEX 20
#define MAX_TELE 30
#define MAX_ADDR 50
#define MAX_DATA 1000
#define DAFAULT_SZ   3 //初始化容量
#define INC_SZ   2   //每次增加的容量
//定义一个结构体存放通讯录联系人信息
typedef struct PeoInfo{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录
typedef struct Contact {
	PeoInfo *data;//存放通讯录信息
	int sz;//记录通讯录的大小
	int capacity;//记录当前容量
}Contact;


//初始化通讯录
void InitContact(Contact * pc);

//销毁通讯录
void DestroyContact(Contact* pc);

//添加指定联系人
void AddContact(Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//打印联系人信息
void PrintContact(Contact* pc);

//查找指定联系人
void SearchContact(Contact* pc);

//修改指定联系人信息
void ModifyContact(Contact* pc);

//对通讯录进行排序
void SortContact(Contact* pc);
