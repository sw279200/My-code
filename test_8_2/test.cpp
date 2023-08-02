#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void test_string1()
{
	string s1;
	string s2("hello");

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;

	cin >> s2;
	cout << s2 << endl;

	string ret1 = s1 + s2;
	cout << ret1 << endl;
	string ret2 = s1+"ÎÒÀ´ÁË";
	cout << ret2 << endl;

}

void test_string2()
{
	string s1("hello world");
	string s2 = "hello world";
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void func(const string& s)
{
	string::const_iterator cit = s.begin();
	while (cit != s.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;
}

void test_string3()
{
	string s1("hello world");
	string s2 = "hello world";
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
	//test_string1();
	//test_string2();
	test_string3();
	return 0;
}