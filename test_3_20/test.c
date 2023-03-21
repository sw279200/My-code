<<<<<<< HEAD
ï»¿#define _CRT_SECURE_NO_WARNINGS 1

//å°ç™½æœˆèµ›64 Bé¢˜æ•é±¼è¾¾äºº
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int (max)(int a, int b)
=======
#define _CRT_SECURE_NO_WARNINGS 1

//Ğ¡°×ÔÂÈü64 BÌâ²¶Óã´ïÈË
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int max(int a, int b)
>>>>>>> f3085594ccece8af816ed76ff4cdfe94c3a64f8d
{
	return ((a > b) ? a : b);
}
char arr[1010][1010];
int main()
{
<<<<<<< HEAD
	
=======

>>>>>>> f3085594ccece8af816ed76ff4cdfe94c3a64f8d
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
