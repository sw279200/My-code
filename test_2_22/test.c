#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////����һ��������n  (1 �� n �� 109)
////���һ�У�Ϊ������n��ʾΪ�����ƵĽ��
//int main()
//{
//	int arr[20] = { 0 };
//	int num = 0;
//	scanf("%d", &num);
//	int i = 0;
//	while (num>0)
//	{
//		 arr[i] = num % 6;
//		 num /= 6;
//		 i++;
//	}
//	int j = 0;
//	for (j = i-1; j >=0; j--)
//	{
//		printf("%d", arr[j]);
//	}
//	return 0;
//}

//��͹�ʽ
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	long long sum = 0;
//	int i = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	printf("%lld", sum);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	struct stu {
//		char name[20];
//		char sex;
//		int Chinese;
//		int math;
//		int English;
//		int sum;
//	};
//	struct stu arr[50];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s %c %d %d %d",arr[i].name, &arr[i].sex, &arr[i].Chinese, &arr[i].math, &arr[i].English);
//	}
//	int j = 0;
//	double Chinese_aver=0.00;
//	double math_aver=0.00;
//	double English_aver=0.00;
//
//	for (j = 0; j < n; j++)
//	{
//		Chinese_aver += arr[j].Chinese;
//		math_aver += arr[j].math;
//		English_aver += arr[j].English;
//		arr[j].sum = arr[j].Chinese + arr[j].math + arr[j].English;
//	}
//	int k = 0;
//	for (k = 0; k < n-1; k++)
//	{
//	
//		for (int m = 0; m < n - k - 1; m++)
//		{
//			if (arr[m].sum < arr[m+1].sum)
//			{
//				struct stu t = arr[m+1];
//				arr[m + 1]= arr[m];
//				arr[m]=t;
//			}
//		}
//	}
//	Chinese_aver /= n;
//	math_aver /= n;
//	English_aver /= n;
//	printf("����ƽ���֣�%.2f\n", Chinese_aver);
//	printf("��ѧƽ���֣�%.2f\n", math_aver);
//	printf("Ӣ��ƽ���֣�%.2f\n", English_aver);
//	printf("ȫ���һ����%s\n", arr[0].name);
//	printf("ȫ��ڶ�����%s\n", arr[1].name);
//	printf("ȫ���������%s\n", arr[2].name);
//	int m = 0;
//	int f = 0;
//	int x = 0;
//	for (x = 0; x < 5; x++)
//	{
//		if (arr[x].sex == 'M')
//		{
//			m++;
//		}
//		else if (arr[x].sex == 'F')
//		{
//			f++;
//		}
//	}
//
//	double f_scale = 1.00*f / (f+m);
//	double m_scale =1.00*m/(f+m);
//	printf("ǰ5������ռ�ȣ�%.2f%%\n", m_scale*100);
//	printf("ǰ5��Ů��ռ�ȣ�%.2f%%\n", f_scale*100);
//
//	return 0;
//}

//#include<stdio.h>
////�ж��Ƿ�������
//int Is_leap(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
////��������ھ��� 0000-00-00������
//int sum_day(int year, int month, int day,int* month_date)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < year; i++)
//	{
//		if (Is_leap(i))
//		{
//			sum += 366;
//		}
//		else
//		{
//			sum += 365;
//		}
//	}
//	int j = 0;
//	for (j = 0; j < month; j++)
//	{
//		if (Is_leap(year))
//		{
//			month_date[2] = 29;
//		}
//		sum += month_date[j];
//	}
//	sum += day;
//	return sum;
//
//}
//int main()
//{
//	struct date {
//		int year;
//		int month;
//		int day;
//	};
//	//һ���ÿ���¸��ж����죬2����ʱ��Ϊƽ������
//	int month_date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	struct date temp;
//	scanf("%d %d %d", &temp.year, &temp.month, &temp.day);
//	
//    int sum1 = sum_day(temp.year, temp.month, temp.day, month_date);
//	struct date ret = { 1949,9,30 };
//	int sum2 = sum_day(ret.year, ret.month, ret.day, month_date);
//	printf("%d", sum1 - sum2);
//	return 0;
//}
// //дһ�������������ݷ��������10���ַ�����С�����˳������
//#include<stdio.h>
//#include<string.h>
//void sort(char* str, int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		for (j = 0; j < len - i - 1; j++)
//		{
//			if (str[j] >= str[j + 1])
//			{
//				char temp = *(str+j);
//				*(str+j) = *(str+j + 1);
//				*(str+j+1) = temp;
//			}
//		}
//	}
// }
//int main()
//{
//	char str[10];
//	while ((scanf("%s", str)) != EOF)
//	{
//		sort(str, strlen(str));
//		printf("%s\n", str);
//	}
//
//	return 0;
//}
// ��һ�и���һ������n��2<n<10000����
// ��ʾһ���г��ж������г���
// ���n�У�����4������sh��sm��eh��em��
// ��ʾÿ���г��Ľ�վʱ��ͳ�վʱ�䡣
// h��׺����Сʱ��m��׺������ӡ����һ�и���2������h��m��0<=sh,eh,h<24  0<=sm,em,m<60����
// ����ѯ��ʱ�䡣��֤��վʱ��ͳ�վʱ����ͬһ�죬���ҳ�վʱ���ڽ�վʱ���
//#include<stdio.h>
//int main()
//{
//	int arr[100][4] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int h = 0;
//	int m = 0;
//	scanf("%d %d", &h, &m);
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (h >arr[i][0]&&h<arr[i][2])
//		{
//			count++;
//		}
//		else if (h == arr[i][0] && h < arr[i][2])
//		{
//			if (m >= arr[i][1])
//			{
//				count++;
//			}
//			else if (h == arr[i][0] && h == arr[i][2])
//			{
//				if (m >= arr[i][1]&&m<=arr[i][3])
//				{
//					count++;
//				}
//			}
//		}
//		
//	}
//	printf("%d\n", count);
//	return 0;
//}
#include<stdio.h>
#include<string.h>
int is_pla(char str[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			return 0;
		}
	}
	return 1;
		
		
	
}
int main()
{
	char str[100];
	scanf("%s",str);
	int ret = is_pla(str,strlen(str));
	if (ret)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}