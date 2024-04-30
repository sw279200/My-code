#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int SIZE = 32;

//乒乓球筐
void solve()
{
	string first, second;
	cin >> first >> second;
	vector<int> v1(SIZE),v2(SIZE);
	bool flag = false;
	for (int i = 0; i < first.size(); i++) v1[first[i] - 'A']++;
	for (int i = 0; i < second.size(); i++) v2[second[i] - 'A']++;
	for (int i = 0; i < SIZE; i++)
	{
		if (v1[i] < v2[i])
		{
			flag = true;
			break;
		}
	}

	if (flag)cout << "No" << endl;
	else cout << "Yes" << endl;


}


//组队竞赛
long long maximumLevelSum()
{
	int n = 0;
	cin >> n;
	vector<int> v(3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(),less<int>());
	long long sum = 0;
	for (int i = 3*n-2; i >= n; i-=2)
	{
		sum += v[i];
	}
	return sum;
}

//删除相邻数字的最大分数
void getGrade()
{
	unordered_map<int, int> hash;
	vector<vector<int>>dp(100010, vector<int>(2));
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		hash[x] = hash[x] + 1;
	}
	int maxSum = 0;
	for (int i = 1; i <= 100000; i++)
	{
		dp[i][1] = dp[i - 1][0] + i * hash[i];
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		maxSum = max(dp[i][0], dp[i][1]);
	}
	cout << maxSum << endl;

}

int main() {
	//solve();
	//cout<< maximumLevelSum()<<endl;
	getGrade();
	return 0;
}