#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;//c++��׼��
//����һ������Ϊdate�������ռ䣨����������

//�������ռ�date��Ƕ�׶��������ռ�A
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
	cout << "���������ռ�date�еĺ���" << endl;
}

//����һ������Ϊxiaobai�������ռ䣨����������
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


//����ģ������Ծֲ����������ռ�
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
//	cout << "A�е�a = " << A::a << endl;
//	cout << " B�е� a = " << B::a << endl;
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

	cout << "date�е� a = " << date::a << " date�е� b = " << date::b << endl;
	cout << "xiaobai�е� a = " << xiaobai::a << " xiaobai�е� b = " << xiaobai::b << endl;
	cout << "date�е�A��a = " << date::A::a << "date�е�A��b = " << date::A::b << endl;

	cout << "xiaobai�е� a = " << xiaobai::a << endl;
	cout << "xiaobai�е� b = " << xiaobai::b << endl;
	cout << "xiaobai�е� c = " << xiaobai::c << endl;
	cout << "a = " << a << endl;
	cout << "func�ĵ���:\n"<< endl;
	func();
	namespace newName = oldName;
	cout <<"a = "<< newName::a << endl;
	func();	
	return 0;
}

#endif

#include <iostream>

using namespace std;

//ȫȱʡ
void Function(int x = 10,int y = 20,int z = 30)
{
	cout <<"x = "<< x << endl;
	cout << "y = " << y << endl;
	cout <<"z = " << z << endl;
}

////��ȱʡ
//void Function(int x , int y = 20, int z = 30)
//{
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//	cout << "z = " << z << endl;
//}

// 1���������Ͳ�ͬ
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


// 2������������ͬ
void func()
{
	cout << "func()" << endl;
}
void func(int a)
{
	cout << "func(int a)" << endl;
}

// 3����������˳��ͬ
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
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	//// �ֱ���������������н������ʱ��
	//cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	//cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;

	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

int main()
{
	//û�д���ʱ��ʹ�ò�����Ĭ��ֵ
	//Function();
	//����ʱ��ʹ��ָ����ʵ��
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