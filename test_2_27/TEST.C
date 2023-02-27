#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//打印遍历一个整型数组的每个元素
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//这是一个交换函数，可以用来交换任意类型的数组元素
//像整型，字符型数组的元素，结构体类型的结构体成员
//这里的width指的是一个数组元素所占的字节数
//因为char类型的一个字符占用一个字节，一个整型是占四个字节，
//那么交换四个char型的字节也就是一个width实现交换一个整形元素
void swap(char* s1, char* s2, size_t width)
{
	size_t i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++;//交换了一个字节之后继续往后移动，直到交换了width个字节
		s2++;
	}
}
//这是一个该排序函数使用者自定义的一个函数，
//如果你想要排什么类型的数据就需要把该函数的参数p1,p2
//强转成相应类型的指针进行比较
int cmp_int(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
void bubble_sort(void* base, size_t count, size_t width, int (*cmp_int)(const void*, const void*))
{
	size_t i = 0;//定义i为无符号整数
	for(i = 0; i < count; i++)
	{
		int flag = 1;//假设待排序数组有序
		size_t j = 0;//定义j为无符号整数
		for (j = 0; j < count - i - 1; j++)
		{
			//默认排序成升序，若想要排成降序只需要把">0"修改成"<0"
			if (cmp_int((char*)base + j * width, (char*)base + (j + 1) * width)>0)
			{
				flag = 0;
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
		if (flag == 1)//如果上述循环数组元素一次都没有交换，
		{	         //说明有序，则flag没有被赋值为0,则不再需要继续多余的交换过程了
		
			break;
		}
	}
}
int main()
{
	//使用冒泡排序的思想模拟实现qsort的使用方法
	int arr[] = { 4,3,1,0,2,5,8,6,10,9,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);//该数组的大小，即有多少个元素
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);//打印排序后的数组
	return 0;
}