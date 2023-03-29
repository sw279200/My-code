#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef int STLDataType;

typedef struct STListNode
{
	STLDataType data;
	struct STListNode* next;
}STLNode;


//向内存申请一个新节点
STLNode* BuySTLNode(STLDataType x);

//打印链表中的元素
void SListPrint(STLNode* phead);


//尾插
void SlistPushBack(STLNode** pphead, STLDataType x);

//头插
void SlistPushFront(STLNode** pphead, STLDataType x);

//尾删
void SlistPopBack(STLNode** pphead);

//头删
void SlistPopFront(STLNode** pphead);

//查找
STLNode* SlistFind(STLNode * phead,STLDataType x);

//任意位置插入
void SlistInsert(STLNode** pphead, STLNode* pos, STLDataType x);

//删除操作
void SlistErase(STLNode** pphead, STLNode* pos);

