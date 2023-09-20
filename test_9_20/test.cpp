#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#include"list.h"

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;


	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_op()
{
	srand(time(0));
	const int N = 1000000;

	list<int> lt1;
	list<int> lt2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		lt1.push_back(e);
		lt2.push_back(e);
	}

	int begin1 = clock();
	// vector

	vector<int> v(lt2.begin(), lt2.end());
	// 
	sort(v.begin(), v.end());

	// lt2
	lt2.assign(v.begin(), v.end());

	int end1 = clock();

	int begin2 = clock();
	lt1.sort();
	int end2 = clock();

	printf("list copy vector sort copy list sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(5);
	lt.push_back(5);
	lt.push_back(3);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.sort();
	lt.unique(); //

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//lt.remove(30);
	lt.remove(3);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list3()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl;

	//mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
								  // mylist2 (empty)
								  // "it" still points to 2 (the 5th element)

	//mylist1.splice(it, mylist2, ++mylist2.begin()); // mylist1: 1 20 2 3 4

	// 10:20
	mylist1.splice(it, mylist2, ++mylist2.begin(), mylist2.end()); // mylist1: 1 20 30 2 3 4

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_list3();
	//test_op();
	mylist::test_list4();
	return 0;
}