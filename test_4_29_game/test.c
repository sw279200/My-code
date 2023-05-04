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
            printf("欢迎来到五子棋---玩家1vs玩家2\n");
            printf("祝您游戏愉快\n");
            game();
            break;
        case 0:
            printf("游戏已退出\n");
            break;
        default:
            printf("选择错误，请重新输入！\n");
            break;
        }
    } while (input);
    return 0;
}
