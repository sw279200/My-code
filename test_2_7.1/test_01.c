#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
#include<string.h>
int main()
{
	
		//����������Ԫ�صĵ�ַ
		//1. sizeof(������) -��������ʾ��������
		//2. &������-��������ʾ��������
		//
		//һά����
	int a[] = { 1,2,3,4 };//4*4 = 16
	printf("%d\n", sizeof(a));//sizeof (������)-������������ܴ�С-��λ���ֽ�-16
	printf("%d\n",sizeof(a + 0));//4/8 -�����������ʾ��Ԫ�ص�ֵ��a+0 ������Ԫ�ص�ַ����ַ�Ĵ�С����4/8���ֽ�
	printf("%d\n",sizeof(*a)); //4 -��������ʾ��Ԫ�ص�ַ��*a������Ԫ�أ�sizeof(*a)����4
	printf("%d\n",sizeof(a + 1));//4/8 һ�����������ʾ��Ԫ�ص�ֵ��a+1 ��2��Ԫ�صĵ�ַ����ַ�Ĵ�С����4/8���ֽ�
	printf("%d\n",sizeof(a[1])); //4 -��2��Ԫ�صĴ�С
	printf("%d\n",sizeof(&a));
	//4/8 &aȡ����������ĵ�ַ����������ĵ�ַ��Ҳ�ǵ�ַ����ַ�Ĵ�С����4/8���ֽ�
	printf("%d\n",sizeof(*&a)); //16 - &a����ĵ�ַ������ĵ�ַ�⹭|�÷��ʵ����飬sizeof����ľ�������Ĵ�С��λ���ֽ�
	printf("%d\n", sizeof(&a + 1));//4/8 &a������ĵ�ַ�� &a+1��Ȼ��ַ�����������飬�����ǵ�ַ��������4/8���ֽ�
	printf("%d\n",sizeof(&a[0]));//4/8 &a[0]�ǵ�һ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));//4/8 &a[0]+1 �ǵڶ���Ԫ�صĵ�ַ


	//�ַ�����
	char arr[] = { 'a', 'b','c','d', 'e', 'f' };
	printf("%d\n",sizeof(arr));//sizeofi��������������С��6*1 = 6�ֽ�
	printf("%d\n",sizeof(arr + 0));//4/8 arr����Ԫ�صĵ�ַ��arr +0������Ԫ�صĵ�ַ��ַ�Ĵ�С��4/8�ֽ�
	printf("%d\n",sizeof(*arr));
	//1 arr����Ԫ�صĵ�ַ�� *arr������Ԫ�أ���Ԫ�����ַ���С��һ���ֽ�
	printf(" %d\n",sizeof(arr[1])); //1
	printf("%d\n",sizeof(&arr)); //4/8 &arr��Ȼ������ĵ�ַ�������ǵ�ַ����ַ��С��4/8���ֽ�
	printf("%d\n",sizeof(&arr + 1));//4/8 &arr+1���������������ĵ�ַ����ַ��С��4/8���ֽ�
	printf("%d\n",sizeof(&arr[0] + 1));//4/8�ڶ���Ԫ�صĵ�ַ


	//�ַ�����
char arr[] = { 'a', 'b','c','d','e','f'};
printf("%d\n",strlen(arr));//���ֵ
printf("%d\n",strlen(arr + 0));//���ֵ
//printf("%d\n",strlen(*arr));//err
//printf("%d\n",strlen(arr[1]));//err
//printf( "%d\n", strlen(&arr));//���ֵ
//printf("%d\n",strlen(&arr + 1));//���ֵ-6
//printf("%d\n",strlen(&arr[0]+1));//���ֵ-1


//char* p = "abcdef";
//printf("%d\n",sizeof(p));//4/8 -����ָ�����p�Ĵ�С
//printf("%d\n",sizeof(p + 1));//4/8 . p+1�õ������ַ�b�ĵ�ַ
//printf("%d\n",sizeof(*p));//1 *p�����ַ����ĵ�һ���ַ�һ'a
//printf("%d\n",sizeof(p[0]));//1 int arr[10]; arr[0] == *(arr+0)  p[0] == *(p + 0) == 'a'
//printf("%d\n", sizeof(&p));//4/8 ��ַ
//printf("%d\n",sizeof(&p + 1));//4/8��ַ
//printf("%d\n",sizeof(&p[0] + 1));//4/8. ��ַ


//��ά����
int a[3][4] = { 0 };
//printf("%p\n"��&a[0][0]);
//printf(��%p\n", a[0] + 1);
//printf("%p\n"��a+ 1);
//printf(*%p\n", &a[0] + 1);
printf("%d\n", sizeof(a));//48
printf("%d\n", sizeof(a[0][0]));//4
printf("%d\n", sizeof(a[0])); //16 a[e]�൱�ڵ�һ-����Ϊһά�����������,
//sizeof(arr [0])����������������sizeof()�ڣ�������ǵ�- -�еĴ�С
printf("%d\n",sizeof(a[0] + 1));//4 - a[0]�ǵ�һ-�е�������,��������ʱ����Ԫ�صĵ�ַ��a[0]��ʵ���ǵ�һ�е�һ��Ԫ�صĵ�ַ
//����a[0]+1���ǵ�- -�еڶ���Ԫ�صĵ�ַ-��ַ��С��4/8���ֽ�
//printf("%d\n", sizeof(*(a[0] + 1)));//4- *(a[0] + 1))�ǵ�һ-�еڶ���Ԫ�أ���С��4���ֽ�
printf("%d\n", sizeof(a + 1)); //4 //a�Ƕ�ά������������� û��sizeof(a), Ҳû��&(a) ,����a����Ԫ�ص�ַ
//���Ѷ�ά���鿴��һ-ά����ʱ�� ��ά�������Ԫ�������ĵ�һ�У�a���ǵ�һ -��(��Ԫ��)�ĵ�ַ
//a+1���ǵڶ��еĵ�ַ
printf(."%d\n"��sizeof(*(a + 1)));//16��sizeof(a[1]�� ����ڶ��еĴ�С����λ���ֽ�
printf("%d\n",sizeof(&a[0] + 1));//4���ڶ��еĵ�ַ
printf("%d\n", sizeof(*(&a[0] + 1)));//16.����ڶ��еĴ�С����λ���ֽ�
printf("%d\n",sizeof(*a));//a�� ��Ԫ�ص�ַ-��һ-�еĵ�ַ�� *a���ǵ�һ�У�sizeof(*a)���Ǽ����һ �еĴ�С
printf("%d\n", sizeof(a[3]));//16


	return 0;
}

