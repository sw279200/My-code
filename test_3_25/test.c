#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//小白月赛62B 剩下的数
void solve()
{
	long long l = 0;
	long long r = 0;
	int m = 0;
	scanf("%lld %lld", &l, &r);
	scanf("%d", &m);
	long long sum = ((l + r) * (r - l + 1)) / 2;
	int i = 0;
	int mod = 0;
	int x = 0;
	long long ans;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &x);
		if (sum % x == 0)
		{
			ans = 0;
		}
		else
		{
			ans = 1;

		}
		printf("%lld\n", ans);
	}
}
int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--)
	{
		solve();
	}
	return 0;
}