#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//���ϸ�ð
#include<stdio.h>
int abss(int s)//ȡ����ֵ 
{
    if (s < 0)return -s;
    else return s;
}
int  main()
{
    int qans = 0, hans = 0, n, i, gm, s;
    scanf("%d", &n);
    scanf("%d", &gm);//gm �׸���ð���� λֵ 
    for (i = 1; i < n; i++)
    {
        scanf("%d", &s);
        if (abss(gm) < abss(s) && s < 0)hans++;//�����׸������Ҳಢ�ҷ��� �ظ�ð 
        if (abss(gm) > abss(s) && s > 0)qans++;//�����׸�������ಢ������ �ظ�ð 
    }
    if (gm > 0 && hans != 0 || gm < 0 && qans != 0)printf("%d", qans + hans + 1);
    else printf("1");//���׸���ð���Ϸ���Ϊ��ʱ ���׸������Ҳಢ�ҷ��� Ϊ 0 ��  
    return 0; //���׸���ð���Ϸ���Ϊ��ʱ ���׸�������ಢ�ҷ��� Ϊ 0 �򲻻ᱻ��ð���׸���ð 
}
#endif


#if 0
//���ű�2013����Ľ����� - ����Ʊ��
#include <stdio.h>
#include <stdlib.h>
//��ʱ���𰸴���
//// ���������ڿӷ�
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
//		//�ұ��ұ�keyС����
//		while (start < end && a[end] >= key)
//		{
//			end--;
//		}
//		//�ҵ���ŵ�����ȥ
//		a[pivot] = a[end];
//		//ԭ��λ�ñ�ɿ�
//		pivot = end;
//		//����ұ�keyС����
//		while (start < end && a[start] <= key)
//		{
//			start++;
//		}
//		//�ҵ���ŵ�����ȥ
//		a[pivot] = a[start];
//		//ԭ��λ�ñ�ɿ�
//		pivot = start;
//
//	}//�����ǿ��ŵĵ�������
//
//	pivot = start;
//	a[pivot] = key;
//	//��������������������򣬸����о������ˣ����÷��εݹ���
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