#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;


//小苯的九宫格
void solve()
{
	char arr[10];
	for (int i = 1; i < 10; i++)
	{
		cin >> arr[i];
	}
	string s,str;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		str += arr[s[i] - '0'];
	}
	cout << str << endl;
	
}

//小苯的好数组
void solution()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	bool flag = true;
	for (int i = 0; i < n-1; i++)
	{
		if (v[i] > v[i + 1]) flag = false;
	}
	if (n > 1 && v[n - 1] < v[n - 2]) flag = false;
	if (!flag)cout << n << endl;
	else cout << 0 << endl;
}


//小苯的数字合并
void getRange()
{
	int n = 0;
	cin >> n;
	vector<long long> v(n), arr;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		arr.push_back(sum - v[i]);
	}


	long long maxRange = -1e9;
	for (int i = 0; i < n; i++)
	{
		long long leftSum = arr[i], rightSum = sum - leftSum - v[i];
		long long x = rightSum > leftSum ? rightSum : leftSum;
		maxRange = max(abs(x - v[i]), maxRange);
	}
	cout << maxRange << endl;

}

int main()
{
	solve();
	return 0;
}