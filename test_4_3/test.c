#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stddef.h>
////дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
////���죺offsetof���ʵ��
//#define OFFSETOF(type,name)  (size_t)&(((type*)0)->name)
//
////offsetof��ʹ��
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
//	//offsetof��ʹ��
//	printf("offsetofʹ�õõ���һ�������\n");
//	printf("%d\n", offsetof(struct S,a));
//	printf("%d\n", offsetof(struct S,c));
//	printf("%d\n", offsetof(struct S,d));
//
//	//offsetof��ʵ�ֵĽ��
//	printf("OFFSETOF��ʵ�ֵĽ��:\n");
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, c));
//	printf("%d\n", OFFSETOF(struct S, d));
//	return 0;
//}


#include<stdio.h>
//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ������
//���λΪ��һλ
#define SWAP(x) (((x&0x55555555)<<1)+((x&0xaaaaaaa)>>1))

int main()
{
	int a = 5;
	//������λΪ 00000000 00000000 00000000 00000101
	//           00000000 00000000 00000000 00001010
	//����ż��λ������
	printf("%d\n", SWAP(a));
	return 0;
}