#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��������
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
//����һ���������飬��ɶ�����Ĳ���
//
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
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
//		int temp = *left;      //ָ����Ԫ�ص�ָ���ͷ�����ƶ�
//		*left = *right;       //ָ�����һ��Ԫ�شӺ���ǰ�ƶ�
//		*right = temp;        //��Ԫ�������һ��Ԫ�ػ�λ��Ȼ������ƶ�������
//	}                         //ֱ������ָ����������ͣ����
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("ԭ����Ϊ��>");
//	print(arr, sz);
//	reverse(arr, sz);
//	printf("���ú������Ϊ��>");
//	print(arr, sz);
//	init(arr, sz);
//	printf("��ʼ��֮�������Ϊ��>");
//	print(arr, sz);
//	return 0;
//}
void bubble_sort(int *arr, int sz)
{
	int i = 0;
	//��Ҫ������ð������
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)//ÿ��ð��������Ҫ����Ĵ���
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
	bubble_sort(arr,sz);//��ð������ʵ������
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}