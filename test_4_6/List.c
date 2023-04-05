#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"


//申请一个新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}


ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}


//双链表尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	//assert(phead);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* plist = phead->prev;
	//plist->next = newnode;
	//newnode->prev = plist;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}

//双链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* first = phead->next;
	newnode->next = first;
	first->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/
	ListInsert(phead->next, x);
}

//打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//双链表尾删
void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//ListNode* prev = phead->prev;
	//ListNode* next = prev->prev;
	//next->next = phead;
	//phead->prev = next;
	//free(prev);
	//prev = NULL;
	ListErase(phead->prev);
}

//双链表头删
void ListPopFront(ListNode* phead)
{
	//assert(phead);
	//ListNode* first = phead->next;
	//ListNode* second = first->next;
	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;
	ListErase(phead->next);
}

//查找
ListNode* ListFind(ListNode* phead,LTDataType x)
{
	ListNode* pos = phead->next;
	
	while (pos != phead)
	{
		if (pos->data == x)
		{
			return pos;
		}
		pos = pos->next;
	}
	return NULL;
}

//在pos前插入一个结点
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* cur = pos->prev;
	cur->next = newnode;
	newnode->prev = cur;
	newnode->next = pos;
	pos->prev = newnode;
}

//删除pos位置上的结点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
}


//销毁链表
void ListDestroy(ListNode* phead)
{
	ListNode* cur = phead->next;
	
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
