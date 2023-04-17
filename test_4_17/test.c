#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//蚂蚁感冒
#include<stdio.h>
int abss(int s)//取绝对值 
{
    if (s < 0)return -s;
    else return s;
}
int  main()
{
    int qans = 0, hans = 0, n, i, gm, s;
    scanf("%d", &n);
    scanf("%d", &gm);//gm 首个感冒蚂蚁 位值 
    for (i = 1; i < n; i++)
    {
        scanf("%d", &s);
        if (abss(gm) < abss(s) && s < 0)hans++;//当在首个蚂蚁右侧并且反向 必感冒 
        if (abss(gm) > abss(s) && s > 0)qans++;//当在首个蚂蚁左侧并且正向 必感冒 
    }
    if (gm > 0 && hans != 0 || gm < 0 && qans != 0)printf("%d", qans + hans + 1);
    else printf("1");//当首个感冒蚂蚁方向为正时 在首个蚂蚁右侧并且反向 为 0 或  
    return 0; //当首个感冒蚂蚁方向为负时 在首个蚂蚁左侧并且反向 为 0 则不会被感冒除首个感冒 
}
#endif


#if 0
//蓝桥杯2013年第四届真题 - 错误票据
#include <stdio.h>
#include <stdlib.h>
//超时，答案错误
//// 快速排序挖坑法
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int start = left;
//	int end = right;
//	int pivot = start;
//	int key = a[start];
//	while (start < end)
//	{
//		//右边找比key小的数
//		while (start < end && a[end] >= key)
//		{
//			end--;
//		}
//		//找到后放到坑里去
//		a[pivot] = a[end];
//		//原来位置变成坑
//		pivot = end;
//		//左边找比key小的数
//		while (start < end && a[start] <= key)
//		{
//			start++;
//		}
//		//找到后放到坑里去
//		a[pivot] = a[start];
//		//原来位置变成坑
//		pivot = start;
//
//	}//以上是快排的单趟排序
//
//	pivot = start;
//	a[pivot] = key;
//	//左子区间和右子区间有序，该序列就有序了，采用分治递归解决
//	QuickSort(a, left, pivot - 1);
//	QuickSort(a, pivot + 1, right);
//}
int cmp(void* p1, void* p2)
{
	return *((int*)p1) - *((int*)p2);
}
int main()
{
    int N = 0;
    int arr[101] = { 0 };
    scanf("%d", &N);
	int num = N;
    int i = 0;
	while (~scanf("%d", &arr[i++]))
	{
		;
		if (getchar() == '\n')
		{
			num--;
		}

	}

	qsort(arr, i, sizeof(arr[0]), cmp);
	int cur = 1;
	int count = 0;
	while (arr[cur] != arr[count]&&cur<N)
	{
		cur++;
		count++;
	}
	int n = arr[cur];
	cur = 1;
	count = 0;
	while (arr[cur] == (arr[count]+1)&&cur<N)
	{
		cur++;
		count++;
	}
	int m = arr[count] + 1;
	printf("%d %d\n", m, n);
    return 0;
}
#endif

#if 1
#include <stdio.h>
int main() {
	int a[100001] = { 0 };
	int n, m, num, max, min;
	int i;

	n = m = max = 0;
	min = 0x7fffffff;

	scanf("%d", &num);
	while (~scanf("%d", &num)) {
		if (max < num)
			max = num;
		if (min > num)
			min = num;
		a[num]++;
	}
	for (i = min + 1; i <= max; i++) {
		if (a[i - 1] == 1) {
			if (a[i] == 0 && a[i + 1] == 1)
				n = i;
		}
	}
	for (i = min; i <= max; i++)
		if (a[i] > 1)
			m = i;
	printf("%d %d", n, m);

	return 0;
}
#endif