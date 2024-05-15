#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int vec[1000010] = { 0 };

//小红的ABC
bool isPalindromicString(const string& s)
{
	for (int left = 0, right = s.size() - 1; left < right; left++, right--)
	{
		if (s[left] != s[right]) return false;
	}
	return true;
}

int MinLengthPalindromicString(const string& str)
{
	int n = str.size(),minLen = INT_MAX;
	vector<vector<int>> dp(n, vector<int>(n,n));
	bool flag = false;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (isPalindromicString(str.substr(i, j - i + 1)))
			{
				flag = true;
				minLen = min(minLen, j - i + 1);
				continue;
			}
		}
	}
	if (!flag)return -1;
	else return minLen;
}

//不相邻取数
int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<vector<long long>> dp(n,vector<long long>(2));
	// init
	dp[0][0] = 0;
	dp[0][1] = a[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + a[i];
	}

	return max(dp[n - 1][0], dp[n - 1][1]);
}



//空调遥控
int TemperatureControl()
{
	int n, p,maxTemperature=-0x3f3f3f3f,minTemperature= 0x3f3f3f3f,MaxCount = 0;
	cin >> n >> p;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		maxTemperature =  max(maxTemperature, v[i]);
		minTemperature = min(minTemperature, v[i]);
	}

	if (maxTemperature - minTemperature <= 2 * p) return n;

	for (int i = 0; i < n; i++)
	{
		vec[v[i]]++;
	}

	for (int K = minTemperature + p; K <= maxTemperature - p; K++)
	{
		int count = 0;
		for (int i = K - p; i <= K + p; i++)count += vec[i];
		MaxCount = max(count, MaxCount);
	}
	return MaxCount;
}

int main()
{
	/*string str;
	getline(cin, str);
	cout << MinLengthPalindromicString(str) << endl;*/

	cout << TemperatureControl() << endl;
	return 0;
}