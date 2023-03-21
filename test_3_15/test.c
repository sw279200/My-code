#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
////模拟实现memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = (char*)dest;//先把目的地的首地址存起来
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//把源字符串一个字节一个字节的拷贝到目的字符串中
//		dest = (char*)dest + 1;//拷贝之后往后移
//		src = (char*)src + 1;
//	}
//	return ret;//返回拷贝后的目的地的首地址
//
//}
////memcpy函数拷贝不重叠内存
//int main()
//{
//	char arr1[] = "Return_MyOffer";
//	char arr2[20] = "mypro";
//	printf("%s\n", my_memcpy(arr2, arr1, 15));
//	return 0;
//}


//模拟实现memmove
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void * ret = dest;
	//从前往后拷贝
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
		//从后往前拷贝
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