#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
// ������ͻ 
//namespace sw
//{
//	int rand = 0;
//}
//
////int main()
////{
////	printf("hello world\n");
////	printf("%p\n", rand);
////
////	// �������޶���::
////	printf("%p\n", sw::rand);
////
////	return 0;
////}
//
//namespace sw
//{
//	// �����ռ��п��Զ������/����/����
//	//int rand = 10;
//
//	int add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//	namespace xxx
//	{
//		int rand = 1;
//	}
//}
//
//int Add(int left, int right)
//{
//	return (left + right);
//}
//
//int main()
//{
//	printf("%d\n", sw::rand);
//	printf("%d\n", sw::add(1,2));
//	printf("%d\n", Add(1, 2));
//
//	struct sw::Node node;
//
//	return 0;
//}

// ȫ��չ��(��Ȩ)
// using namespace bit;

// ����չ��(��Ȩ)
//using bit::Add;
//
//int main()
//{
//	printf("%p\n", rand);
//	printf("%d\n", bit::rand);
//	printf("%d\n", bit::xxx::rand);
//
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//
//	struct bit::Node node;
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////s

#include<iostream>



// ��һ���Ǹ�ʲô�ģ�ΪʲôҪ����һ��
// std��C++��׼��������ռ�
//using namespace std;

using std::cout;
using std::endl;



//int main()
//{
//	// << �����������
//	cout << "hello world" << endl;
//	cout << "hello world" << '\n';
//	cout << "hello world" << endl;
//
//	bit::StackInit();
//	bit::QueueInit();
//
//	// ����ȡ
//	int i = 0;
//	std::cin >> i;
//
//	return 0;
//}

//int main()
//{
//	int i;
//	double j;
//	std::cin >> i >> j;
//
//	cout << i << endl;
//	cout << j << endl;
//	printf("%.1f\n", j);
//
//	cout << &i << endl;
//	cout << &j << endl;
//
//	return 0;
//}

// ȱʡ����
//void Func(int a = 1)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func(2);
//
//	Func();
//
//	return 0;
//}

// ȫȱʡ
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func();
//
//	// ��ʾ���Σ�����������ʾ����
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//
//	return 0;
//}

// ��ȱʡ -- ����������󣬸�ȱʡֵ
void Func(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}


//int main()
//{
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//
//	bit::ST st1;
//	StackInit(&st1, 10);
//	for (size_t i = 0; i < 10; i++)
//	{
//		StackPush(&st1, i);
//	}
//
//	bit::ST st2;
//	StackInit(&st2, 100);
//	for (size_t i = 0; i < 100; i++)
//	{
//		StackPush(&st2, i);
//	}
//
//	// ��֪�����ܻ������ٸ�
//	bit::ST st3;
//	StackInit(&st3);
//
//	return 0;
//}

// C���Բ�����ͬ������
// CPP���ԣ�����Ҫ�󹹳ɺ�������
// ��������ͬ��������ͬ

//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//
//	return left + right;
//}

//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//
//	return left + right;
//}

void Swap(int* p1, int* p2)
{
	//...
}

void Swap(double* p1, double* p2)
{
	//...
}

void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}

void f(char a, int b)
{
	cout << "f(int a,char b)" << endl;
}

// ����ֵ��ͬ���ܹ�������
//int f(char a, int b)
//{
//	cout << "f(int a,char b)" << endl;
//}

//namespace bit1
//{
//	void func(int x)
//	{}
//}
//
//namespace bit1
//{
//	void func(double x)
//	{}
//}

//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	int i = 1, j = 2;
//	double k = 1.1, l = 2.2;
//	Swap(&i, &j);
//	Swap(&k, &l);
//	//cout << i;
//	//cout << k;
//
//	return 0;
//}

// ���ɺ�������
void func(int a, int b)
{
	cout << "void func(int a)" << endl;
}

void func(int a, int b, int c = 2)
{
	cout << "void func(int a, int b)" << endl;
}

int main()
{
	// ���ô������壬��֪�������ĸ�
	//func(1, 0);

	func(1, 3, 2);


	return 0;
}
