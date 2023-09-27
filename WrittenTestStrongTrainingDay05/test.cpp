#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//�ж��Ƿ��ǻ��Ĵ�
bool IsPalindromicString(const string& str)
{
	size_t start = 0,end = str.size()-1;
	bool flag = true; 

	while (start < end)
	{
		if (str[start] != str[end])
		{
			flag = false;
			break;
		}
		else
		{
			start++;
			end--;
		}
	}
	
	return flag;	
}

//ͳ�ƻ���
void solve()
{
	string strA;
	string strB;
	cin >> strA >> strB;
	size_t i = 0;
	int count = 0;
	string strC;
	while (i <= strA.size())
	{
		strC = strA;
		
		strC.insert(i, strB);
		if (IsPalindromicString(strC))
		{
			count++;
		}
		i++;
	}

	cout << count << endl;
}


//��������
void SubIntervalMaxSum()
{
	int n = 0;
	cin >> n;
	vector<int> v(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int sum = v[0], MaxSum = v[0];
	int start = 0, end = 0;//start��end����������ǰ�͵�������
	for (int i = 1; i < n; i++)
	{
		if (sum + v[i] < v[i])
		{
			sum = v[i];
			start = i;
			end = i;
			
		}
		else
		{
			sum += v[i];
			end++;
		}

		if (sum > MaxSum)
		{
			MaxSum = sum;
		}
	}

	cout << MaxSum << endl;
}

int main()
{
	SubIntervalMaxSum();
	//solve();
	return 0;
}