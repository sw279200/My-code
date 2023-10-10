#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

////求最小公倍数
//void solve()
//{
//	int a = 0, b = 0, c = 0;
//	cin >> a >> b;
//	long long ans = 0;
//	c = a > b ? a : b;
//	for (int i = c; i <= a*b; i++)
//	{
//		if (i % a == 0 && i % b == 0)
//		{
//			ans =i;
//			break;
//		}
//	}
//	cout << ans << endl;
//}


//两种排序方式
void TwoSort()
{
	int n = 0;
	cin >> n;
	bool flag1 = true, flag2 = true;
	string str;
	cin >> str;
	for (int i = 1; i < n; i++)
	{
		string s;
		cin >> s;
		if (s < str) flag1 = false;
		if (s.size() < str.size()) flag2 = false;
	}

	if (flag1 && flag2) cout << "both" << endl;
	else if (flag1 && !flag2) cout << "lexicographically" << endl;
	else if (!flag1 && flag2) cout << "lengths" << endl;
	else if (!flag1 && !flag2) cout << "none" << endl;

}

int main()
{
	TwoSort();
	/*solve();*/
	return 0;
}
