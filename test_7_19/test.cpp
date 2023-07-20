#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
// 命名冲突 
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
////	// 域作用限定符::
////	printf("%p\n", sw::rand);
////
////	return 0;
////}
//
//namespace sw
//{
//	// 命名空间中可以定义变量/函数/类型
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

// 全部展开(授权)
// using namespace bit;

// 部分展开(授权)
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



// 这一行是干什么的？为什么要有这一行
// std是C++标准库的命名空间
//using namespace std;

using std::cout;
using std::endl;



//int main()
//{
//	// << 流插入运算符
//	cout << "hello world" << endl;
//	cout << "hello world" << '\n';
//	cout << "hello world" << endl;
//
//	bit::StackInit();
//	bit::QueueInit();
//
//	// 流提取
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

// 缺省参数
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

// 全缺省
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
//	// 显示传参，从左往右显示传参
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//
//	return 0;
//}

// 半缺省 -- 必须从右往左，给缺省值
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
//	// 不知道可能会插入多少个
//	bit::ST st3;
//	StackInit(&st3);
//
//	return 0;
//}

// C语言不允许同名函数
// CPP可以，但是要求构成函数重载
// 函数名相同，参数不同

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

// 返回值不同不能构成重载
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

// 构成函数重载
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
	// 调用存在歧义，不知道调用哪个
	//func(1, 0);

	func(1, 3, 2);


	return 0;
}
