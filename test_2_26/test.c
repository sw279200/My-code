#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
typedef struct stu {//这里定义了一个结构体类型s
	char name[50];
	int age;
}s;
typedef struct Str {  //这是把一个字符数组放在我们的结构体当中，为的是方便实现我们的字符串排序
	char str[50];
}k;
int cmp_age(const void* p1, const void* p2)//这是针对结构体s中的age排序实现的一个函数
{
	return ((s*)p1)->age - ((s*)p2)->age;//这里是把void*强制转换成结构体指针s*，通过s*再来找到结构体成员age进行排序
}
int cmp_name(const void* p1, const void* p2)//这是针对结构体s中的name排序实现的一个函数
{
	return strcmp(((s*)p1)->name, ((s*)p2)->name);//这里是把void*强制转换成结构体指针s*，通过s*再来找到结构体成员name进行排序
}
void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)//打印整型数组，方便看排序后的数组
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void print_str(k arr[], int sz)//打印排序后的字符串
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ",arr[i].str);
	}
	printf("\n");
}
void print_struct(s arr[],int sz)//打印结构体成员的值
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("(姓名：%s 年龄：%d) ", arr[i].name, arr[i].age);
	
	}
	printf("\n");
}
int cmp_str(const void* p1, const void* p2)//针对字符串排序实现的一个比较函数
{
	return strcmp(((k*)p1)->str, ((k*)p2)->str);
}
int cmp_int(const void* p1, const void* p2)//针对整型数据排序实现的一个比较函数
{
	return *(int*)p1 - *(int*)p2;
}
void test()
{
	int arr1[] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	
	s arr2[] = { {"zhangsan",22},{"lisi",33},{"wangwu",44} };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	k str[] = { {"sunwenchao"},{"pengge"},{"laowang"} };
	int sz3 = sizeof(str) / sizeof(str[0]);
	qsort(arr1, sz1, sizeof(arr1[0]), cmp_int);
	printf("排序后的数组为：\n");
	print_arr(arr1, sz1);
	qsort(arr2, sz2, sizeof(arr2[0]), cmp_age);
	printf("按年龄排序：\n");
	print_struct(arr2, sz2);
	qsort(arr2, sz2, sizeof(arr2[0]), cmp_name);
	printf("按名字排序：\n");
	print_struct(arr2, sz2);
	qsort(str, sz3, sizeof(str[0]), cmp_str);
	printf("排序后的字符串顺序为：\n");
	print_str(str, sz3);

}
int main()
{
	test();
	return 0;
}