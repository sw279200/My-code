#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>



//��5��ѡ�֣�ѡ��ABCDE��ʮ����ί��ÿ��ѡ�ֽ��д�֣�ȥ��һ����߷֣�ȥ��һ����ͷ֣�ȡƽ����
//ѡ����

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

public:
	string m_Name;
	int m_Score;

};

//��ѡ�ֽ��г�ʼ��
void CreatPerson(vector<Person>& v)
{
	string NameNeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name = name + NameNeed[i];
		int score = 0;

		//�������Ķ���ŵ�������
		Person p(name, score);

		v.push_back(p);
	}
}

//���

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί��ķ�������deque��
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int Score = rand() % 41 + 60;
			d.push_back(Score);
		}

		//����
		sort(d.begin(), d.end());

		//ȥ����߷�
		d.pop_back();
		//ȥ����ͷ�
		d.pop_front();

		int sum = 0;
		int avg = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		avg = sum / d.size();

		it->m_Score = avg;
	}
}

void ShowScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�������� " << it->m_Name << "ƽ���֣� " << it->m_Score << endl;
	}
}


int main()
{ 
	//���������
	srand((unsigned int)time(NULL));
	//����5��ѡ��
	vector<Person> v;
	CreatPerson(v);
	setScore(v);
	ShowScore(v);

	return 0;
}

