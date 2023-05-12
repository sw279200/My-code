#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void printDeque(const deque<int>& d)
{
	for (deque<int >::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Test1()
{
	//deque的构造函数
	deque<int > d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}

	printDeque(d);

	deque<int> d1(d.begin(), d.end());
	printDeque(d1);

	deque<int> d2(10, 100);
	printDeque(d2);

	deque<int> d3 = d2;
	printDeque(d3);
}

void Test2()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i * 10);
	}

	printDeque(d1);

	deque<int> d2;
	d2.assign(d1.begin(), d1.end());
	printDeque(d2);

	deque<int >d3;
	d3.assign(10, 100);
	printDeque(d3);

}

void Test3()
{
	//deque大小操作
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}

	printDeque(d);

	if (d.empty())
	{
		cout << "d为空" << endl;
	}
	else
	{
		cout << "d不为空" << endl;
		cout << "d的大小为：" << d.size() << endl;
	}

	//重置d的大小
	d.resize(15, 5);
	printDeque(d);

	d.resize(5);
	printDeque(d);


}


//deque容器的插入删除
void Test4()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(30);
	d.push_back(50);
	d.push_back(70);
	d.push_back(90);
	printDeque(d);

	d.push_front(20);
	d.push_front(30);
	printDeque(d);


	d.pop_front();
	d.pop_back();
	printDeque(d);

	deque<int> d1;
	d1.insert(d1.begin(), 6);
	d1.insert(d1.begin(), 3, 8);
	printDeque(d1);

	d1.insert(d1.begin(), d.begin(), d.end());
	printDeque(d1);

	//把第二个位置的元素删除
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);
	//相当于清空
	//d1.erase(it, d1.end());
	d1.clear();
	printDeque(d1);
}

void Test5()
{
	deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_front(100);
	dq.push_front(200);
	dq.push_front(300);

	printDeque(dq);

	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq.at(i) << " ";
	}
	cout << endl;

	cout << "deque的首元素为：" << dq.front() << endl;

	cout<< "deque的末尾元素为：" << dq.back() << endl;

}

//排序
void Test6()
{
	deque<int > d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(100);
	d.push_back(300);
	d.push_back(200);
	d.push_back(30);

	printDeque(d);

	cout << "排序后：" << endl;
	sort(d.begin(), d.end());
	printDeque(d);
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
	return 0;
}

#endif