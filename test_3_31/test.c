#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
////c�����ļ�����
//int main()
//{	//���ļ�
//  //���·��
//	FILE* pf = fopen("C:\\Users\\luoluo\\OneDrive\\����\\test.txt","w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//��/д�ļ�
//
//	//�ر��ļ�
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}



//#include<stdio.h>
////c�����ļ�����
////fputc-д�ļ�
//int main()
//{	//���ļ�
//	FILE* pf = fopen("test.txt","w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//��/д�ļ�
//	int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		fputc('a' + i, pf);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}

//#include<stdio.h>
//
////fgetc-���ļ�����
//int main()
//{
//	//���ļ�
//	file* pf = fopen("test.txt", "r");
//	if (pf == null)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	int ch = 0;
//	int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		ch = fgetc(pf);
//		printf("%c ", ch);
//	}
//	
//	//�ر��ļ�
//	fclose(pf);
//	pf == null;
//	return 0;
//}

//#include<stdio.h>
//
////fputs-дһ������
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fputs("hello bit\n", pf);
//	fputs("hello world\n", pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include<stdio.h>
//
////fgets-��һ������
//
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	char arr[20];
//	fgets(arr, 10, pf);
//	printf("%s\n", arr);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include<stdio.h>
//
////��ʽ���Ķ�д
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
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//��д�ļ�
//	fprintf(pf,"%s %f %d\n", s.arr, s.f, s.n);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//����fscanf����

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
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//���ļ�
	fscanf(pf, "%s %f %d", s.arr, &(s.f), &(s.n));
	printf("%s %f %d\n", s.arr, s.f, s.n);
	//�ر��ļ�
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
	//���л��ͷ����л���ʱ��
	char arr[200];
	S s = { 100,6.9f,"hellobit" };
	//��һ���ṹ��ת�����ַ���
	sprintf(arr, "%d %f %s",s.n,s.f,s.str);
	printf("�ַ��������ݣ�%s\n", arr);
	//��һ���ַ���ת���ɶ�Ӧ�ĸ�ʽ������
	S temp = { 0 };
	sscanf(arr,"%d %f %s", &(temp.n), &(temp.f), temp.str);
	printf("��ʽ���������Ϊ��%d %f %s\n", temp.n, temp.f, temp.str);

	return 0;
}