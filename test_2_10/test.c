#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//int main()
//{
//    
//    int i = 0;
//    int count = 0;
//    for (i = 100; i <= 200; i++)
//    {
//        int flag = 1;//����i������
//                      //�ж�i�Ƿ�������
//                      //��2������i��ֵȥ�Գ�i
//        int j = 0;
//        for (j = 2; j < sqrt(i); j++)
//        {
//            if (i % j == 0)
//            {
//                flag = 0;//��������
//                break;
//            }
//
//        }
//        if (flag == 1)
//        {
//            printf("%d ", i);
//            count++;
//        }
//        
//    }
//    printf("\ncount = %d\n", count);
//    return 0;
//}
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1000; i <= 2000; i++)
	{    

		//�ж�i�Ƿ�Ϊ����
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
		{
			count++;
			printf("%d ",i);
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}


//int main()
//{
//	//շת����������Լ��
//	int i, j;
//	scanf("%d %d", &i, &j);
//	int num = 0;
//	while (num = i % j)
//	{
//		i = j;
//		j = num;
//	}
//	printf("%d\n", j);
//	return 0;
//}
//int main()
//{
//
//    int i =0;
//    for(i = 1;i<=100;i++)
//    {
//        if(i%3==0)
//        {
//            printf("%d ",i);
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int a,b,c;
//    scanf("%d %d %d",&a,&b,&c);//��a,b,c�������Ӵ�С�������
//    if(b>a)
//    {
//        int tmp = b;
//        b = a;
//        a =tmp;
//    }
//    if(c>a)
//    {
//    int m = c;
//        c = a;
//        a =m;
//    }
//    if(c>b)
//    {
//
//        int n = c;
//        c = b;
//        b =n;
//    }
//    printf("%d %d %d",a,b,c);
//    return 0;
//}
//#include<math.h>
//int main ()
//{
//     int flag = 0;
//    int i = 0;
//    for(i = 100;i<=200;i++)
//    {
//
//        int j =0;
//        for(j = 2;j<sqrt(i);j++)
//        {
//            if(i%j!=0)
//            {
//                flag = 1;
//                break;
//            }
//
//        }
//        if(flag == 1)
//        {
//            printf("%d ",i);
//        }
//
//    }
//    return 0;
//}
