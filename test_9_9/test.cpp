#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<string>
using namespace std;

//string��ĳ��ýӿڲ���

void test_string()
{
	string s1("");//���ַ���
	cout << s1 << endl;
	string s2("hello world");//��C-string������string�����
	cout << s2 << endl;
	string s3(8, '*');  //string ������а���n���ַ�c
	cout << s3 << endl;

	string s4(s3);//�������캯��
	cout << s4 << endl;
}



void test_string1()
{
	string s1("hello world");

	cout << s1.length() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.clear();
	s1 += "libai";
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;


}

void test_stringReserve()
{
	string s;
	s.reserve(100);

	size_t old = s.capacity();
	cout << "��ʼ��" << s.capacity() << endl;
	for (size_t i = 0; i < 100; i++)
	{
		s.push_back('m');
		if (s.capacity() != old)
		{

			cout << "���ݣ�" << s.capacity() << endl;
			old = s.capacity();
		}
	}

	s.reserve(10);
	cout << s.capacity() << endl;
}

void test_stringResize()
{
	string s1;
	s1.resize(15, '*');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	s1.resize(20, '#');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	string s2;
	s2.resize(15, '&');
	cout << s2.size() << endl;
	cout << s2.length() << endl;
	cout << s2.capacity() << endl;
	cout << s2 << endl;

	s2[0]++;
	s2.at(0)++;
	cout << s2 << endl;
}

void test_string4()
{
	string s1("world");

	string s("hello");
	s.push_back('#');
	s.append(s1);
	cout << s << endl;

	cout << s1 << endl;
	s1.append(s);
	cout << s1 << endl;

	string ret1 = "hello bit";
	ret1 += s;
	string ret2 = ret1 + s1;
	cout << ret1 << endl;
	cout << ret2 << endl;

}

void test_string5()
{
	string s1("test.cpp.tar.zip");
	//size_t i = s1.find('.');
	size_t i = s1.rfind('.');
	string s2 = s1.substr(i);
	cout << s2 << endl;


	//string s3("https://legacy.cplusplus.com/reference/string/string/rfind/");
	string s3("https://cn.bing.com/search?pglt=41&q=baidu&cvid=b6332837d8f642d1befbdeeaae18733b&aqs=edge..69i57j0l8.1965j0j1&FORM=ANSPA1&PC=EDGEDBB");
	string s4;
	string s5;
	string s6;
	size_t j = s3.find(':');


	if (j != string::npos)
		s4 = s3.substr(0, j);
	else
		cout << "û���ҵ�" << endl;

	size_t m = s3.find('/', j + 3);

	if (m != string::npos)
		s5 = s3.substr(j + 3, m - (j + 3));
	else
		cout << "û���ҵ�" << endl;

	s6 = s3.substr(m);

	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
}

void test_stringClear()
{
	string s("hello world");
	cout << s << endl;
	s.clear();
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}


void test_stringFor()
{
	string s1("hello world");
	string s2 = "hello world";

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;

	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
}

int main()
{
	test_string5();
	//test_stringFor();
	//test_stringReserve();
	//test_stringResize();
	//test_stringClear();
	return 0;
}