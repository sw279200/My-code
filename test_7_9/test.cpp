#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#if 0
//某种特殊的数列a1, a2, a3, ...的定义如下：a1 = 1, a2 = 2, ..., an = 2 * an − 1 + an - 2 (n > 2)。
//
//给出任意一个正整数k，求该数列的第k项模以32767的结果是多少？
int main()
{
	int a1 = 1;
	int a2 = 2;
	vector<int> v;
	v.push_back(a1);
	v.push_back(a2);
	for (int i = 2; i <= 1000000; i++)
	{
		v.push_back((v[i-1]*2+v[i-2])%32767);
	}

	int  n = 0;
	cin >> n;
	while (n--)
	{
		unsigned int x = 0;
		cin >> x;
		cout << v[x-1] << endl;
				
	}
	return 0;

}
#endif


//输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。

int main()
{
	int EngCount = 0;
	int blankCount = 0;
	int NumCount = 0;
	int otherCount = 0;
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			EngCount++;
		}
		else if (str[i] == ' ')
		{
			blankCount++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			NumCount++;
		}
		else
		{
			otherCount++;
		}
	}

	cout << EngCount << "\n" << blankCount << "\n" << NumCount << "\n" << otherCount << endl;
	return 0;
}