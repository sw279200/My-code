#define _CRT_SECURE_NO_WARNINGS 1

//小白月赛64 B题捕鱼达人
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int (max)(int a, int b)
{
	return ((a > b) ? a : b);
}
char arr[1010][1010];
int main()
{
	
	int n = 0;
	int m = 0;
	int ret = 0;
	int ans = 0;
	int i = 0;
	scanf("%d %d", &n, &m);
	getchar();
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &arr[i][j]);

			if (arr[i][j] == '#')
			{

				int a = abs(i - 1) + abs(j - 1);
				int b = abs(i - 1) + abs(j - m);
				int c = abs(i - n) + abs(j - 1);
				int d = abs(i - n) + abs(j - m);
				ret = max(a, b);
				ret = max(ret, c);
				ret = max(ret, d);
				ans = max(ret, ans);
			}
		}
		getchar();

	}
	printf("%d", ans);
	return 0;
}
