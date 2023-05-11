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

//vector�����������캯��
void Test1()
{
	vector<int > v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printVector(v1);

	//ͨ�������������ֵ
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);
	
	//ͨ��n�� elem��ֵ
	vector<int> v3(10, 100);
	printVector(v3);

	//ͨ�����ÿ������캯����ֵ
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

	//ͨ�������������ֵ
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());
	printVector(v2);

	//ͨ��n�� elem��ֵ
	vector<int> v3;
	v3.assign(10, 100);
	printVector(v3);

}

//vector�����������ʹ�С
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
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ: " << v1.size() << endl;
	}

	//����v1��С��������Ŀռ�Ĭ�����Ϊ0
	/*v1.resize(15);
	printVector(v1);*/
	//����v1�Ĵ�С��������Ŀռ����Ϊ10
	v1.resize(15, 10);
	printVector(v1);

	//����v1�Ĵ�С��������õĿռ��ԭ����С�����ԭ�������Ԫ��ɾ��
	v1.resize(5);
	printVector(v1);
	

}

void Test4()
{
	vector<int > v1;
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	printVector(v1);
	//��һ��λ�ò���һ��100
	v1.insert(v1.begin(), 100);
	printVector(v1);
	//����Ԫ��λ�ò���2��666
	v1.insert(v1.begin(), 2, 666);
	printVector(v1);
	//βɾ
	v1.pop_back();
	printVector(v1);

	//ɾ��ĳ�������е�Ԫ��
	v1.erase(v1.begin(), v1.begin() + 3);
	printVector(v1);

	//��������е�Ԫ��
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
	

}

//vector�������ݵĴ�ȡ
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

	//����v1��ĵ�һ��Ԫ��
	cout << v1.front() << endl;

	//����v1������һ��Ԫ��
	cout << v1.back() << endl;
}

//vector��������������

void Test6()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "v������Ϊ�� " << v.capacity() << endl;
	cout << "v�Ĵ�СΪ�� " << v.size() << endl;

	v.resize(3);
	cout << "v������Ϊ�� " << v.capacity() << endl;
	cout << "v�Ĵ�СΪ�� " << v.size() << endl;

	//�����������v������������
	vector<int>(v).swap(v);
	cout << "v������Ϊ�� " << v.capacity() << endl;
	cout << "v�Ĵ�СΪ�� " << v.size() << endl;
	
}


void Test7()
{
	vector<int> v;
	
	//����reserve������vԤ���ռ�
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