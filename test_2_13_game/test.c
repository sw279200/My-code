#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"



void menu()
{
	printf("**************************\n");
	printf("******* 0.�˳���Ϸ *******\n");
	printf("******* 1.ɨ����Ϸ *******\n");
	printf("**************************\n");
}

void game()
{
	//������������ֱ�������
	char mine[ROWS][COLS] = { 0 };//������Ų����׵���Ϣ������
	char show[ROWS][COLS] = { 0 };//��������Ų��׵���Ϣ������
	//��ʼ���Ų��׵�����
	InitBoard(mine, ROWS, COLS,'0');
	//��ʼ�������׵�����
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	PrintBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);

	//����
	RemoveMine(mine,show,ROW,COL);

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
			game();
			break;
		default:
			printf("ѡ���������������!\n");
		}
	}while (input);
	return 0;
}