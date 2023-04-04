#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stddef.h>
////写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
////考察：offsetof宏的实现
//#define OFFSETOF(type,name)  (size_t)&(((type*)0)->name)
//
////offsetof的使用
//
//struct S
//{
//	int a;
//	char c;
//	double d;
//};
//struct S s;
//int main()
//{
//	//offsetof的使用
//	printf("offsetof使用得到的一个结果：\n");
//	printf("%d\n", offsetof(struct S,a));
//	printf("%d\n", offsetof(struct S,c));
//	printf("%d\n", offsetof(struct S,d));
//
//	//offsetof宏实现的结果
//	printf("OFFSETOF宏实现的结果:\n");
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, c));
//	printf("%d\n", OFFSETOF(struct S, d));
//	return 0;
//}


#include<stdio.h>
//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
//最低位为第一位
#define SWAP(x) (((x&0x55555555)<<1)+((x&0xaaaaaaa)>>1))

int main()
{
	int a = 5;
	//二进制位为 00000000 00000000 00000000 00000101
	//           00000000 00000000 00000000 00001010
	//奇数偶数位交换后
	printf("%d\n", SWAP(a));
	return 0;
}