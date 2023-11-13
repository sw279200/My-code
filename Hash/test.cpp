#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;


int main()
{
	unordered_set<int>s;
	s.insert(2);
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(4);
	unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	unordered_map<string, string>hash;
	hash["left"] = "×ó±ß";
	hash["right"] = "ÓÒ±ß";
	hash["sort"] = "ÅÅÐò";

	for (auto& kv : hash)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
 
	return 0;
}