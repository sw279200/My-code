#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include <string>
using namespace std;

class Person
{
	friend void getmoney(Person* friends);
public:

	//void showPerson() const
	//{
	//	this->m_A = 100;
	//}
	//mutable int m_A;//特殊变量，即使是在常函数中也可以修改

	Person()
	{
		money = 200.00;
	}
private:
	double money;
};

void getmoney(Person* friends)
{
	cout << "正在访问好朋友的money:" << friends->money << endl;
}

void Test1()
{
	Person p;
	getmoney(&p);
}
int main()
{
	Test1();
	return 0;
}

#endif


#if 0
//类和对象——友元——友元类
#include <iostream>
#include <string>
using namespace std;
class Building;

class GoodGay
{
public:
	GoodGay();//类内声明成员函数
	void visit();//参观函数，访问Building类的属性
public:
	Building * building;
};

class Building
{
	friend class GoodGay;//GoodGay类是Building类的好朋友，可以访问Building类中的私有内容
public:
	Building();
public:
	string sitroom;
private:
	string bedroom;

};

GoodGay::GoodGay()//类外实现成员函数
{
	//创建建筑物对象
	building = new Building;
}
void GoodGay::visit()
{
	cout << "好基友类正在访问：" << building->sitroom << endl;
	cout << "好基友类正在访问：" << building->bedroom << endl;
}

Building::Building()
{
	//一创建对象就赋初值
	sitroom = "客厅";
	bedroom = "卧室";
}

void Test()
{
	GoodGay gg;//创建一个GoodGay类的一个对象，调用构造函数
	gg.visit();
}
int main()
{
	Test();
	return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:

	Person(int A,int B)
	{
		p_A = A;
		p_B = B;
	}

	//成员函数实现不了 p<<cout 不是我们想要的效果
	/*void operator<<(Person& p)
	{

	}*/

private:
	int p_A;
	int p_B;
};

//全局函数实现左移运算符重载
//ostream 对象只能有一个
ostream& operator<<(ostream& cout,Person &p)
{
	cout << "p_A=  " << p.p_A << " p_B = " << p.p_B;
	return cout;
}

void Test()
{
	Person p(10, 10);
	cout << p << " +hello bit" << endl;//链式编程

}
int main()
{
	Test();
	return 0;
}

#endif


#if 0

//递减运算符重载

#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
	//成员函数重载前置--运算符
	MyInteger& operator--()
	{
		--my_num;
		return *this;

	}

	//成员函数重载后置--运算符
	MyInteger operator--(int)
	{
		MyInteger temp = *this;
		my_num--;
		return temp;
	}

	MyInteger(int num)
	{
		my_num = num;
	}

private:
	int my_num;

};

//全局函数重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.my_num;
	return cout;

}


void Test1()
{
	MyInteger m_int(2);
	cout << "后置减减的结果: " << m_int-- << endl;
	cout << "减完之后: " << m_int << endl;
}

void Test2()
{
	MyInteger m_int(2);
	cout << "前置减减结果:" << --m_int << endl;
	cout << "减完之后: " << m_int << endl;
}

int main()
{

	Test1();
	Test2();
	return 0;
}
#endif


#if 0
//赋值运算符重载

#include <iostream>
using namespace std;

class Person
{
public:

	Person& operator=(Person& p)
	{
		//编译器是提供浅拷贝
		//my_num = p.my_num

		if (my_num != NULL)
		{
			delete my_num;
			my_num = NULL;
		}
		//深拷贝操作
		my_num = new int(*p.my_num);

		//返回对象本身
		return *this;
	}

	Person(int num)
	{
		my_num = new int(num);//在堆中申请一块内存空间,把内存地址给到my_num
	}

	~Person()//析构函数
	{
		if (my_num != NULL)
		{
			delete my_num;
			my_num = NULL;
		}

	}

public:
	int* my_num;

};

void Test()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p3 = p2 = p1;

	cout << "赋值后p1的值是： " << *p1.my_num << endl;
	cout << "赋值后p2的值是： " << *p2.my_num << endl;
	cout << "赋值后p3的值是： " << *p3.my_num << endl;


}

int main()
{
	Test();
	return 0;
}


#endif 

#if 0
//关系运算符重载

#include <iostream>
using namespace std;

class Person
{
public:

	bool operator==(Person& p)
	{
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person& p)
	{
		if (this->name == p.name && this->age == p.age)
		{
			return false;
		}
		return true;
	}
	
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}

private:
	string name;
	int age;

};

void Test()
{
	Person p1("gaofeng",20);
	Person p2("gaofeng",20);
	
	if (p1 == p2)
	{
		cout << "p1和p2是相等的" << endl;
	}
	else
	{
		cout << "p1和p2是不相等的" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1和p2是不相等的" << endl;
	}
	else
	{
		cout << "p1和p2是相等的" << endl;
	}
}

int main()
{
	Test();
	return 0;
}


#endif 

//函数调用运算符重载
#if 1

#include <iostream>
using namespace std;

class MyPrint
{

public:
	void operator()(string test)//仿函数
	{
		cout << test << endl;
	}

};


void Test()
{
	MyPrint myPrint;

	myPrint("hello world");

	//用匿名对象调用仿函数
	MyPrint()("hello world");
}

int main()
{
	Test();

	return 0;
}

#endif


