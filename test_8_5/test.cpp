#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

void Test1()
{
	//调用无参构造函数
	string s1;//空字符串
	cout << "s1 = " << s1 << endl;


	const char* str = "hello cpp, good night!";
	string s2(str);//把c_string 转换成了string
	cout << "s2 = " << s2 << endl;

	//调用拷贝构造函数
	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');//s4初始化为10个'a'组成的字符串
	cout << "s4 = " << s4 << endl;

	string s5;
	s5.assign("hello c++");
	cout << "s5= " << s5 << endl;

	string s6;
	s6.assign("hello c++", 5);
	cout << "s6 = " << s6 << endl;

	string s7;
	s7.assign(5, 'w');
	cout << "s7 = " << s7 << endl;

	//string字符串的追加
	string s8 = "我";
	s8 += "爱编程";
	cout << s8 << endl;

	s8 += ':';
	cout << s8 << endl;

	string s9 = "c++,Java,Python";
	s8 += s9;
	cout << s8 << endl;

	string s0 = "I ";
	s0.append("love ");
	cout << s0 << endl;

	s0.append("playing game.", 4);
	cout << "s0 = " << s0 << endl;

	s0.append(s6, 0, 5);
	cout << "s0 = " << s0 << endl;
}

void Test2()
{
	string str1;
	str1 = "abcdefghde";
	int pos = str1.find("de");
	if (pos == -1)
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;

	//字符串的替换
	str1.replace(1, 3, "wwww");
	cout << "str1 = " << str1 << endl;


	//字符串比较
	string str2;
	str2 = "awwwwefghde";

	if (str1.compare(str2) == 0)
	{
		cout << "str1等于str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1大于str2" << endl;
	}
	else
	{
		cout << "str1小于str2" << endl;
	}


	//字符串的存取
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << " ";
	}

	cout << endl;
	//字符串的插入删除
	str1.insert(1, "666");
	cout << "str1 = " << str1 << endl;
	str1.erase(1, 3);
	cout << "str1 = " << str1 << endl;


	//获取子串
	string Substr = str1.substr(1, 5);
	cout << "Substr = " << Substr << endl;

	string email = "sunwenchao@qq.com";
	pos = email.find("@");
	string sbs = email.substr(0, pos);
	cout << "sbs = " << sbs << endl;
}

int main()
{
	Test2();
	return 0;
}