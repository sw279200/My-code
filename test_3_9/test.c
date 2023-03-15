#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<assert.h>
////模拟实现strlen函数
//int my_strlen(char* str)
//{
//	//用断言检查str是否为空指针
//	assert(str);
//	//用count来记录字符串的长度
//	int count = 0;
//	while (*str!='\0')//如果str指向的内容为'\0'就跳出循环
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "mystrlenfunction";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}


//#include<stdio.h>
//#include<assert.h>
////模拟实现strcpy函数
//char* my_strcpy(char* dest, const char* src)
//{
//	//如果dest 和 src 有一个是空指针就断言
//	assert(dest && src);
//	//把dest的原地址保存
//	char* ret = dest;
//	//把src里面的字符一个一个复制到dest，直到src='\0'时跳出循环
//	while (*dest++=*src++)
//	{
//		;
//	}
//	//复制完之后返回原来字符数组的首元素地址
//	return ret;
//}
//int main()
//{
//	char str1[] = "returnMyOffer";
//	char str2[20] = "studyHard";
//	printf("%s\n", my_strcpy(str2, str1));
//	return 0;
//}


//
//#include<stdio.h>
//#include<assert.h>
////模拟实现strcat函数（字符串追加）
//char* my_strcat(char* dest, const char* src)
//{
//	//如果dest 和 src 有一个是空指针就断言
//	assert(dest && src);
//	//把dest的原地址保存
//	char* ret = dest;
//	//从dest指向'\0'时开始追加，src = '\0'时停止追加
//	while (*dest!='\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//
//}
//int main()
//{
//	char arr1[50] = "return_my";
//	char arr2[] = "offer";
//	printf("%s\n", my_strcat(arr1, arr2));
//	return 0;
//}




//#include<stdio.h>
//#include<assert.h>
////模拟实现strcmp函数
//int my_strcmp(const char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2);
//	while (*arr1 == *arr2)
//	{
//		if (*arr1 == '\0')
//		{
//			return 0;
//		}
//		arr1++;
//		arr2++;
//	}
//	return *arr1 - *arr2;//返回两个字符的ASCLL码的差值
//	
//}
//int main()
//{
//	char arr1[] = "hellobit";
//	char arr2[] = "hellobit";
//	if (my_strcmp(arr1, arr2) == 0)
//		printf("arr1==arr2\n");
//	else if (my_strcmp(arr1, arr2) > 0)
//	{
//		printf("arr1>arr2\n");
//	}
//	else
//		printf("arr1<arr2\n");
//	return 0;
//}




#include<stdio.h>
#include<assert.h>
//模拟实现strstr函数
char* my_strstr(const char* str1,const char* str2)
{
	assert(str1 && str2);
	if (*str1 == '\0')
	{
		return str1;
	}
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cp = str1;
	
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*) cp;
		}
		cp++;
	}
	return NULL;//如果循环结束后没有找到说明没有，返回NULL
}
int main()
{
	char str1[] = "myoffferreturn";
	char str2[] = "ffer";
	char* ret = my_strstr(str1, str2);
	if (ret == NULL)
	{
		printf("没有找到\n");
	}
	else
	{
		printf("找到了，位置是：%s\n", ret);
	}
	return 0;
}
