#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int TotalNumberOfRabbits(int n)
{
	if (n < 3) return 1;
	else return TotalNumberOfRabbits(n - 1) + TotalNumberOfRabbits(n - 2);
}

//ͳ��ÿ�������ӵ�����
void solve()
{
	int n = 0;
	cin >> n;
	cout << TotalNumberOfRabbits(n) << endl;
}

int main()
{
	solve();
	return 0;
}
#endif

//��̬�滮��˼·���ص��ж�*���ֵ�λ��
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int isMatch(const string& checkStr, const string& srcStr)//�ж��Ƿ�ƥ��
{
	int m = checkStr.length();
	int n = srcStr.length();
	vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));//��ʼ��[m+1][n+1]�ռ�
	dp[0][0] = 1;//�߽����������ǵ�һ���ַ���*�����
	for (int i = 1; i <= m; ++i)
		dp[i][0] = dp[i - 1][0] && (checkStr[i - 1] == '*');//�߽�����
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			char ch1 = checkStr[i - 1];
			char ch2 = srcStr[j - 1];
			if (ch1 == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] && (ch1 == ch2 || ch1 == '?');
		}
	return dp[m][n];
}
int main()
{
	string checkStr, srcStr;
	while (cin >> checkStr >> srcStr)
	{
		if (isMatch(checkStr, srcStr))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}