#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>

using namespace std;

void test_list1()
{
	list<int> lt1;   //1.这里我们构造了一个空的list对象

	list<int> lt2(10, 100);  // 2.这里我们通过用构造了10个100的方式构造了lt2

	//由于list不支持随机访问，所以下面我们需要借助迭代器遍历一下lt2

	cout << "lt2中的元素遍历：" << endl;
	list<int>::iterator it = lt2.begin();
	while (it != lt2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	cout << "lt3拷贝lt2构造后的元素遍历：" << endl;
	list<int> lt3(lt2);
	list<int>::iterator its = lt3.begin();
	while (its != lt3.end())
	{
		cout << *its << " ";
		its++;
	}
	cout << endl;

	list<int> lt4(lt3.begin(), lt3.end());
	cout << "lt4用lt3的迭代器区间构造后的元素遍历：" << endl;
	list<int>::iterator it1 = lt4.begin();
	while (it1 != lt4.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

}


void test_list2()
{
	//迭代器的使用,我们就简单通过常用的正反向迭代器进行说明,
	//前面加了const的迭代器只需要记得不能修改迭代器所指向的内容

	//1.正向迭代器，我们用简单的遍历list元素来说明
	list<int> lt;
	lt.push_back(1);    //在list里面插入6个结点
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	cout << "正向迭代器的遍历：" << endl;
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 2.反向迭代器
	list<int>::reverse_iterator rit = lt.rbegin();
	cout << "反向迭代器的遍历：" << endl;
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

}

void test_list3()
{
	//empty()接口和size()接口的使用，你会发现跟vector相比没有capacity（）
	list<int>  lt;
	cout << "empty():" << lt.empty() << endl;
	cout << "size():" << lt.size() << endl;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	cout << "插入三个元素之后" << endl;
	cout << "empty():" << lt.empty() << endl;
	cout << "size():" << lt.size() << endl;
}


void test_list4()
{
	//front()接口和 back()接口的测试

	list<int>  lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	cout << "遍历" << endl;
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << "第一个元素" << endl;
	cout << lt.front() << endl;
	cout << "最后一个元素" << endl;
	cout << lt.back() << endl;
}


void test_list5()
{
	list<int> lt;
	//尾插
	for (int i = 0; i < 10; i++)//尾插后的结点值是0 1 2 3 4 5 6 7 8 9
	{
		lt.push_back(i);
	}

	//我们这里使用简单的范围for来进行遍历
	cout << "尾插后链表中的结点值为：" << endl;

	for (auto e : lt)//范围for借助迭代器自动推导e的类型，自动给e赋值，自动往后++
	{
		cout << e << " ";
	}
	cout << endl;


	//头插
	lt.push_front(10);
	lt.push_front(20);    //头插这两个结点后变成：20 10 0 1 2 3 4 5 6 7 8 9
	cout << "头插后的链表结点值为：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	//头删
	lt.pop_front();
	lt.pop_front();
	lt.pop_front();     //头删之后变成：1 2 3 4 5 6 7 8 9
	cout << "头删之后：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	//尾删
	lt.pop_back();
	lt.pop_back();
	lt.pop_back();     //尾删之后变成： 1 2 3 4 5 6
	cout << "尾删之后：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	//在pos位置插入一个值为val的结点
	list<int>::iterator it = lt.begin();
	it++;
	lt.insert(it, 20);  //此时变成 1 20 2 3 4 5 6

	cout << "在第2个结点位置插入一个20:" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//在pos位置插入n个值为val的结点
	it++;
	++it;
	lt.insert(it, 5, 30);//在第4个结点的位置插入5个30
	cout << "在第4个结点的位置插入5个30后：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//在pos位置插入一段迭代器区间
	list<int> lt2(10, 100);
	lt.insert(it, lt2.begin(), lt2.end());//将lt2的10个值为100的结点从lt的第4个结点插入
	cout << "插入一段迭代器区间之后:" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//删除pos位置的结点   这里我们会涉及一个迭代器失效的问题，我们后面再说
	it = lt.erase(it);
	cout << "删除it位置的结点后：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//删除一段迭代器区间的结点
	it = lt.erase(it, lt.end());//我们将it以及之后的结点都删除
	cout << "将it后面位置的结点都删除了" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//交换两个链表
	//我们先看看lt和lt2的两个链表结点的值，然后交换
	cout << "lt：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "lt2:" << endl;
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	//交换后
	lt.swap(lt2);
	cout << "交换后：" << endl;
	cout << "lt：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "lt2:" << endl;
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	//将链表数据清空
	cout << "将两个链表的数据都清空之后：" << endl;
	lt.clear();
	lt2.clear();
	cout << "lt：" << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "lt2:" << endl;
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

}


void TestListIterator1()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给
		//其赋值
			l.erase(it);
		++it;
	}
}

// 改正
void TestListIterator()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++); // it = l.erase(it);
	}
}


//int main()
//{
//
//	int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
//
//	int n = sizeof(array) / sizeof(int);
//
//	list<int> mylist(array, array + n);
//
//	auto it = mylist.begin();
//
//	while (it != mylist.end())
//
//	{
//
//		if (*it != 0)
//
//			cout << *it << " ";
//
//		else
//
//			it = mylist.erase(it);
//
//		++it;
//
//	}
//
//	return 0;
//
//}

int main()
{
	//test_list5();
	TestListIterator();
	return 0;
}