#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
////一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
////编写一个函数找出这两个只出现一次的数字。
//int * solve(int arr[],int sz,int *num)
//{
//	int ret = 0;
//	int pos = 0;
//	int i = 0;
//	//让ret与数组中所有的数异或，最后的结果是两个不相同的数异或的结果
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//用pos记录两个单身狗数异或结果为1的位置，这说明这两个单身狗数在这个位置上的二进制位不同
//	for (pos = 0; pos < 32; pos++)
//	{
//		if (((ret >> pos) & 1) == 1)
//		{
//			break;
//		}
//	}
//	//将数组分成两组，一组为二进制位在pos位上是1的数，一组是为0的数
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			//num[1]里面存的是其中一个单身狗数
//			num[1] ^= arr[i];
//		}
//		else
//		{
//			//num[0]里面存的是另一个单身狗数
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
////模拟实现strncpy
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	//把目的地址存起来,用来return
//	char* ret = dest;
//	//如果src字符串长度小于需要复制到dest的字符个数，则用'\0'来填充
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
////模拟实现strncat
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



//atoi    将一个字符串转化为一个整型
//模拟实现atoi
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
	//字符串长度为0
	if (*str == '\0')
	{
		return 0;
	}
	//字符串前面有很多空格
	while (*p == ' ')
	{
		p++;
	}
	//判断符号
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
	//开始计算
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
 特殊情况
 1前面有一大堆空格
 2传过来空指针
 3字符串长度为0
 4整形溢出
 5含有其它字符
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
		printf("非法转化\n");
	}

	return 0;
}