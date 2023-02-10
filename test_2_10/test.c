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
//        int flag = 1;//假设i是素数
//                      //判断i是否是素数
//                      //用2到根号i的值去试除i
//        int j = 0;
//        for (j = 2; j < sqrt(i); j++)
//        {
//            if (i % j == 0)
//            {
//                flag = 0;//不是素数
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

		//判断i是否为闰年
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
//	//辗转相除法求最大公约数
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
//    scanf("%d %d %d",&a,&b,&c);//对a,b,c三个数从大到小排序输出
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
