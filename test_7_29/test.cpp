#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//// �ۻ������˶��ٸ�����  
//int n = 0;
//
//// ����ʹ�õĻ��ж��ٸ�����
//int m = 0;
//
//class A
//{
//public:
//	A()
//	{
//		++n;
//		++m;
//	}
//
//	A(const A& t)
//	{
//		++n;
//		++m;
//	}
//
//	~A() 
//	{
//		--m;
//	}
//private:
//};
//
////A& Func(A& aa)
//A Func(A aa)
//{
//	return aa;
//}
//
//int main()
//{
//	A aa1;
//	A aa2;
//	cout << n << " " << m << endl;
//	
//	// ���ܱ����������޸�
//	//--n;
//	//++m;
//	A();
//	cout << n << " " << m << endl;
//
//
//	Func(aa1);
//	cout << n << " " << m << endl;
//
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		++n;
//		++m;
//	}
//
//	A(const A& t)
//	{
//		++n;
//		++m;
//	}
//
//	~A()
//	{
//		--m;
//	}
//
//	// ��̬��Ա�������ص㣺û��thisָ��
//	static int GetM()
//	{
//		return m;
//	}
//
//	// ...
//
//	static void Print()
//	{
//		// x++; // ���ܷ��ʷǾ�̬����Ϊû��this
//
//		cout << m <<" " << n << endl;
//	}
//
//private:
//	// ��̬��Ա������������A��������������
//	// ����
//	// �ۻ������˶��ٸ�����  
//	static int n;
//	// ����ʹ�õĻ��ж��ٸ�����
//	static int m;
//
//	int x = 0;
//};
//
////class SeqList
////{
////	int& operator[](int i)
////	{
////		return a[i];
////	}
////
////private:
////	int a[10];
////};
//
//// ����
//int A::n = 0;
//int A::m = 0;
//
////A& Func(A& aa)
//A Func(A aa)
//{
//	return aa;
//}
//
//int main()
//{
//	A();
//	A();
//
//	A::Print();
//	++A::GetM();
//	A::Print();
//
//	A aa1;
//	Func(aa1);
//
//	aa1.Print();
//
//	return 0;
//}

//int main()
//{
//	A aa1;
//	A aa2;
//	cout << A::n << " " << A::m << endl;
//	cout << aa1.n << " " << aa2.m << endl;
//	A* ptr = nullptr;
//	cout << ptr->n << " " << ptr->m << endl;
//
//	// ���ܱ����������޸�
//	A();
//	cout << n << " " << m << endl;
//
//	Func(aa1);
//	cout << n << " " << m << endl;
//
//	return 0;
//}

// ��Ԫ����
// ��Ԫ��
// �ܲ�����Ԫ�Ͳ�Ҫ��
// 10:30jixu

//class B
//{
//private:
//	int _b;
//};
//
//class A
//{
//public:
//	
//private:
//	int _a;
//};

// 1��B����A����ͷ����޶��������ƣ���ʵ������������������
// 2���ڲ���Ĭ�Ͼ����ⲿ�����Ԫ��
//class A
//{
////public:
//	class B
//	{
//	public:
//		void FuncB()
//		{
//			A aa;
//			aa._a = 1;
//		}
//	private:
//		int _b;
//	};
//
//	void func()
//	{
//		B bb;
//	}
//
//private:
//	int _a;
//};
//
//
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	A aa;
//	//A::B bb1;
//
//	return 0;
//}

// �˽ⷶ��
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void Print() const
//	{
//		cout <<"Print->" << _a << endl;
//	}
//private:
//	int _a = 0;
//};

//void f1(const A& aa = A())
//{
//	aa.Print();
//}
//
//int main()
//{
//	A aa1;
//	f1(aa1);
//
//	f1(A(1));
//	f1(2);
//	f1();
//
//	A();
//
//	// const���û��ӳ�����������������
//	// ref�������������������������
//	const A& ref = A();
//	A aa2;
//	return 0;
//}

//void f1(A aa)
//{
//	aa.Print();
//}
//
//int main()
//{
//	A aa1;
//	f1(aa1);
//
//	cout << "--------------------------" << endl;
//	// һ�����ʽ�������Ĳ������棬�����Ĺ���ᱻ�ϲ�
//	f1(A(1));
//
//	cout << "--------------------------" << endl;
//	f1(1);
//
//	cout << "--------------------------" << endl;
//	A aa2 = 1;
//
//	cout << "--------------------------" << endl;
//	A aa3 = A(2);
//
//	return 0;
//}

//A f2()
//{
//	A aa;
//	return aa;
//}
//
//int main()
//{
//	A ret1 = f2();
//
//	cout << "---------------------------------" << endl;
//	A ret2;
//	ret2 = f2();
//
//	return 0;
//}

// 11��46����
// �����̽��C++����ģ�͡�
//A f2()
//{
//	A aa;
//	return aa;
//
//	return A(1);
//	return 2;
//}

//int main()
//{
//	A ret1 = f2();
//
//	cout << "--------------------------" << endl;
//	A aa2 = 1;
//
//	cout << "--------------------------" << endl;
//	A aa3 = A(2);
//
//
//	return 0;
//}

//int main()
//{
//	int* p2 = (int*)malloc(sizeof(int));
//	// �Զ������С������Ҫǿת 
//	int* p3 = new int;
//
//	int* p4 = (int*)malloc(sizeof(int)*10);
//	int* p5 = new int[10];
//
//	free(p2);
//	free(p4);
//
//	delete p3;
//	delete[] p5;
//
//	// ����֧�ֿ��ռ�+��ʼ��
//	int* p6 = new int(10);
//	int* p7 = new int[10]{1,2,3};
//	int* p8 = new int[10]{};
//
//	return 0;
//}int main()
//{
//	int* p2 = (int*)malloc(sizeof(int));
//	// �Զ������С������Ҫǿת 
//	int* p3 = new int;
//
//	int* p4 = (int*)malloc(sizeof(int)*10);
//	int* p5 = new int[10];
//
//	free(p2);
//	free(p4);
//
//	delete p3;
//	delete[] p5;
//
//	// ����֧�ֿ��ռ�+��ʼ��
//	int* p6 = new int(10);
//	int* p7 = new int[10]{1,2,3};
//	int* p8 = new int[10]{};
//
//	return 0;
//}int main()
//{
//	int* p2 = (int*)malloc(sizeof(int));
//	// �Զ������С������Ҫǿת 
//	int* p3 = new int;
//
//	int* p4 = (int*)malloc(sizeof(int)*10);
//	int* p5 = new int[10];
//
//	free(p2);
//	free(p4);
//
//	delete p3;
//	delete[] p5;
//
//	// ����֧�ֿ��ռ�+��ʼ��
//	int* p6 = new int(10);
//	int* p7 = new int[10]{1,2,3};
//	int* p8 = new int[10]{};
//
//	return 0;
//}

class A
{
public:
	//A�Ĺ��캯��
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	//��������
	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

struct ListNode
{
	ListNode* _next;
	int _val;

	ListNode(int val = 0)
		:_val(0)
		, _next(nullptr)
	{}
};

int main()
{
	// mallocû�а취�ܺ�֧�ֶ�̬������Զ�������ʼ��
	A* p1 = (A*)malloc(sizeof(A));
	//p1->_a = 0;
	//p1->A(1);

	// �Զ������ͣ����ռ�+���ù��캯����ʼ��
	A* p2 = new A;
	A* p3 = new A(3);

	// �Զ������ͣ�������������+�ͷſռ�
	delete p2;
	delete p3;

	A* p4 = new A[10];
	delete[] p4;

	A aa1(1);
	A aa2(2);
	A* p5 = new A[10]{ aa1, aa2 };
	delete[] p5;


	A* p6 = new A[10]{ A(1), A(2) };
	delete[] p6;

	A* p7 = new A[10]{ 1, 2 };
	delete[] p7;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);

	n1->_next = n2;
	n2->_next = n3;
	n3->_next = n4;
	n4->_next = n5;

	// ...

	return 0;
}