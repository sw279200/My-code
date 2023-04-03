#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
////c语言文件操作
//int main()
//{	//打开文件
//  //相对路径
//	FILE* pf = fopen("C:\\Users\\luoluo\\OneDrive\\桌面\\test.txt","w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读/写文件
//
//	//关闭文件
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}



//#include<stdio.h>
////c语言文件操作
////fputc-写文件
//int main()
//{	//打开文件
//	FILE* pf = fopen("test.txt","w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读/写文件
//	int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		fputc('a' + i, pf);
//	}
//	//关闭文件
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}

//#include<stdio.h>
//
////fgetc-读文件操作
//int main()
//{
//	//打开文件
//	file* pf = fopen("test.txt", "r");
//	if (pf == null)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	int ch = 0;
//	int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		ch = fgetc(pf);
//		printf("%c ", ch);
//	}
//	
//	//关闭文件
//	fclose(pf);
//	pf == null;
//	return 0;
//}

//#include<stdio.h>
//
////fputs-写一行数据
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fputs("hello bit\n", pf);
//	fputs("hello world\n", pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include<stdio.h>
//
////fgets-读一行数据
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	char arr[20];
//	fgets(arr, 10, pf);
//	printf("%s\n", arr);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include<stdio.h>
//
////格式化的读写
////fscanf 
////fprintf
//
//typedef struct S 
//{
//	char arr[20];
//	float f;
//	int n;
//}S;
//int main()
//{
//	S s = { "jiege",3.14f,600};
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读写文件
//	fprintf(pf,"%s %f %d\n", s.arr, s.f, s.n);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//测试fscanf函数

#include<stdio.h>
typedef struct S 
{
	char arr[20];
	float f;
	int n;
}S;
int main()
{
	S s = { 0 };
	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//读文件
	fscanf(pf, "%s %f %d", s.arr, &(s.f), &(s.n));
	printf("%s %f %d\n", s.arr, s.f, s.n);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//#include<stdio.h>
//typedef struct S
//{
//	int n;
//	float f;
//	char arr[20];
//}S;
//int main()
//{
	//int ch = fgetc(stdin);
	//printf("%c\n", ch);
	//fputc('a', stdout);
	//fputc('b', stdout);
	//fputc('c', stdout);
	//fputc('d', stdout);
	//S s = { 600,3.666f,"nianxin" };
	//fprintf(stdout, "%d %f %s", s.n, s.f, s.arr);
//	S s = { 0 };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.f), s.arr);
//	fprintf(stdout,"%d %f %s\n", s.n, s.f, s.arr);
//
//
//	return 0;
//}


#include<stdio.h>
typedef struct S
{
	int n;
	float f;
	char str[20];
}S;
int main()
{
	//序列化和反序列化的时候
	char arr[200];
	S s = { 100,6.9f,"hellobit" };
	//把一个结构体转换成字符串
	sprintf(arr, "%d %f %s",s.n,s.f,s.str);
	printf("字符串的数据：%s\n", arr);
	//把一个字符串转化成对应的格式化数据
	S temp = { 0 };
	sscanf(arr,"%d %f %s", &(temp.n), &(temp.f), temp.str);
	printf("格式化后的数据为：%d %f %s\n", temp.n, temp.f, temp.str);

	return 0;
}