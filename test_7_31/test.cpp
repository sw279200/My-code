#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;
//static关键字的使用
class Person
{

public:
	
	Person(string name = "小白",int age = 22)

	{
		mName = name;
		mAge = age;
		m++;
		n++;
	}

	Person(const Person& p)		
	{
		mName = p.mName;
		mAge = p.mAge;
		m++;
		n++;
	}

	~Person()
	{
		m--;
	}

	//静态成员变量的特点：没有this指针
	static int GetM()
	{
		//静态成员函数不能访问非静态成员变量,因为没有this指针
		//mAge = 2;
		return m;
	}

	static void Print()
	{
		cout << "m = " << m << " n = " << n << endl;
	}

private:
	//静态成员变量属于所有Person对象，属于整个类

	int mAge;
	string mName;
	//声明
	//正在使用的对象
	static int m;
	//累计创建了多少个对象
	static int n;
};


int Person::m = 0;
int Person::n = 0;

Person func(Person p)
{
	return p;
}

int main()
{
	Person p1;
	Person p2("小白", 22);
	Person::Print();

	func(p1);

	p1.Print();


	/*cout << "m = " << Person::m << " n = " << Person::n << endl;

	cout << "m = " <<p1.m << " n = " << p1.n << endl;

	Person* p3 = nullptr;
	cout << "m = " << p3->m << " n = " << p3->n << endl;


	func(p2);
	cout << "m = " << p2.m << " n = " << p2.n << endl;*/
	return 0;
}

#endif


#include <iostream>
using namespace std;

//内部类
//B类受A类域和访问限定符的限制,其实他们是两个独立的类
class A
{
public:
	//内部类天生是外部类的友元
	class B
	{

	public:
		void funcB()
		{
			A a;
			a._a = 0;
		}
	private:
		int _b;
	};

	void func()
	{
		B bb;
	}
	
private:
	int _a;
};

int main()
{
	cout << sizeof(A) << endl;
	return 0;
}

