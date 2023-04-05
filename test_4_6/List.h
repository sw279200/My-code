#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int LTDataType;
//有头双向循环链表
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}ListNode;


//初始化，申请一个头结点
ListNode* ListInit();


//双链表尾插
void ListPushBack(ListNode* phead,LTDataType x);

//双链表头插
void ListPushFront(ListNode* phead, LTDataType x);

//打印
void ListPrint(ListNode* phead);

//双链表尾删
void ListPopBack(ListNode* phead);

//双链表头删
void ListPopFront(ListNode* phead);

//查找
ListNode* ListFind(ListNode* phead,LTDataType x);

//在pos前插入一个结点
void ListInsert(ListNode* pos, LTDataType x);

//删除pos位置上的结点
void ListErase(ListNode* pos);

//销毁链表
void ListDestroy(ListNode* phead);
