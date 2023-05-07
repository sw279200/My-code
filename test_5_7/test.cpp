#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//�ı��ļ����� -- д�ļ�
#include <iostream>
using namespace std;

//1.����ͷ�ļ�
#include <fstream>

void Test()
{
	//2.�����ļ�������
	ofstream ofs;

	//3.���ļ�: �ļ���+�򿪷�ʽ
	ofs.open("test.txt", ios::out);

	//4.д�ļ�
	ofs << "�������쾲��" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺22" << endl;

	//5.�ر��ļ�
	ofs.close();
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
#include <string>
//1.����ͷ�ļ�
#include <fstream>

void Test()
{
	//2.����������
	ifstream ifs;

	//3.���ļ����ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//4.���ļ� ���ֲ���

	////��һ��
	//char buf[1024];
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	////�ڶ���
	//char buf[1024];
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//������
	string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}

	////������
	//char s;
	//while ((s = ifs.get()) != EOF)
	//{
	//	cout << s;
	//}

	//�ر��ļ�
	ifs.close();

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
//�������ļ���ʽд�ļ�
//1.����ͷ�ļ�
#include <fstream>
#include<string>
class Person
{
public:
	char name[64];
	int age;
};

void Test()
{
	//2.����������(ͬʱ�����ַ�ʽ���ļ�)
	ofstream ofs("person.txt", ios::out | ios::binary);
	

	//3.���ļ�
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = { "���",23 };

	//4.д�ļ�
	ofs.write((const char*)&p,sizeof(Person));

	//5.�ر��ļ�
	ofs.close();

}

int main()
{
	Test();
	return 0;
}

#endif

#if 1
#include <iostream>
using namespace std;
//�������ļ���ʽ ���ļ�
//1.����ͷ�ļ�
#include <fstream>
#include <string>
class Person
{
public:
	char name[64];
	int age;
};

void Test()
{
	//2.����������
	ifstream ifs;


	//3.���ļ�
	ifs.open("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	Person p;

	//4.д�ļ�
	ifs.read((char*)&p, sizeof(Person));
	cout << "����:" << p.name << " ���䣺" << p.age << endl;

	//5.�ر��ļ�
	ifs.close();

}

int main()
{
	Test();
	return 0;
}

#endif