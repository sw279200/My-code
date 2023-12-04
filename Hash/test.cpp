#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;
#include"HashTable.h"


//
//int main()
//{
//	unordered_set<int>s;
//	s.insert(2);
//	s.insert(5);
//	s.insert(1);
//	s.insert(6);
//	s.insert(4);
//	unordered_set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	unordered_map<string, string>hash;
//	hash["left"] = "×ó±ß";
//	hash["right"] = "ÓÒ±ß";
//	hash["sort"] = "ÅÅÐò";
//
//	for (auto& kv : hash)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
// 
//	return 0;
//}
#include"MyUnorderedMap.h"
#include"MyUnorderedSet.h"
#include"bitset.h"
#include<bitset>
//int main()
//{
//	//hash_bucket::TestHT1();
//	//open_address::TestHT2();
//	//bit::test_set();
//	//bit::test_map();
//
//	std::bitset<100> bs;
//	bs.set(40);
//	bs.set(39);
//
//	cout << bs.test(38) << endl;
//	cout << bs.test(39) << endl;
//	cout << bs.test(40) << endl;
//	cout << bs.test(41) << endl;
//	cout << bs.test(42) << endl;
//	cout << endl;
//	bs.reset(40);
//	cout << bs.to_string() << endl;
//
//	cout << bs.test(38) << endl;
//	cout << bs.test(39) << endl;
//	cout << bs.test(40) << endl;
//	cout << bs.test(41) << endl;
//	cout << bs.test(42) << endl;
//
//	//bit::bitset<0xffffffff> bigbs1;
//
//	return 0;
//}

//int main()
//{
//	int a[] = { 1 ,4,1,4,23,5,9,44,88,77,44,88,99,78,7};
//	bit::twobitset<100>bs;
//	for (auto e : a)
//	{
//		bs.set(e);
//	}
//	bs.PrintOnce();
//	return 0;
//}

#include"BloomFilter.h"

int main()
{
	//TestBF1();
	TestBF2();
	return 0;
}