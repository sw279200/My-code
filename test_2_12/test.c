#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//交换数组
//int main()
//{
//    int arr1[] = { 1,3,5,7,9  };
//    int arr2[] = { 2,4,6,8,10 };
//    int sz = sizeof(arr1) / sizeof(arr1[0]);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        int temp = arr1[i];
//        arr1[i] = arr2[i];
//        arr2[i] = temp;
//    }
//    printf("arr1: ");
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(arr1 + i));
//    }
//    printf("\n");
//    printf("arr2: ");
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(arr2 + i));
//    }
//    return 0;
//}
//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
//void init(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*(arr++) = 0;
//	}
//}
//void print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int* arr, int sz)
//{
//	int* left = arr;
//	int* right = arr + sz - 1;
//	for (left = arr, right = arr + sz - 1; left <= right; left++, right--)
//	{
//		int temp = *left;      //指向首元素的指针从头往后移动
//		*left = *right;       //指向最后一个元素从后往前移动
//		*right = temp;        //首元素与最后一个元素换位，然后继续移动继续换
//	}                         //直到两个指针相遇，就停下来
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("原数组为：>");
//	print(arr, sz);
//	reverse(arr, sz);
//	printf("逆置后的数组为：>");
//	print(arr, sz);
//	init(arr, sz);
//	printf("初始化之后的数组为：>");
//	print(arr, sz);
//	return 0;
//}
void bubble_sort(int *arr, int sz)
{
	int i = 0;
	//需要多少趟冒泡排序
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)//每趟冒泡排序需要排序的次数
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}
	}
}
int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);//用冒泡排序实现升序
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}