#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
////Ìí¼Ó¶ººÅ
//int main()
//{
//	char arr[14];
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	int k = 0;
//	while (n)
//	{
//		if (k % 3 == 0 && k != 0)
//		{
//			arr[i++] = ',';
//		}
//		arr[i++] = n % 10 + '0';
//		n /= 10;
//		k++;
//	}
//
//	for (--i; i >= 0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

#include<stdio.h>
//É¾³ý¹«¹²×Ö·û´®
int func(char* str, char ch)
{
	int i = 0;
	while (str[i])
	{
		if (ch == str[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}
int main()
{
	char str1[101] = {0};
	char str2[101] = {0};
	gets(str1);
	gets(str2);
	int i = 0;
	while (str1[i])
	{
		int x = func(str2, str1[i]);
		if (x == 0)
		{
			printf("%c", str1[i]);
		}
		i++;
	}
	return 0;
}