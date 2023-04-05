#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"


//����һ���½ڵ�
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


//˫����β��
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

//˫����ͷ��
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

//��ӡ
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

//˫����βɾ
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

//˫����ͷɾ
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

//����
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

//��posǰ����һ�����
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

//ɾ��posλ���ϵĽ��
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
}


//��������
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
