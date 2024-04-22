#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

void test_set1()
{
	set<int> s,myset;
	s.insert(1);
	s.insert(3);
	s.insert(5);
	s.insert(5);
	s.insert(4);
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(4);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	/*set<std::set<int>::iterator, bool> ret;
	for (int i = 0; i < 10; i++) myset.insert(i * 10);
	ret = myset.insert(20);
*/

}

void test_set2()
{

}


void test_map1()
{
	map<string, string> dict;
	/*dict.insert(pair<string, string>("sort", "ÅÅĞò"));
	dict.insert(pair<string, string>("insert", "²åÈë"));
	dict.insert(pair<string, string>("erase", "É¾³ı"));
	dict.insert(pair<string, string>("key", "first"));
	dict.insert(pair<string, string>("value", "second"));
	dict.insert(pair<string, string>("center", "ÖĞĞÄ"));*/


	dict.insert(make_pair("sort", "ÅÅĞò"));
	dict.insert(make_pair("insert", "²åÈë"));
	dict.insert(make_pair("erase", "É¾³ı"));
	dict.insert(make_pair("key", "first"));
	dict.insert(make_pair("value", "second"));
	dict.insert(make_pair("center", "ÖĞĞÄ"));
	map<string, string>::iterator mit = dict.begin();
	while (mit != dict.end())
	{
		cout << (*mit).first << " : " << (*mit).second << endl;
		mit++;
	}
	cout << endl;

	for (auto& m : dict) cout << m.first << " " << m.second << endl;
	cout << endl;
}

int main()
{
	test_map1();
	//test_set2();
	return 0;
}