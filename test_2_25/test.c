#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("arr = %p\n", arr);
//	printf("arr+1 = %p\n", arr+1);
//	printf("&arr = %p\n", &arr);
//	printf("&arr+1 = %p\n", &arr+1);
//	return 0;
//}
//void print1(int arr[3][5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print(int(*arr)[5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", *(*(arr + i) + j));//arr[i]
//			printf("%d ", arr[i][j]);//arr[i]
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = {1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7};
//	//��ά�������������Ҳ��ʾ��Ԫ�صĵ�ַ
//	//��ά�������Ԫ���ǵ�һ��
//	//��Ԫ�صĵ�ַ���ǵ�һ�еĵ�ַ,��һ��һά����ĵ�ַ
//	//
//	print(arr, 3, 5);
//	return 0;
//}
#include <stdio.h>
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//һ��ָ��p����������
//	print(p, sz);
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//	//pf���Ǻ���ָ��
//	int (* pf)(int, int) = Add;//�����ĵ�ַҪ���������͵÷��ڡ�����ָ���������
//	
//	int ret = (*pf)(3, 5);
//	//int ret = Add(3, 5);
//	//int ret = pf(3, 5);
//
//	printf("%d\n", ret);
//
//	return 0;
//}
//#include <stdio.h>
//void function()
//{
//	printf("hello xiaobai!\n");
//}
//int main()
//{
//	printf("%p\n", function);
//	printf("%p\n", &function);
//	return 0;
//}
//#include <stdio.h>
//int add(int a, int b)
//{
//    return a + b;
//}
//int sub(int a, int b)
//{
//    return a - b;
//}
//int mul(int a, int b)
//{
//    return a * b;
//}
//int div(int a, int b)
//{
//    return a / b;
//}
//int main()
//{
//    int x, y;
//    int input = 1;
//    int ret = 0;
//    do
//    {
//        printf("*************************\n");
//        printf(" 1:add      2:sub \n");
//        printf(" 3:mul      4:div \n");
//        printf(" 0:exit           \n");
//        printf("*************************\n");
//        printf("��ѡ��");
//        scanf("%d", &input);
//        switch (input)
//        {
//        case 1:
//            printf("�����������");
//            scanf("%d %d", &x, &y);
//            ret = add(x, y);
//            printf("ret = %d\n", ret);
//            break;
//        case 2:
//            printf("�����������");
//            scanf("%d %d", &x, &y);
//            ret = sub(x, y);
//            printf("ret = %d\n", ret);
//            break;
//        case 3:
//            printf("�����������");
//            scanf("%d %d", &x, &y);
//            ret = mul(x, y);
//            printf("ret = %d\n", ret);
//            break;
//        case 4:
//            printf("�����������");
//            scanf("%d %d", &x, &y);
//            ret = div(x, y);
//            printf("ret = %d\n", ret);
//            break;
//        case 0:
//            printf("�˳�����\n");
//            break;
//        default:
//            printf("ѡ�����\n");
//            break;
//        }
//    } while (input);
//
//    return 0;
//}
#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    return a / b;
}
int main()
{
    int x, y;
    int input = 1;
    int ret = 0;
    int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //ת�Ʊ�
    while (input)
    {
        printf("*************************\n");
        printf(" 1:add      2:sub \n");
        printf(" 3:mul      4:div \n");
        printf(" 0:exit           \n");
        printf("*************************\n");
        printf("��ѡ��");
        scanf("%d", &input);
        if ((input <= 4 && input >= 1))
        {
            printf("�����������");
            scanf("%d %d", &x, &y);
            ret = (*p[input])(x, y);
            printf("ret = %d\n", ret);
        }
        else if(input!=0)
            printf("��������\n");
        
    }
    printf("�˳�����");
    return 0;
}