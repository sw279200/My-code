#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector容器——构造函数
void Test1()
{
	vector<int > v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printVector(v1);

	//通过区间给容器赋值
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);
	
	//通过n个 elem赋值
	vector<int> v3(10, 100);
	printVector(v3);

	//通过调用拷贝构造函数赋值
	vector<int > v4(v3);
	printVector(v4);


}

void Test2()
{
	vector<int > v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printVector(v1);

	//通过区间给容器赋值
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());
	printVector(v2);

	//通过n个 elem赋值
	vector<int> v3;
	v3.assign(10, 100);
	printVector(v3);

}

//vector容器的容量和大小
void Test3()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printVector(v1);

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为: " << v1.size() << endl;
	}

	//重置v1大小，多出来的空间默认填充为0
	/*v1.resize(15);
	printVector(v1);*/
	//重置v1的大小，多出来的空间填充为10
	v1.resize(15, 10);
	printVector(v1);

	//重置v1的大小，如果重置的空间比原来的小，则把原来多出的元素删除
	v1.resize(5);
	printVector(v1);
	

}

void Test4()
{
	vector<int > v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	printVector(v1);
	//第一个位置插入一个100
	v1.insert(v1.begin(), 100);
	printVector(v1);
	//在首元素位置插入2个666
	v1.insert(v1.begin(), 2, 666);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);

	//删除某个区间中的元素
	v1.erase(v1.begin(), v1.begin() + 3);
	printVector(v1);

	//清空容器中的元素
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
	

}

//vector容器数据的存取
void Test5()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	
	for (int i = 0; i < v1.size(); i++)
		cout << v1.at(i)<<" ";
	cout << endl;

	//访问v1里的第一个元素
	cout << v1.front() << endl;

	//访问v1里的最后一个元素
	cout << v1.back() << endl;
}

//vector容器，互换容器

void Test6()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为： " << v.size() << endl;

	v.resize(3);
	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为： " << v.size() << endl;

	//用匿名对象跟v进行容器互换
	vector<int>(v).swap(v);
	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为： " << v.size() << endl;
	
}


void Test7()
{
	vector<int> v;
	
	//利用reserve函数给v预留空间
	v.reserve(100000);

	int num = 0;
	int* pv = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (pv != &v[0])
		{
			pv = &v[0];
			num++;
		}
	}

	cout << "num = " << num << endl;
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	Test7();
	return 0;
}