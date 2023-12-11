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

	// 循环引用
	n1->next = n2;
	n2->prev = n1;

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
}

template<class T>
struct DelArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

void test_shared_ptr4()
{
	// 定制删除器
	bit::shared_ptr<ListNode> sp1(new ListNode[10], DelArray<ListNode>());
	bit::shared_ptr<ListNode> sp2(new ListNode[10], [](ListNode* ptr) {delete[] ptr; });
	bit::shared_ptr<FILE> sp3(fopen("Test.cpp", "r"), [](FILE* ptr) {fclose(ptr); });

	bit::shared_ptr<ListNode> sp4(new ListNode);
}

//int main()
//{
//	//TestSmartPtr2();
//
//	//test_auto_ptr1();
//	//test_unique_ptr1();
//
//	test_shared_ptr4();
//
//	return 0;
//}


// 请设计一个类，只能在堆上创建对象
//class HeapOnly
//{
//public:
//	/*static void Destroy(HeapOnly* ptr)
//	{
//		delete ptr;
//	}*/
//
//	void Destroy()
//	{
//		delete this;
//	}
//private:
//	// 方案一：析构函数私有化
//	// 方案二：构造函数私有化
//	~HeapOnly()
//	{
//		cout << "~HeapOnly()" << endl;
//	}
//};
//
//int main()
//{
//	//HeapOnly hp1;
//	//static HeapOnly hp2;
//	HeapOnly* ptr = new HeapOnly;
//	//delete ptr;
//	//HeapOnly::Destroy(ptr);
//	ptr->Destroy();
//		
//	return 0;
//}

//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//
//	HeapOnly(const HeapOnly& hp) = delete;
//private:
//	// 方案一：析构函数私有化
//	// 方案二：构造函数私有化
//	HeapOnly()
//	{
//		cout << "HeapOnly()" << endl;
//	}
//};
//
//int main()
//{
//	//HeapOnly hp1;
//	//static HeapOnly hp2;
//	HeapOnly* ptr = HeapOnly::CreateObj();
//	//HeapOnly copy(*ptr);
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////
// 请设计一个类，只能在栈上创建对象
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly obj;
		return obj;
	}

	//StackOnly(const StackOnly&) = delete;

	void* operator new(size_t size) = delete;

	// 实现类专属的operator new
	// new这个类对象时，operator new就会调用这个，不会调全局的
	/*void* operator new(size_t size)
	{
		cout << "void* operator new(size_t size)" << endl;
		return malloc(size);
	}*/
private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};

//int main()
//{
//	StackOnly obj = StackOnly::CreateObj();
//	//StackOnly* ptr = new StackOnly;
//
//	//StackOnly* ptr = new StackOnly(obj);
//
//	//int i = (int)obj;
//
//	return 0;
//}

//int main()
//{
//	// 相近类型用static_cast->意义相似的类型
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// 有一定的关联，但是意义不相似的的类型用reinterpret_cast 
//	int* ptr = reinterpret_cast<int*>(a);
//
//	return 0;
//}

//void main()
//{
//	volatile const int a = 2;
//	//int* p = const_cast<int*>(&a);
//	int* p = (int*)&a;
//	*p = 3;
//
//	cout << a << endl;
//	cout << *p << endl;
//
//	cout << &a << endl;
//	cout << typeid(&a).name() << endl;
//	cout << (void*)&a << endl;
//	printf("%p\n", &a);
//	cout << p << endl;
//
//	char ch = 'x';
//	cout << (void*)&ch << endl;
//}

//void insert(size_t pos, char ch)
//{
//	int end = 10;
//	while (end >= pos)
//	{
//		cout << end << endl;
//		--end;
//	}
//}
//
//int main()
//{
//	insert(5, 'x');
//	insert(0, 'x');
//
//	return 0;
//}

class A
{
public:
	virtual void f() {}

	int _a = 0;
};

class B : public A
{

public:
	int _b = 1;
};

//int main()
//{
//	B objb;
//	A obja = objb;
//	A& ra = objb;
//
//	double d = 1.1;
//	const int& i = d;
//
//	return 0;
//}

//void fun(A* pa)
//{
//	//  向下转换：直接转换是不安全的
//	// 如果pa是指向父类A对象，存在越界问题
//	B* ptr = (B*)pa;
//	ptr->_a++;
//	ptr->_b++;
//}

void fun(A* pa)
{
	//  向下转换：直接转换是不安全的
	// 如果pa是指向父类A对象，存在越界问题
	B* ptr = dynamic_cast<B*>(pa);
	if (ptr)
	{
		ptr->_a++;
		ptr->_b++;
	}
	else
	{
		cout << "转换失败" << endl;
	}
}

int main()
{
	// 向下转换规则：父类对象不能转换成子类对象，但是父类指针和引用可以转换子类指针和引用
	B b1;
	int x = 0;
	A a;
	int y = 0;
	B b;
	fun(&a);
	fun(&b);

	return 0;
}