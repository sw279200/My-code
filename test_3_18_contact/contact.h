#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME 40
#define MAX_SEX 20
#define MAX_TELE 30
#define MAX_ADDR 50
#define MAX_DATA 1000
//����һ���ṹ����ͨѶ¼��ϵ����Ϣ
typedef struct PeoInfo{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼
typedef struct Contact {
	PeoInfo data[MAX_DATA];
	int sz;
}Contact;


//��ʼ��ͨѶ¼
void InitContact(Contact * pc);

//���ָ����ϵ��
void AddContact(Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(Contact* pc);

//��ӡ��ϵ����Ϣ
void PrintContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(Contact* pc);

//�޸�ָ����ϵ����Ϣ
void ModifyContact(Contact* pc);

//��ͨѶ¼��������
void SortContact(Contact* pc);
