#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
////OJ第一次月赛6 文文玩原神
//void solve()
//{
//	int a, b, c, d;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//	if (a < 180)
//	{
//		printf("No\n");
//		return;
//	}
//	b = b + (a - 180) / 3;
//	if (b < 180)
//	{
//		printf("No\n");
//		return;
//	}
//	c = c + (b - 180) / 3;
//	if (c< 180)
//	{
//		printf("No\n");
//		return;
//	}
//	d = d + (c - 180) / 3;
//	if (d < 180)
//	{
//		printf("No\n");
//		return;
//	}
//	printf("Yes\n");
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	while(n--)
//	solve();
//	return 0;
//}

//#include<stdio.h>
////OJ第一次月赛1 文文数数
//int arr[101];
//
//int function(int x)
//{
//	if (x % 10 == 0 || x % 10 == 2)return x;
//	return function(x + x % 10);
//}
//void solve()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int flag = 0;
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//		arr[i] = function(arr[i]);
//		if(arr[i] % 10 == 0)flag = 1;
//	}
//
//	if (flag)
//	{
//		for (i = 2; i <= n; i++)
//		{
//			if (arr[i] != arr[i - 1])
//			{
//				printf("No");
//				return;
//			}
//
//		}
//		printf("Yes");
//		return;
//	}
//
//	for (i = 2; i <= n; i++)
//	{
//		if ((arr[i] - arr[i - 1]) % 20!= 0)
//		{
//			printf("No");
//			return;
//		}
//	}
//	printf("Yes");
//	
//}
//int main()
//{
//	solve();
//	return 0;
//}

#include<stdio.h>
int min(int x, int y)
{
	return ((x < y)?x:y);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[22] = { 0 };
	int i = 0;
	int sum = 0;
	int ans = 1000000000;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int k = 1;
	for (k = 1; k <= n; k++)
	{
		int i = 0;
		for (i = k; i <= n; i++)
		{
			int j = 0;
			for (j = k; j <= i; j++)
			{
				if (j == k)
				{
					sum = arr[j];
				}
				else
				{
					sum &= arr[j];
				}
				ans = min(ans, sum);
			}
		}
	}
	printf("%d", ans);
	return 0;
}