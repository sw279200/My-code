#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;//c++标准库
//定义一个名字为date的命名空间（函数变量）

//在命名空间date中嵌套定义命名空间A
namespace date
{
	int year = 2023;
	int month = 7;
	int day = 21;
	int a = 20;
	int b = 10;

	namespace A
	{
		int a = 10;
		int b = 20;
	}

	void fun();

}

void date::fun()
{
	cout << "这是命名空间date中的函数" << endl;
}

//定义一个名字为xiaobai的命名空间（函数变量）
namespace xiaobai
{
	int a = 100;
	int b = 200;

	int add(int x, int y)
	{
		return x + y;
	}
}




namespace xiaobai
{
	int c = 300;
}


//错误的：不可以局部定义命名空间
//void Test()
//{
//	namespace A
//	{
//		int a = 10;
//	}
//
//	namespace B
//	{
//		int a = 20;
//	}
//
//	cout << "A中的a = " << A::a << endl;
//	cout << " B中的 a = " << B::a << endl;
//}


namespace oldName
{
	int a = 200;
	void func()
	{
		cout << "hello namespace" << endl;
	}
}


using  namespace oldName;

int main()
{

	cout << "date中的 a = " << date::a << " date中的 b = " << date::b << endl;
	cout << "xiaobai中的 a = " << xiaobai::a << " xiaobai中的 b = " << xiaobai::b << endl;
	cout << "date中的A的a = " << date::A::a << "date中的A的b = " << date::A::b << endl;

	cout << "xiaobai中的 a = " << xiaobai::a << endl;
	cout << "xiaobai中的 b = " << xiaobai::b << endl;
	cout << "xiaobai中的 c = " << xiaobai::c << endl;
	cout << "a = " << a << endl;
	cout << "func的调用:\n"<< endl;
	func();
	namespace newName = oldName;
	cout <<"a = "<< newName::a << endl;
	func();	
	return 0;
}

#endif

#include <iostream>

using namespace std;

//全缺省
void Function(int x = 10,int y = 20,int z = 30)
{
	cout <<"x = "<< x << endl;
	cout << "y = " << y << endl;
	cout <<"z = " << z << endl;
}

////半缺省
//void Function(int x , int y = 20, int z = 30)
//{
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//	cout << "z = " << z << endl;
//}

// 1、参数类型不同
int Add(int x, int y)
{
	cout << "int Add(int x, int y)" << endl;
	return x + y;
}
double Add(double a, double b)
{
	cout << "double Add(double a, double b)" << endl;
	return a + b;
}


// 2、参数个数不同
void func()
{
	cout << "func()" << endl;
}
void func(int a)
{
	cout << "func(int a)" << endl;
}

// 3、参数类型顺序不同
void func(int a, char b)
{
	cout << "func(int a,char b)" << endl;
}
void func(char b, int a)
{
	cout << "func(char b, int a)" << endl;
}



#include <time.h>
struct A { int a[10000]; };
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	//// 分别计算两个函数运行结束后的时间
	//cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	//cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;

	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

int main()
{
	//没有传参时，使用参数的默认值
	//Function();
	//传参时，使用指定的实参
	//Function(100); 

	//Add(10, 20);
	//Add(10.1, 20.2);
	//func();
	//func(10);
	//func(10, 'a');
	//func('a', 10);
	TestRefAndValue();
	return 0;
}