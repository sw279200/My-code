#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
////һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
////��дһ�������ҳ�������ֻ����һ�ε����֡�
//int * solve(int arr[],int sz,int *num)
//{
//	int ret = 0;
//	int pos = 0;
//	int i = 0;
//	//��ret�����������е���������Ľ������������ͬ�������Ľ��
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//��pos��¼���������������Ϊ1��λ�ã���˵�������������������λ���ϵĶ�����λ��ͬ
//	for (pos = 0; pos < 32; pos++)
//	{
//		if (((ret >> pos) & 1) == 1)
//		{
//			break;
//		}
//	}
//	//������ֳ����飬һ��Ϊ������λ��posλ����1������һ����Ϊ0����
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			//num[1]������������һ��������
//			num[1] ^= arr[i];
//		}
//		else
//		{
//			//num[0]����������һ��������
//			num[0] ^= arr[i];
//		}
//	}
//	return num;
//}
//int main()
//{
//	int arr[] = { 1,2,2,3,4,4,5,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int nums[2] = { 0 };
//	int* p = solve(arr,sz,nums);
//	printf("%d %d\n",p[0], p[1]);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
////ģ��ʵ��strncpy
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	//��Ŀ�ĵ�ַ������,����return
//	char* ret = dest;
//	//���src�ַ�������С����Ҫ���Ƶ�dest���ַ�����������'\0'�����
//	while (num &&(*dest++ = *src++))
//	{
//		num--;
//	}
//	if (num)
//	{
//		while (--num)
//		{
//			*dest++ = '\0';
//		}
//	}
//	return ret;
//
//}
//int main()
//{
//	char dest[20] = "return ";
//	char *src = "MyOffer";
//	printf("%s\n", my_strncpy(dest, src, 10));
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
////ģ��ʵ��strncat
//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;
// 	while (*dest)
//	{
//		dest++;
// 	}
//	while (num&&(*dest++ = *src++))
//	{
//		num--;
//	}
//	if (num)
//	{
//		while (--num)
//		{
//			*dest++ = '\0';
//		}
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
// {
//	char dest[50] = "visual stdio ";
//	char src[10] = "code";
//	printf("%s\n", my_strncat(dest, src, 7));
//	return 0;
//}



//atoi    ��һ���ַ���ת��Ϊһ������
//ģ��ʵ��atoi
#include<stdio.h>
#include<assert.h>
#include<limits.h>
#include<ctype.h>
enum state
{
	Value,
	ErrValue
};
enum state statue = ErrValue;
int my_atoi(const char* str)
{
	assert(str);

	char* p = (char*)str;

	long long n = 0;
	int flag = 1;
	//�ַ�������Ϊ0
	if (*str == '\0')
	{
		return 0;
	}
	//�ַ���ǰ���кܶ�ո�
	while (*p == ' ')
	{
		p++;
	}
	//�жϷ���
	if (*p == '+')
	{
		flag = 1;
		p++;
	}
	else if (*p == '-')
	{
		flag = -1;
		p++;
	}
	//��ʼ����
	while (*p != '\0')
	{
		if (isdigit(*p))
		{
			n = n * 10 + flag * (*p - '0');
			if (n > INT_MAX)
			{
				n = INT_MAX;
				break;
			}
			else if (n < INT_MIN)
			{
				n = INT_MIN;
				break;
			}
		}
		else
		{
			break;
		}
		p++;
	}

	if (*p == '\0')
	{
		statue = Value;
	}

	return (int)n;
}/**
 �������
 1ǰ����һ��ѿո�
 2��������ָ��
 3�ַ�������Ϊ0
 4�������
 5���������ַ�
 */
int main()
{
	char arr[] = "12345678";
	int m = my_atoi(arr);
	if (statue == Value)
	{
		printf("%d\n", m);
	}
	if (statue == ErrValue)
	{
		printf("�Ƿ�ת��\n");
	}

	return 0;
}