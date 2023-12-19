#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include<string>
using namespace std;

#include"stack_queue.h"
#include"PriorityQueue.h"
void test_stack1()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	cout << st.top() << " ";
	st.pop();
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() <<" ";
		st.pop();
	}
}

void test_stack2()
{
	mystack::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}


void test_queue1()
{
	queue<int> q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}


void test_queue2()
{
	myqueue::queue<int> q;
	q.push(4);
	q.push(3);
	q.push(1);
	q.push(0);
	q.push(2);
	q.push(5);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test_mypriority_queue()
{
	bite::priority_queue<int> pq;
	pq.push(4);
	pq.push(3);
	pq.push(1);
	pq.push(0);
	pq.push(2);
	pq.push(5);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}


int main()
{
	//test_stack2();
	//test_queue1();
	//test_queue2();
	//test_mypriority_queue();
	TestQueuePriority();
	return 0;
}