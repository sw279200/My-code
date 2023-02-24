#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<string.h>
//void left_move(char str1[],char str2[], int len)
//{
//	int n = 0;
//	scanf("%d", &n);//输入一个左旋转该字符串的字符个数
//	int i = 0;
//	for (i = 0; i < n; i++)//把该字符串需要左旋转的字符放入str2中暂时存放
//	{
//		str2[i] = str1[i];
//	}
//	int count = n;
//	while (count)//把不需要左旋转的字符往前移动直到第n个字符的数组下标为0为止
//	{
//		int j = 0;
//		for (j = count; j <len; j++)
//		{
//			str1[j-1]  =str1[j];
//		}
//		count--;
//	}
//	int k = 0;
//	for (k = 0; k <n; k++)//把之前存放在str2的字符追加在str1的后面
//	{
//		str1 [len- n + k] = str2[k];
//	}
//	printf("%s", str1);
//}
//int main()
//{
//	char str1[20];
//	char str2[20];
//	scanf("%s", str1);
//	int len = strlen(str1);
//	left_move(str1,str2, len);
//	return 0;
//}
#include <stdio.h>
#include<string.h>
//左旋转
//int left_move(char str1[], char str2[],char str3[], int len)
//{
//	int n = 0;
//	int flag = 0;
//	for (n = 1; n <= len; n++)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)//把该字符串需要左旋转的字符放入str2中暂时存放
//		{
//			str2[i] = str1[i];
//		}
//		int count = n;
//		while (count)//把不需要左旋转的字符往前移动直到第n个字符的数组下标为0为止
//		{
//			int j = 0;
//			for (j = count; j < len; j++)
//			{
//				str1[j - 1] = str1[j];
//			}
//			count--;
//		}
//		int k = 0;
//		for (k = 0; k < n; k++)//把之前存放在str2的字符追加在str1的后面
//		{
//			str1[len - n + k] = str2[k];
//		}
//		if (strcmp(str1, str3)==0)
//		{
//			flag = 1;
//		}
//	}
//	
//	return flag;
//}
int is_reveser(char* str1,char* str2)
{
	int len = strlen(str1);
	int i = 0;
	//左旋转
	for (i = 0; i < len; i++)
	{
		char temp = *str1; //把第一个字符存起来
		int j = 0;
		for (j = 0; j < len-1; j++)
		{
			*(str1+j) = *(str1+j+1);
		}
		*(str1+len-1) = temp;//把存好的字符放在最后面
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
	}
	//右旋转
	for (i = 0; i < len; i++)
	{
		char temp = *(str1 + len - 1);//把最后一个字符存起来
		int j = 0;
		for (j = 1; j < len; j++)
		{
			*(str1 +len- j) = *(str1 +len- j - 1);
		}
		*(str1) = temp;//把存放的字符放在第一位
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char str1[20];
	char str2[20];
	scanf("%s", str1);
	scanf("%s", str2);
	if (is_reveser(str1, str2))
	{
		printf("该字符串是str1旋转后的字符串\n");
	}
	else
	{
		printf("该字符串不是str1旋转后的字符串\n");
	}
	return 0;
}