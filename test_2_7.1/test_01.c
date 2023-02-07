#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
#include<string.h>
int main()
{
	
		//数组名是首元素的地址
		//1. sizeof(数组名) -数组名表示整个数组
		//2. &数组名-数组名表示整个数组
		//
		//一维数组
	int a[] = { 1,2,3,4 };//4*4 = 16
	printf("%d\n", sizeof(a));//sizeof (数组名)-计算的是数组总大小-单位是字节-16
	printf("%d\n",sizeof(a + 0));//4/8 -数组名这里表示收元素的值，a+0 还是首元素地址，地址的大小就是4/8个字节
	printf("%d\n",sizeof(*a)); //4 -数组名表示首元素地址，*a就是首元素，sizeof(*a)就是4
	printf("%d\n",sizeof(a + 1));//4/8 一数组名这里表示收元素的值，a+1 第2个元素的地址，地址的大小就是4/8个字节
	printf("%d\n",sizeof(a[1])); //4 -第2个元素的大小
	printf("%d\n",sizeof(&a));
	//4/8 &a取出的是数组的地址，但是数组的地址那也是地址，地址的大小就是4/8个字节
	printf("%d\n",sizeof(*&a)); //16 - &a数组的地址，数组的地址解弓|用访问的数组，sizeof计算的就是数组的大小单位是字节
	printf("%d\n", sizeof(&a + 1));//4/8 &a是数组的地址， &a+1虽然地址跳过整个数组，但还是地址，所以是4/8个字节
	printf("%d\n",sizeof(&a[0]));//4/8 &a[0]是第一个元素的地址
	printf("%d\n", sizeof(&a[0] + 1));//4/8 &a[0]+1 是第二个元素的地址


	//字符数组
	char arr[] = { 'a', 'b','c','d', 'e', 'f' };
	printf("%d\n",sizeof(arr));//sizeofi计算机的是数组大小，6*1 = 6字节
	printf("%d\n",sizeof(arr + 0));//4/8 arr是首元素的地址，arr +0还是首元素的地址地址的大小是4/8字节
	printf("%d\n",sizeof(*arr));
	//1 arr是首元素的地址， *arr就是首元素，首元素是字符大小是一个字节
	printf(" %d\n",sizeof(arr[1])); //1
	printf("%d\n",sizeof(&arr)); //4/8 &arr虽然是数组的地址，但还是地址，地址大小是4/8个字节
	printf("%d\n",sizeof(&arr + 1));//4/8 &arr+1是跳过整个数组后的地址，地址大小是4/8个字节
	printf("%d\n",sizeof(&arr[0] + 1));//4/8第二个元素的地址


	//字符数组
char arr[] = { 'a', 'b','c','d','e','f'};
printf("%d\n",strlen(arr));//随机值
printf("%d\n",strlen(arr + 0));//随机值
//printf("%d\n",strlen(*arr));//err
//printf("%d\n",strlen(arr[1]));//err
//printf( "%d\n", strlen(&arr));//随机值
//printf("%d\n",strlen(&arr + 1));//随机值-6
//printf("%d\n",strlen(&arr[0]+1));//随机值-1


//char* p = "abcdef";
//printf("%d\n",sizeof(p));//4/8 -计算指针变量p的大小
//printf("%d\n",sizeof(p + 1));//4/8 . p+1得到的是字符b的地址
//printf("%d\n",sizeof(*p));//1 *p就是字符串的第一个字符一'a
//printf("%d\n",sizeof(p[0]));//1 int arr[10]; arr[0] == *(arr+0)  p[0] == *(p + 0) == 'a'
//printf("%d\n", sizeof(&p));//4/8 地址
//printf("%d\n",sizeof(&p + 1));//4/8地址
//printf("%d\n",sizeof(&p[0] + 1));//4/8. 地址


//二维数组
int a[3][4] = { 0 };
//printf("%p\n"，&a[0][0]);
//printf(“%p\n", a[0] + 1);
//printf("%p\n"，a+ 1);
//printf(*%p\n", &a[0] + 1);
printf("%d\n", sizeof(a));//48
printf("%d\n", sizeof(a[0][0]));//4
printf("%d\n", sizeof(a[0])); //16 a[e]相当于第一-行做为一维数组的数组名,
//sizeof(arr [0])把数组名单独放在sizeof()内，计算的是第- -行的大小
printf("%d\n",sizeof(a[0] + 1));//4 - a[0]是第一-行的数组名,数组名此时是首元素的地址，a[0]其实就是第一行第一个元素的地址
//所以a[0]+1就是第- -行第二个元素的地址-地址大小是4/8个字节
//printf("%d\n", sizeof(*(a[0] + 1)));//4- *(a[0] + 1))是第一-行第二个元素，大小是4个字节
printf("%d\n", sizeof(a + 1)); //4 //a是二维数组的数组名， 没有sizeof(a), 也没有&(a) ,所以a是首元素地址
//而把二维数组看成一-维数组时， 二维数组的首元素是他的第一行，a就是第一 -行(首元素)的地址
//a+1就是第二行的地址
printf(."%d\n"，sizeof(*(a + 1)));//16，sizeof(a[1]〉 计算第二行的大小，单位是字节
printf("%d\n",sizeof(&a[0] + 1));//4，第二行的地址
printf("%d\n", sizeof(*(&a[0] + 1)));//16.计算第二行的大小，单位是字节
printf("%d\n",sizeof(*a));//a是 首元素地址-第一-行的地址， *a就是第一行，sizeof(*a)就是计算第一 行的大小
printf("%d\n", sizeof(a[3]));//16


	return 0;
}

