#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;
//static�ؼ��ֵ�ʹ��
class Person
{

public:
	
	Person(string name = "С��",int age = 22)

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

	//��̬��Ա�������ص㣺û��thisָ��
	static int GetM()
	{
		//��̬��Ա�������ܷ��ʷǾ�̬��Ա����,��Ϊû��thisָ��
		//mAge = 2;
		return m;
	}

	static void Print()
	{
		cout << "m = " << m << " n = " << n << endl;
	}

private:
	//��̬��Ա������������Person��������������

	int mAge;
	string mName;
	//����
	//����ʹ�õĶ���
	static int m;
	//�ۼƴ����˶��ٸ�����
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
	Person p2("С��", 22);
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

//�ڲ���
//B����A����ͷ����޶���������,��ʵ������������������
class A
{
public:
	//�ڲ����������ⲿ�����Ԫ
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

