#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//白兔的字符串
//案例能过，但是结果超时
int str_count(char* str1, char* str2, size_t len)
{
	size_t count = len;
	while (count--)
	{
		char temp = *str1;
		int i = 0;
		for (i = 0; i < len - 1; i++)
		{
			*(str1 + i) = *(str1 + i + 1);
		}
		*(str1 + len - 1) = temp;
		if (strcmp(str1, str2) == 0)
			return 1;
	}
	return 0;
}
char str1[10000];
int n = 0;
char str2[10000];
char str3[10000];
int main()
{
	
	scanf("%s", str1);
	scanf("%d", &n);
	size_t i= 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s", str2);
		int count = 0;
		int j = 0;
		for (j = 0; j <= strlen(str2) - strlen(str1); j++)
		{
			strncpy(str3, str2 + j, strlen(str1));
			count += str_count(str1, str3, strlen(str1));
		}
		printf("%d\n", count);
	}
	return 0;
}