#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	//��Ҫһ��3*3�Ķ�ά����������
	char board[3][3] = { 0 };
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
			//�������
			PlayerMove(board, ROW, COL);
			// ��ӡ����
			DisplayBoard(board, ROW, COL);
			// �ж���Ӯ
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
			//��������
			ComputerMove(board, ROW, COL);
			//��ӡ����
			DisplayBoard(board, ROW, COL);
			//�ж���Ӯ
			IsWin(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
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
void menu()
{
	printf("**************************\n");
	printf("********* 1.play *********\n");
	printf("********* 0.exit *********\n");
	printf("**************************\n");
}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!");
			break;
		default:
			printf("ѡ���������������!");
			break;
		}
	} while (input);
	return 0;
}