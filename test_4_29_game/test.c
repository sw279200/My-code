#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


int main()
{
    int input = 0;
    do
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("��ӭ����������---���1vs���2\n");
            printf("ף����Ϸ���\n");
            game();
            break;
        case 0:
            printf("��Ϸ���˳�\n");
            break;
        default:
            printf("ѡ��������������룡\n");
            break;
        }
    } while (input);
    return 0;
}
