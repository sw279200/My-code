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
	//mutable int m_A;//�����������ʹ���ڳ�������Ҳ�����޸�

	Person()
	{
		money = 200.00;
	}
private:
	double money;
};

void getmoney(Person* friends)
{
	cout << "���ڷ��ʺ����ѵ�money:" << friends->money << endl;
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
//��Ͷ��󡪡���Ԫ������Ԫ��
#include <iostream>
#include <string>
using namespace std;
class Building;

class GoodGay
{
public:
	GoodGay();//����������Ա����
	void visit();//�ιۺ���������Building�������
public:
	Building * building;
};

class Building
{
	friend class GoodGay;//GoodGay����Building��ĺ����ѣ����Է���Building���е�˽������
public:
	Building();
public:
	string sitroom;
private:
	string bedroom;

};

GoodGay::GoodGay()//����ʵ�ֳ�Ա����
{
	//�������������
	building = new Building;
}
void GoodGay::visit()
{
	cout << "�û��������ڷ��ʣ�" << building->sitroom << endl;
	cout << "�û��������ڷ��ʣ�" << building->bedroom << endl;
}

Building::Building()
{
	//һ��������͸���ֵ
	sitroom = "����";
	bedroom = "����";
}

void Test()
{
	GoodGay gg;//����һ��GoodGay���һ�����󣬵��ù��캯��
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

	//��Ա����ʵ�ֲ��� p<<cout ����������Ҫ��Ч��
	/*void operator<<(Person& p)
	{

	}*/

private:
	int p_A;
	int p_B;
};

//ȫ�ֺ���ʵ���������������
//ostream ����ֻ����һ��
ostream& operator<<(ostream& cout,Person &p)
{
	cout << "p_A=  " << p.p_A << " p_B = " << p.p_B;
	return cout;
}

void Test()
{
	Person p(10, 10);
	cout << p << " +hello bit" << endl;//��ʽ���

}
int main()
{
	Test();
	return 0;
}

#endif


#if 0

//�ݼ����������

#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
	//��Ա��������ǰ��--�����
	MyInteger& operator--()
	{
		--my_num;
		return *this;

	}

	//��Ա�������غ���--�����
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

//ȫ�ֺ����������������
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.my_num;
	return cout;

}


void Test1()
{
	MyInteger m_int(2);
	cout << "���ü����Ľ��: " << m_int-- << endl;
	cout << "����֮��: " << m_int << endl;
}

void Test2()
{
	MyInteger m_int(2);
	cout << "ǰ�ü������:" << --m_int << endl;
	cout << "����֮��: " << m_int << endl;
}

int main()
{

	Test1();
	Test2();
	return 0;
}
#endif


#if 0
//��ֵ���������

#include <iostream>
using namespace std;

class Person
{
public:

	Person& operator=(Person& p)
	{
		//���������ṩǳ����
		//my_num = p.my_num

		if (my_num != NULL)
		{
			delete my_num;
			my_num = NULL;
		}
		//�������
		my_num = new int(*p.my_num);

		//���ض�����
		return *this;
	}

	Person(int num)
	{
		my_num = new int(num);//�ڶ�������һ���ڴ�ռ�,���ڴ��ַ����my_num
	}

	~Person()//��������
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

	cout << "��ֵ��p1��ֵ�ǣ� " << *p1.my_num << endl;
	cout << "��ֵ��p2��ֵ�ǣ� " << *p2.my_num << endl;
	cout << "��ֵ��p3��ֵ�ǣ� " << *p3.my_num << endl;


}

int main()
{
	Test();
	return 0;
}


#endif 

#if 0
//��ϵ���������

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
		cout << "p1��p2����ȵ�" << endl;
	}
	else
	{
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}
	else
	{
		cout << "p1��p2����ȵ�" << endl;
	}
}

int main()
{
	Test();
	return 0;
}


#endif 

//�����������������
#if 1

#include <iostream>
using namespace std;

class MyPrint
{

public:
	void operator()(string test)//�º���
	{
		cout << test << endl;
	}

};


void Test()
{
	MyPrint myPrint;

	myPrint("hello world");

	//������������÷º���
	MyPrint()("hello world");
}

int main()
{
	Test();

	return 0;
}

#endif


