#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
typedef struct MyLinkedList {
	struct MyLinkedList* prev;
	struct MyLinkedList* next;
	int data;
} MyLinkedList;

MyLinkedList* BuyListNode(int x)
{
	MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

MyLinkedList* myLinkedListCreate() {
	MyLinkedList* phead = BuyListNode(0);
	phead->prev = phead;
	phead->next = phead;
	return phead;
    
}

int myLinkedListGet(MyLinkedList* phead, int index) {
	MyLinkedList* pos = phead->next;
	int len = 0;
	while (pos != phead)
	{
		if (len == index)
		{
			return pos->data;
		}
		len++;
		pos = pos->next;
	}

	return -1;
}

void myLinkedListAddAtHead(MyLinkedList* phead, int val) {
	assert(phead);
	MyLinkedList* newnode = BuyListNode(val);
	MyLinkedList* first = phead->next;
	newnode->next = first;
	first->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}

void myLinkedListAddAtTail(MyLinkedList* phead, int val) {
	assert(phead);
	MyLinkedList* newnode = BuyListNode(val);
	MyLinkedList* plist = phead->prev;
	plist->next = newnode;
	newnode->prev = plist;
	newnode->next = phead;
	phead->prev = newnode;
}

void myLinkedListAddAtIndex(MyLinkedList* phead, int index, int val) {
	MyLinkedList* newnode = BuyListNode(val);
	MyLinkedList* pos = phead->next;
	int len = 0;
	while (pos != phead)
	{

		if (len == index)
		{
			MyLinkedList* cur = pos->prev;
			cur->next = newnode;
			newnode->prev = cur;
			newnode->next = pos;
			pos->prev = newnode;
			return;
		}

		pos = pos->next;
		len++;
	}
	if (len == index)
	{
		assert(phead);
		MyLinkedList* newnode = BuyListNode(val);
		MyLinkedList* plist = phead->prev;
		plist->next = newnode;
		newnode->prev = plist;
		newnode->next = phead;
		phead->prev = newnode;
	}
	return;

}

void myLinkedListDeleteAtIndex(MyLinkedList* phead, int index) {
	MyLinkedList* pos = phead->next;
	int len = 0;
	while (pos != phead)
	{

		if (len == index)
		{
			MyLinkedList* next = pos->next;
			MyLinkedList* prev = pos->prev;
			prev->next = next;
			next->prev = prev;
			free(pos);
			return;
		}

		pos = pos->next;
		len++;
	}
	return;
}

void myLinkedListFree(MyLinkedList* phead) {
	MyLinkedList* cur = phead->next;

	while (cur != phead)
	{
		MyLinkedList* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/