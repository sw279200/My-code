#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game2.h"
#include"game3.h"
void menu()
{
	printf("**************************\n");
	printf("******* 0.�˳���Ϸ *******\n");
	printf("******* 1.������   *******\n");
	printf("******* 2.������   *******\n");
	printf("******* 3.ɨ��     *******\n");
	printf("**************************\n");
}

void game1()
{
	int num = 0;
	int ret = rand() % 100 + 1;//�õ�һ��1-100������� 
	while (1)
	{
		printf("��¸����֣�>");
		scanf("%d", &num);
		if (num > ret)
		{
			printf("�´���!\n");
		}
		else if (num < ret)
		{
			printf("��С��!\n");
		}
		else
		{
			printf("��ϲ�㣡�¶��ˣ�\n");
			break;
		}
	}

}
void game2()
{
	//��Ҫһ��3*3�Ķ�ά����������
	char board[3][3] = { 0 };
	//��ʼ������
	initBoard(board,Row,Col);
	//��ӡ����
	DisplayBoard(board, Row, Col);
	char ret = 0;
	while (1)
	{
		//�������
		PlayerMove(board, Row, Col);
		// ��ӡ����
		DisplayBoard(board, Row, Col);
		// �ж���Ӯ
		ret = IsWin(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, Row, Col);
		//��ӡ����
		DisplayBoard(board, Row, Col);
		//�ж���Ӯ
		IsWin(board, Row, Col);
		ret = IsWin(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("��ϲ���ʤ����\n");

	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}
void game3()
{
	//������������ֱ�������
	char mine[ROWS][COLS] = { 0 };//������Ų����׵���Ϣ������
	char show[ROWS][COLS] = { 0 };//��������Ų��׵���Ϣ������
	//��ʼ���Ų��׵�����
	InitBoard(mine, ROWS, COLS, '0');
	//��ʼ�������׵�����
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	PrintBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);

	//����
	RemoveMine(mine, show, ROW, COL);

}
int main()
{

	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 3:
			game3();
		default:
			printf("ѡ���������������!\n");
		}
	} while (input);
	return 0;
}