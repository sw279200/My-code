#define _CRT_SECURE_NO_WARNINGS 1

////牛客小白月赛60 A小竹与妈妈
//#include<stdio.h>
//
//int main()
//{
//	int x = 0;
//	int a = 0;
//	int b = 0;
//	scanf("%d %d %d", &a, &b, &x);
//	printf("%d\n", (x - b) / a);
//	return 0;
//}


////牛客小白月赛60 B走丢的小竹
//#include<stdio.h>
//#define N 100005
//typedef long long ll;
//ll arr[N-1] = { 0 };
//ll flag[N] = { 0 };
//int main()
//{
//	
//	ll n, m, x, q;
//	scanf("%lld %lld %lld", &n, &m, &q);
//	int i = 1;
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%lld", &arr[i]);
//		flag[arr[i]]++;
//	}
//	for (i = 1; i <= q; i++)
//	{
//		ll ans = 0;
//		scanf("%lld", &x);
//		ans = n - flag[x];
//		printf("%lld\n", ans);
//	}
//	return 0;
//}

//牛客小白月赛60 C小竹关禁闭
#include<stdio.h>
int Max(int x, int y)
{
	return (x > y) ? x : y;
}
int main()
{
	int arr[2010];
	int rope[2010] = { 0 };
	int n, k;
	int ans = 0;
	scanf("%d %d", &n, &k);
	int i = 1;
	for (; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	for (i = 1; i <= n; i++)
	{
		int maxn = 0;
		for (int j = 1; j < i - k; j++)
		{
			maxn = Max(maxn, rope[j]);
		}
		rope[i] = arr[i] + maxn;
		ans = Max(ans, rope[i]);
	}
	printf("%d\n", ans);

	return 0;
}