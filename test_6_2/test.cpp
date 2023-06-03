#define _CRT_SECURE_NO_WARNINGS 1
//归并排序
#include <iostream>
using namespace std;
int n;
int arr[1000010];
int temp[1000010];

void merge_sort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);

	int k = 0;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left, j = 0; i <= right; i++, j++)
	{
		arr[i] = temp[j];
	}
}

int main()
{
	cout << "请输入需要排序的个数： ";
	cin >> n;
	cout << "排序前：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	merge_sort(arr, 0, n - 1);
	cout << "排序后：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
