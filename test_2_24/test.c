#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<string.h>
//void left_move(char str1[],char str2[], int len)
//{
//	int n = 0;
//	scanf("%d", &n);//����һ������ת���ַ������ַ�����
//	int i = 0;
//	for (i = 0; i < n; i++)//�Ѹ��ַ�����Ҫ����ת���ַ�����str2����ʱ���
//	{
//		str2[i] = str1[i];
//	}
//	int count = n;
//	while (count)//�Ѳ���Ҫ����ת���ַ���ǰ�ƶ�ֱ����n���ַ��������±�Ϊ0Ϊֹ
//	{
//		int j = 0;
//		for (j = count; j <len; j++)
//		{
//			str1[j-1]  =str1[j];
//		}
//		count--;
//	}
//	int k = 0;
//	for (k = 0; k <n; k++)//��֮ǰ�����str2���ַ�׷����str1�ĺ���
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
//����ת
//int left_move(char str1[], char str2[],char str3[], int len)
//{
//	int n = 0;
//	int flag = 0;
//	for (n = 1; n <= len; n++)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)//�Ѹ��ַ�����Ҫ����ת���ַ�����str2����ʱ���
//		{
//			str2[i] = str1[i];
//		}
//		int count = n;
//		while (count)//�Ѳ���Ҫ����ת���ַ���ǰ�ƶ�ֱ����n���ַ��������±�Ϊ0Ϊֹ
//		{
//			int j = 0;
//			for (j = count; j < len; j++)
//			{
//				str1[j - 1] = str1[j];
//			}
//			count--;
//		}
//		int k = 0;
//		for (k = 0; k < n; k++)//��֮ǰ�����str2���ַ�׷����str1�ĺ���
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
	//����ת
	for (i = 0; i < len; i++)
	{
		char temp = *str1; //�ѵ�һ���ַ�������
		int j = 0;
		for (j = 0; j < len-1; j++)
		{
			*(str1+j) = *(str1+j+1);
		}
		*(str1+len-1) = temp;//�Ѵ�õ��ַ����������
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
	}
	//����ת
	for (i = 0; i < len; i++)
	{
		char temp = *(str1 + len - 1);//�����һ���ַ�������
		int j = 0;
		for (j = 1; j < len; j++)
		{
			*(str1 +len- j) = *(str1 +len- j - 1);
		}
		*(str1) = temp;//�Ѵ�ŵ��ַ����ڵ�һλ
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
		printf("���ַ�����str1��ת����ַ���\n");
	}
	else
	{
		printf("���ַ�������str1��ת����ַ���\n");
	}
	return 0;
}