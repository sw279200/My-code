#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
////ģ��ʵ��memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = (char*)dest;//�Ȱ�Ŀ�ĵص��׵�ַ������
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//��Դ�ַ���һ���ֽ�һ���ֽڵĿ�����Ŀ���ַ�����
//		dest = (char*)dest + 1;//����֮��������
//		src = (char*)src + 1;
//	}
//	return ret;//���ؿ������Ŀ�ĵص��׵�ַ
//
//}
////memcpy�����������ص��ڴ�
//int main()
//{
//	char arr1[] = "Return_MyOffer";
//	char arr2[20] = "mypro";
//	printf("%s\n", my_memcpy(arr2, arr1, 15));
//	return 0;
//}


//ģ��ʵ��memmove
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void * ret = dest;
	//��ǰ���󿽱�
	if (dest < src)
	{
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			dest = (char*)dest;
			src = (char*)src;

		}
	}
	else
	{
		//�Ӻ���ǰ����
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1 + 2, arr1, 20);
	return 0;
}