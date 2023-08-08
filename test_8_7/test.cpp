#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

#include"string.h"

//int main()
//{
//	//bit::test_string9();
//
//	string s1("xxxxxx");
//	cout << s1.capacity() << endl;
//
//	string s2("hello world1111111111111111111111111111");
//	cout << s2.capacity() << endl;
//
//	// 小于16，字符串存到buff数组里面
//	// 大于等于16，存在_str指向的空间
//	
//	//_buff[16]
//	//_str
//	//_size
//	//_capacity
//
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//
//	return 0;
//}

int main()
{


	string s1("xxxxxxxxxxxxxxxxxxxxxxxxxxx");
	string s2(s1);
	cout << (void*)s1.c_str() << endl;
	cout << (void*)s2.c_str() << endl;

	return 0;
}