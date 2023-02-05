#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//int main() {
//
//	int a = 1;
//	int i = 0;
//	int n;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		a = a * (i+1);
//	}
//	printf("%d\n", a);
//	return 0;
//}
//int main() {
//	int sum = 0;
//	int a = 1;
//	int i = 0;
//	int n;
//	for (i = 0; i < 10; i++) {
//		a = a * (i + 1);
//		sum += a;
//	}
//	printf("1! + 2! + 3! + ...... + 10! = %d\n", sum);
//	return 0;
//}
//int main() {
//
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
//	int n = 7;
//	int count = sizeof(arr) / sizeof(arr[0]);//计算元素个数
//	int right = count - 1;//右下标
//	int left = 0;//左下标
//
//
//	while (left <=  right) {
//		int mid = (right + left) / 2;
//		if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n) {
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d", mid);
//			break;
//		}
//	}
//	if (right < left) {
//		printf("抱歉，没有找到！");
//	}
//	return 0;
//}
//int main() {
//	char arr1[] = "welcome to my world!!!!!!";
//	char arr2[] = "*************************";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//
//	while (right>=left) {
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//
//
//
//
//	return 0; 
//}

int main(){
	int i = 0;
	                       //判断是否是素数
	int count = 0;
	for (i = 100; i <= 200;i++) {
		int j = 0;
		for (j = 2; j < sqrt(i); j++) {
			if (i % j == 0) {
				break;
			}
			
		
		}
		if (j >sqrt(i)) {
			count++;
			printf("%d ", i);

		}
	}

	printf("\ncount = %d\n", count);
	return 0;

}


