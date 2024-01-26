#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
void solve()
{
	int n = 0,length = 0;
	int arr1[1010] = { 0 }, arr2[5050] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (arr1[x] == 0)
		{
			arr1[x]++;
			arr2[length++] = x;
		}
	}
	for (int j = 0; j < length; j++) printf("%d ", arr2[j]);
	printf("\n");
}

int main()
{
	solve();
	return 0;
}