#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

void func()
{
	string s1("hello world,hello xiaobainnnnnnnnnnnnmmmmmmmmmmmmmm!");
	string s2(s1, 2, s1.size());
	cout << s2 << endl;

	string s3(s1, 2, 7);
	cout << s3 << endl;

	string s4(s1, 6, 5);
	cout << s4 << endl;

	string s5(s1, 6, 3);
	cout << s5 << endl;

	string s6(s1, 6);
	cout << s6 << endl;

	string s7(s1, 6, s1.size() - 6);
	cout << s7 << endl;

	string s8(10, 'a');
	cout << s8 << endl;

	string s9(++s8.begin(), --s8.end());
	cout << s9 << endl;


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

void test_string2()
{
	string s;
	s.reserve(100);

	size_t old = s.capacity();
	cout << "初始：" << s.capacity() << endl;
	for (size_t i = 0; i < 100; i++)
	{
		s.push_back('m');
		if (s.capacity() != old)
		{

			cout << "扩容：" << s.capacity() << endl;
			old = s.capacity();
		}
	}

	s.reserve(10);
	cout << s.capacity() << endl;
}

void test_string3()
{
	string s1;
	s1.resize(15, '*');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	s1.resize(20, '#');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	string s2;
	s2.resize(15, '&');
	cout << s2.size() << endl;
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
		cout << "没有找到" << endl;

	size_t m = s3.find('/', j + 3);

	if (m != string::npos)
		s5 = s3.substr(j + 3, m - (j + 3));
	else
		cout << "没有找到" << endl;

	s6 = s3.substr(m);

	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
}

int main()
{
	//func();
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	test_string5();
	return 0;
}
