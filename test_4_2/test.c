#define _CRT_SECURE_NO_WARNINGS 1

////小白月赛59 A我会开摆
//
//#include<stdio.h>
//void solve()
//{
//	char arr[6][6];
//	int i = 1;
//	for (i = 1; i <= 4; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= 4; j++)
//		{
//			scanf("%c", &arr[i][j]);
//		}
//		getchar();
//	}
//	int flag = 0;
//	for (i = 1; i < 4; i++)
//	{
//		int j = 1;
//		for (j = 1; j < 4; j++)
//		{
//			if ((arr[i][j] == arr[i][j + 1])&& (arr[i + 1][j] == arr[i][j]) && (arr[i + 1][j] == arr[i + 1][j + 1]))
//			{
//				flag = 1;
//				goto end;
//			}
//		}
//	}
//	end:
//	if (flag == 1)
//	{
//		printf("Yes\n");
//	}
//	else if(flag==0)
//	{
//		printf("No\n");
//	}
//	
//}
//int main()
//{
//	int T = 0;
//	scanf("%d", &T);
//	while (T--)
//	{
//		solve();
//	}
//	return 0;
//}

//小白月赛59 B 走廊的灯
#include<stdio.h>
char str[100020];
int Max(int x, int y)
{
	return x > y ? x : y;
}
int len(char* str)
{
	char* ps = str;
	int ans = 0;
	while (*ps != '\0')
	{
		if (*ps == '0')
		{
			int count = 0;
			while ((*(ps++) != '1' || *(ps++) != '2'))
			{
				count++;
				ps++;
			}
			ps++;
			ans = Max(ans, count);
		}
		if (*ps == '1' || *ps == '2')
		{
			int num = 0;
			while (*(ps++) != '0')
			{
				num++;
				ps++;
			}
			ps++;
			ans = Max(ans, num);
		}
		
	}
	return ans;
}
void solve()
{
	int n = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", str);
		printf("%d\n", len(str));
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