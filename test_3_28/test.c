#define _CRT_SECURE_NO_WARNINGS 1

#include"STList.h"

void STListTest1()
{
	STLNode* plist = NULL;
	SlistPushBack(&plist, 1);
	SlistPushBack(&plist, 2);
	SlistPushBack(&plist, 3);
	SlistPushBack(&plist, 4);
	SlistPushBack(&plist, 5);
	SlistPushBack(&plist, 6);
	SListPrint(plist);
	SlistPushFront(&plist, 0);
	SlistPushFront(&plist, 10);
	SListPrint(plist);
}

void STListTest2()
{
	STLNode* plist = NULL;
	SlistPushBack(&plist, 1);
	SlistPushBack(&plist, 2);
	SlistPushBack(&plist, 3);
	SlistPushBack(&plist, 4);
	SlistPushBack(&plist, 5);
	SlistPushBack(&plist, 6);
	SListPrint(plist);
	SlistPushFront(&plist, 0);
	SlistPushFront(&plist, 10);
	SListPrint(plist);
	SlistPopBack(&plist);
	SlistPopBack(&plist);
	SlistPopFront(&plist);
	SlistPopFront(&plist);
	SListPrint(plist);
	
}
int main()
{
	//STListTest1();
	STListTest2();
	return 0;
}
