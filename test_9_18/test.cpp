#define _CRT_SECURE_NO_WARNINGS 1

#include"vector.h"



void test_vector1()
{
	simulation::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	simulation::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{

		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	simulation::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);

	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin() + 3, 40);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin(), 100);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.end(), 1000);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.end() - 1);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	simulation::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	simulation::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (int e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector4()
{
	simulation::vector<string> v;
	v.push_back("666666666666666");
	v.push_back("666666666666666");
	v.push_back("666666666666666");
	v.push_back("666666666666666");
	v.push_back("666666666666666");

	for (auto s : v)
	{
		cout << s << " ";
	}
	cout << endl;

	simulation::vector<string> v1(v);
	for (auto s : v1)
	{
		cout << s << " ";
	}
	cout << endl;
	simulation::vector<int> v2;
	
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	for (auto s : v2)
	{
		cout << s << " ";
	}
	cout << endl;
	simulation::vector<int> v3;
	v3 = v2;
	for (auto s : v3)
	{
		cout << s << " ";
	}
	cout << endl;


	simulation::vector<int> v4(10,0);
	for (auto s : v4)
	{
		cout << s << " ";
	}
	cout << endl;

	simulation::vector<string> v5(10, "xxx");
	for (auto s : v5)
	{
		cout << s << " ";
	}
	cout << endl;
}


int main()
{
	test_vector4();
	return 0;
}