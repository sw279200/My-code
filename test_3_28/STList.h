#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef int STLDataType;

typedef struct STListNode
{
	STLDataType data;
	struct STListNode* next;
}STLNode;


//���ڴ�����һ���½ڵ�
STLNode* BuySTLNode(STLDataType x);

//��ӡ�����е�Ԫ��
void SListPrint(STLNode* phead);


//β��
void SlistPushBack(STLNode** pphead, STLDataType x);

//ͷ��
void SlistPushFront(STLNode** pphead, STLDataType x);

//βɾ
void SlistPopBack(STLNode** pphead);

//ͷɾ
void SlistPopFront(STLNode** pphead);

//����
STLNode* SlistFind(STLNode * phead,STLDataType x);

//����λ�ò���
void SlistInsert(STLNode** pphead, STLNode* pos, STLDataType x);

//ɾ������
void SlistErase(STLNode** pphead, STLNode* pos);

