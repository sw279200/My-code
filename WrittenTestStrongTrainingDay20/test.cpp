#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


//字符串反转
string reserveStr(string& str)
{
	string s("");
	for (int i = str.size()-1;i>=0;i--)
	{
		s += str[i];
	}
	return s;
}


//最长公共子串
int maxLenSubStr(string& s1, string& s2)
{
	if (s1.size() > s2.size()) swap(s1, s2);
	int len1 = s1.size(), len2 = s2.size();

	int ret = 0;
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			ret = max(ret, dp[i][j]);
		}
	}
	return ret;
}


int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << maxLenSubStr(s1, s2)<< endl;
	/*string str;
	cin >> str;
	cout << reserveStr(str) << endl;*/
	return 0;
}