#define _CRT_SECURE_NO_WARNINGS 1

////�����Ƶ�д�ļ� - fwrite
//#include<stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { "pengge",18,99.9f };
//	//���ļ�
//	FILE* pf = fopen("test.dat", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	fwrite(&s, sizeof(struct S), 1, pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


////fread - ���ļ�
//#include<stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = {0};
//	//���ļ�
//	FILE* pf = fopen("test.dat", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	fread(&s, sizeof(struct S), 1, pf);
//	printf("%s %d %f\n", s.name, s.age, s.score);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//p
//	ch = fgetc(pf);
//	printf("%c\n", ch);//e
//	ch = fgetc(pf);
//	printf("%c\n", ch);//n
//	ch = fgetc(pf);
//	printf("%c\n", ch);//g
//
//	//fseek(pf, -3, SEEK_CUR);
//	fseek(pf, 1, SEEK_SET);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//ϣ����������e
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//p
//	ch = fgetc(pf);
//	printf("%c\n", ch);//e
//	ch = fgetc(pf);
//	printf("%c\n", ch);//n
//	ch = fgetc(pf);
//	printf("%c\n", ch);//g
//
//	rewind(pf);
//	printf("%d\n", ftell(pf));
//	ch = fgetc(pf);
//	printf("%c\n", ch);//p
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include<stdio.h>
//#include <stdlib.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//	//���ļ�
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


#include <stdio.h>
#include <windows.h>

//VS2013 WIN10��������
int main()
{
	FILE* pf = fopen("test.txt", "w");
	fputs("abcdef", pf);//�Ƚ�����������������
	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
	Sleep(10000);
	printf("ˢ�»�����\n");
	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
	Sleep(10000);
	fclose(pf);
	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
	pf = NULL;
	return 0;
}
//
//
//

//#include<stdio.h>
//int main()
//{
//	//ʵ��һ�����룬����һ���ļ�
//	//���ļ�
//	//�򿪱������ļ�
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		perror("open file for read");
//		return 1;
//	}
//	//��Ҫд���ļ�
//	FILE* pfWrite = fopen("test2.txt", "w");
//	if (pfWrite == NULL)
//	{
//		fclose(pfRead);
//		pfRead = NULL;
//		pfRead = NULL;
//		perror("open file for write");
//		return 1;
//	}
//
//	//����
//	int ch = 0;
//	while ((ch=fgetc(pfRead)) != EOF)
//	{
//		fputc(ch,pfWrite);
//	}
//
//	//�ر��ļ�
//	fclose(pfRead);
//	pfRead = NULL;
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}
