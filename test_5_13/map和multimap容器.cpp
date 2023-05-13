#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

#include <map>

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key :" << it->first << " value :" << it->second << endl;
	}
	cout << endl;
}

//map��������͸�ֵ
void Test1()
{
	//Ĭ�Ϲ���
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	cout << "-------------------" << endl;
	//��������
	map<int, int>m1(m);
	printMap(m1);
	cout << "-------------------" << endl;

	//�ȺŸ�ֵ
	map<int, int>m2;
	m2 = m1;
	printMap(m2);
	
}

//��С�ͽ���
void Test2()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	if (m.empty())
	{
		cout << "mΪ��" << endl;
	}
	else
	{
		cout << "m��Ϊ��" << endl;
		cout << "m�Ĵ�СΪ��" << m.size() << endl;
	}

	map<int, int>m0;
	m0.insert(pair<int, int>(5, 100));
	m0.insert(pair<int, int>(6, 200));
	m0.insert(pair<int, int>(7, 300));
	m0.insert(pair<int, int>(8, 400));

	//����ǰ
	cout << "����ǰ��" << endl;
	printMap(m);
	printMap(m0);

	//������
	cout << "������" << endl;
	m.swap(m0);
	printMap(m);
	printMap(m0);

}

//map���������ɾ��
void Test3()
{
	map<int, int>m;
	//����
	//��һ�ֲ��뷽ʽ
	m.insert(pair<int, int>(1, 10));

	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair(2, 20));

	//�����ֲ��뷽ʽ
	m.insert(map<int, int>::value_type(3, 30));

	//�����ֲ��뷽ʽ
	m[4] = 40; //������ʹ��[]�ķ�ʽ�����в��룬[]�ʺ�����ͨ��key���ҳ���Ӧ��value

	printMap(m);

	//ɾ��
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//���
	//m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}


//map�����Ĳ��Һ�ͳ��
void Test4()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	map<int, int>::iterator pos = m.find(4);

	if (pos != m.end())
	{
		cout << "�ҵ��ˣ�key = " << pos->first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ���Ԫ��" << endl;
	}


	//ͳ�ƣ�map����������ظ�keyԪ�أ�countͳ�ƶ��ԣ����ҪôΪ0��ҪôΪ1
	//multimap��countͳ�ƿ��ܴ���1
	int num = m.count(3);
	cout << "num = " << num << endl;
}

class MyCmp
{
public:
	bool operator()(int v1, int v2) const
	{
		//����
		return v1 > v2;
	}
};

void Test5()
{
	
	map<int, int,MyCmp>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	for (map<int, int, MyCmp>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	return 0;
}

#endif