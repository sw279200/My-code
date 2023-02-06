#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//
//}



//int main()
//{   
//	char ch;
//	scanf("%c", &ch);
//	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//	{
//		printf("YES");
//	}
//	else
//		printf("NO");
//	return 0;
//}

//int main()
//{
//
//	unsigned int yearMonth;
//	scanf("%d", &yearMonth);
//	unsigned int num = yearMonth%100;//提取月份的值
//	if (num >= 12) {
//		printf("月份输入错误");
//	}
//	switch (num)
//	{
//	case 3:
//	case 4:
//	case 5:
//		printf("spring");
//		break;
//	case 6:
//	case 7:
//	case 8:
//		printf("summer");
//		break;
//	case 9:
//	case 10:
//	case 11:
//		printf("autumn");
//		break;
//	case 12:
//	case 1:
//	case 2:
//		printf("winter");
//		break;
//	default:
//		printf("没有该月份");
//		break;
//
//	}
//	return 0;
//}
//int main()
//{
//	float height;
//	float weight;
//	float BMI;
//	scanf("%f %f",&weight,&height );
//	BMI =( 1.0*weight) / (height*height);
//	if (BMI >= 18.5 && BMI <= 29.3)
//	{
//		printf("Normal");
//	}
//	else
//		printf("Abnormal");
//	return 0;
//}
//int Max(int a[],int sz)
//{
//	int MAX = a[0];
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (a[i] > MAX)
//			MAX = a[i];
//		
//	}
//	return MAX;
//}
//int main()
//{
//	int a, b, c, d;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//	int arr[4] = { a,b,c,d };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int max = Max(arr, sz);
//	printf("%d", max);
//	return 0;
//
//}
int main()
{
	char ch;
	while (scanf("%c\n", &ch)!=eof)
	{
		if (ch >= 'a' && ch <= 'z' || ch >= 'a' && ch <= 'z')
		{
			printf("%c is an alphabet.\n", ch);
			
		}
		else
		{ 
			printf("%c is not an alphabet.\n", ch);
		}
	}
	return 0;
}

//int main() {
//    int a;
//    scanf("%d", &a);
//    if (a % 2 == 0)//如果a能整除2就输出2
//        printf("2 ");
//    if (a % 3 == 0)如果a能整除3就输出3
//        printf("3 ");
//    if (a % 7 == 0)
//        printf("7 ");如果a能整除7就输出7
//    else if (a % 7 != 0 && a % 2 != 0 && a % 3 != 0) {
//        printf("n");
//    }
//}