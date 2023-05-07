#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//文本文件操作 -- 写文件
#include <iostream>
using namespace std;

//1.包含头文件
#include <fstream>

void Test()
{
	//2.创建文件流对象
	ofstream ofs;

	//3.打开文件: 文件名+打开方式
	ofs.open("test.txt", ios::out);

	//4.写文件
	ofs << "姓名：徐静杭" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：22" << endl;

	//5.关闭文件
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
//1.包含头文件
#include <fstream>

void Test()
{
	//2.创建流对象
	ifstream ifs;

	//3.打开文件并判断文件是否打开成功
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读文件 四种操作

	////第一种
	//char buf[1024];
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	////第二种
	//char buf[1024];
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}

	////第四种
	//char s;
	//while ((s = ifs.get()) != EOF)
	//{
	//	cout << s;
	//}

	//关闭文件
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
//二进制文件形式写文件
//1.包含头文件
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
	//2.创建流对象(同时以这种方式打开文件)
	ofstream ofs("person.txt", ios::out | ios::binary);
	

	//3.打开文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = { "李白",23 };

	//4.写文件
	ofs.write((const char*)&p,sizeof(Person));

	//5.关闭文件
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
//二进制文件形式 读文件
//1.包含头文件
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
	//2.创建流对象
	ifstream ifs;


	//3.打开文件
	ifs.open("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	Person p;

	//4.写文件
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名:" << p.name << " 年龄：" << p.age << endl;

	//5.关闭文件
	ifs.close();

}

int main()
{
	Test();
	return 0;
}

#endif