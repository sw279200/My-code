#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int LTDataType;
//��ͷ˫��ѭ������
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}ListNode;


//��ʼ��������һ��ͷ���
ListNode* ListInit();


//˫����β��
void ListPushBack(ListNode* phead,LTDataType x);

//˫����ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

//��ӡ
void ListPrint(ListNode* phead);

//˫����βɾ
void ListPopBack(ListNode* phead);

//˫����ͷɾ
void ListPopFront(ListNode* phead);

//����
ListNode* ListFind(ListNode* phead,LTDataType x);

//��posǰ����һ�����
void ListInsert(ListNode* pos, LTDataType x);

//ɾ��posλ���ϵĽ��
void ListErase(ListNode* pos);

//��������
void ListDestroy(ListNode* phead);
