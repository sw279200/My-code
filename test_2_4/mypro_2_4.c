#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//int main() {
//
//	//二分法查询
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int right = sizeof(arr) / sizeof(arr[0])-1;
//	int left = 0;
//	int mid = 0;
//	
//
//	while (left <= right) {
//		mid = (right + left) / 2;
//		if (arr[mid] > k) {
//			right = mid - 1;
//
//		}
//		else if (arr[mid] < k) {
//			left = mid + 1;
//		}
//		else
//			break;
//	}
//
//	if (left <= right) {
//
//		printf("找到了，下标是%d", mid);
//	}
//	else
//		printf("抱歉，没找到");
//	return 0;
//}
void bubble_sort(int arr[], int sz) {
	int i = 0;
	int flag = 1;
	for (i = 0; i < sz - 1; i++) {
		int flag = 1;//假设这一趟排序有序
		for (int j = 0; j < sz - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}
int main() {

	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}