#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<assert.h>
////ģ��ʵ��strlen����
//int my_strlen(char* str)
//{
//	//�ö��Լ��str�Ƿ�Ϊ��ָ��
//	assert(str);
//	//��count����¼�ַ����ĳ���
//	int count = 0;
//	while (*str!='\0')//���strָ�������Ϊ'\0'������ѭ��
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
////ģ��ʵ��strcpy����
//char* my_strcpy(char* dest, const char* src)
//{
//	//���dest �� src ��һ���ǿ�ָ��Ͷ���
//	assert(dest && src);
//	//��dest��ԭ��ַ����
//	char* ret = dest;
//	//��src������ַ�һ��һ�����Ƶ�dest��ֱ��src='\0'ʱ����ѭ��
//	while (*dest++=*src++)
//	{
//		;
//	}
//	//������֮�󷵻�ԭ���ַ��������Ԫ�ص�ַ
//	return ret;
//}
//int main()
//{
//	char str1[] = "returnMyOffer";
//	char str2[20] = "studyHard";
//	printf("%s\n", my_strcpy(str2, str1));
//	return 0;
//}
//#include<stdio.h>
//#include<assert.h>
////ģ��ʵ��strcat�������ַ���׷�ӣ�
//char* my_strcat(char* dest, const char* src)
//{
//	//���dest �� src ��һ���ǿ�ָ��Ͷ���
//	assert(dest && src);
//	//��dest��ԭ��ַ����
//	char* ret = dest;
//	//��destָ��'\0'ʱ��ʼ׷�ӣ�src = '\0'ʱֹͣ׷��
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
#include<stdio.h>
#include<assert.h>
//ģ��ʵ��strcmp����
int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1 == *arr2)
	{
		if (*arr1 == '\0')
		{
			return 0;
		}
		arr1++;
		arr2++;
	}
	return *arr1 - *arr2;//���������ַ���ASCLL��Ĳ�ֵ
	
}
int main()
{
	char arr1[] = "hellobit";
	char arr2[] = "hellobit";
	if (my_strcmp(arr1, arr2) == 0)
		printf("arr1==arr2\n");
	else if (my_strcmp(arr1, arr2) > 0)
	{
		printf("arr1>arr2\n");
	}
	else
		printf("arr1<arr2\n");
	return 0;
}