#define _CRT_SECURE_NO_WARNINGS 1

#include"STList.h"

//���ڴ�����һ���½ڵ�
STLNode* BuySTLNode(STLDataType x)
{
	STLNode* newnode = (STLNode*)malloc(sizeof(STLNode));
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

//��ӡ�����е�Ԫ��
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


//β��
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

//ͷ��
void SlistPushFront(STLNode** pphead, STLDataType x)
{
	STLNode * newnode = BuySTLNode(x);
		newnode->next= *pphead;
		*pphead = newnode;
}


//βɾ
void SlistPopBack(STLNode** pphead)
{
	//1.�սڵ�
	//2.1���ڵ�
	//3.����ڵ�
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

//ͷɾ
void SlistPopFront(STLNode** pphead)
{
	STLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//����
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

//��posǰ�����x
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

//ɾ��pos λ�õ�ֵ
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
