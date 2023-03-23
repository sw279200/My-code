#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<stdio.h>

//测试顺序表的各项功能
void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);

}
void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}
void TestSeqList3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	//SeqListPrint(&sl);
	SeqListInsert(&sl, 1, 20);
	//SeqListPrint(&sl);

	SeqListErase(&sl, 1);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}
int main()
{
	TestSeqList3();
	//TestSeqList1();
	//TestSeqList2();
	return 0;
}
