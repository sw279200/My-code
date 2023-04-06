#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void ListTest1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPrint(plist);
	ListPushFront(plist, 2);
	ListPushFront(plist, 1);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

}
void ListTest2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPrint(plist);
	ListPushFront(plist, 2);
	ListPushFront(plist, 1);
	ListPrint(plist);
	ListErase(ListFind(plist, 3));
	ListInsert(ListFind(plist, 4), 30);
	ListPrint(plist);
}
int main()
{
	ListTest2();
	return 0;
}
