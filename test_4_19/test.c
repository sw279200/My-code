#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//小d和答案修改
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[501] = { 0 };
	scanf("%s", arr);
	int len = strlen(arr);
	int i = 0;
	for (; i < len; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			printf("%c", arr[i] + 32);
		else if (arr[i] >= 'a' && arr[i] <= 'z')
			printf("%c", arr[i] - 32);
	}
	printf("\n");
	return 0;
}
#endif

#if 1

#include <stdio.h>
int arr[1001][1001] = { 0 };
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i+=2)
	{
		for (int j = 1; j <= m; j+=2)
		{
			printf("%d ", (arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1]) / 4);
		}
		printf("\n");
	}
	return 0;
}
#endif
