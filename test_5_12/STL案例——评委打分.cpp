#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>



//有5名选手：选手ABCDE，十个评委对每个选手进行打分，去掉一个最高分，去掉一个最低分，取平均分
//选手类

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

//对选手进行初始化
void CreatPerson(vector<Person>& v)
{
	string NameNeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name = name + NameNeed[i];
		int score = 0;

		//将创建的对象放到容器中
		Person p(name, score);

		v.push_back(p);
	}
}

//打分

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委打的分数存在deque中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int Score = rand() % 41 + 60;
			d.push_back(Score);
		}

		//排序
		sort(d.begin(), d.end());

		//去掉最高分
		d.pop_back();
		//去掉最低分
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
		cout << "选手姓名： " << it->m_Name << "平均分： " << it->m_Score << endl;
	}
}


int main()
{ 
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建5名选手
	vector<Person> v;
	CreatPerson(v);
	setScore(v);
	ShowScore(v);

	return 0;
}

