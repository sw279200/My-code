#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include"SmartPtr.h"

void TestSmartPtr1()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 1;

	SmartPtr<pair<string, int>>sp2(new pair<string, int>("xxx",1));
	sp2.operator->()->first += 'y';
	sp2->first += 'z';
	sp2->second += 1;
	sp2.operator->()->second += 1;
	cout << sp2->first << ":" << sp2->second << endl;
}

void TestSmartPtr2()
{
	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2 = sp1;
}

void Testunique_ptr1()
{
	/*bit::unique_ptr<int> sp1(new int);
	bit::unique_ptr<int> sp2(sp1);*/

	/*std::unique_ptr<int> sp1(new int);
	std::unique_ptr<int> sp2(sp1);*/
}



void test_shared_ptr2()
{
	bit::shared_ptr<string> sp1(new string("xxxxxxxxxxxxxxxxxx"));
	bit::shared_ptr<string> sp2(sp1);

	bit::shared_ptr<string> sp3(new string("yyyyyyyyy"));

	//sp1 = sp3;
	//sp3 = sp1;

	sp3 = sp3;
	cout << *sp3 << endl;

	sp1 = sp2;
}

struct ListNode
{
	int val;
	bit::weak_ptr<ListNode> next;
	bit::weak_ptr<ListNode> prev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

void test_shared_ptr3()
{
	bit::shared_ptr<ListNode> n1(new ListNode);
	bit::shared_ptr<ListNode> n2(new ListNode);
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	// Ñ­»·ÒýÓÃ
	n1->next = n2;
	n2->prev = n1;

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
}

int main()
{
	//TestSmartPtr2();

	//test_auto_ptr1();
	//test_unique_ptr1();

	test_shared_ptr3();

	return 0;
}