#define _CRT_SECURE_NO_WARNINGS 1

#include"STList.h"

//向内存申请一个新节点
STLNode* BuySTLNode(STLDataType x)
{
	STLNode* newnode = (STLNode*)malloc(sizeof(STLNode));
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

//打印链表中的元素
void SListPrint(STLNode* phead)
{
	STLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");

}


//尾插
void SlistPushBack(STLNode** pphead, STLDataType x)
{
	STLNode* newnode =BuySTLNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		STLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//头插
void SlistPushFront(STLNode** pphead, STLDataType x)
{
	STLNode * newnode = BuySTLNode(x);
		newnode->next= *pphead;
		*pphead = newnode;
}


//尾删
void SlistPopBack(STLNode** pphead)
{
	//1.空节点
	//2.1个节点
	//3.多个节点
	if ((*pphead) == NULL)
	{
		return;
	}
	else if ((*pphead)->next== NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		STLNode* prev = NULL;
		STLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}

	
}

//头删
void SlistPopFront(STLNode** pphead)
{
	STLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//查找
STLNode*  SlistFind(STLNode* phead, STLDataType x)
{
	STLNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos前面插入x
void SlistInsert(STLNode** pphead,STLNode* pos, STLDataType x)
{
	if (*pphead == pos)
	{
		SlistPushFront(pphead, x);
	}
	else
	{
		STLNode* newnode = BuySTLNode(x);
		STLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newnode = cur->next;
		newnode->next = pos;
	}
}

//删除pos 位置的值
void SlistErase(STLNode** pphead, STLNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		STLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
	}
}
