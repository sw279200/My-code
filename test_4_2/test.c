#define _CRT_SECURE_NO_WARNINGS 1

////С������59 A�һῪ��
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

//С������59 B ���ȵĵ�
#include<stdio.h>
char str[100020];
int Max(int x, int y)
{
	return x > y ? x : y;
}

void solve()
{
	int n = 0;
	scanf("%d", &n);
	scanf("%s", str);
	int ans = 1;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (str[i] != '1')
		{
			int j = i;
			while (j < n && str[j] != '1')
			{
				j++;
			}
			ans = Max(ans, j-i);
			j--;
			i = j;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (str[i] != '0')
		{
			int j = i;
			while (j < n && str[j] != '0')
			{
				j++;
			}
			ans = Max(ans, j - i);
			j--;
			i = j;
		}
	}
	printf("%d\n", ans);
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