#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int x = 0;
int y = 0;

void menu()
{
    printf("****************************\n");
    printf("******1. 开始   0.退出******\n");
    printf("****************************\n");
    printf("请选择 :> ");

}

void PlayerMove(int board[ROW][COL], int who)
{
    while (1) {
        printf("\n玩家[%d] 请输入你需要下棋的位置:> ", who);
        scanf("%d %d", &x, &y);
        if (x<0 || y > COL) {
            printf("Postion Error!\n");
        }
        else if (board[x][y] != 0) {
            printf("Postion Is Occupied!\n");
        }
        else {
            board[x][y] = who;
            break;
        }
    }
}

int ChessCount(int board[ROW][COL], enum Dir d)
{
    int _x = x;
    int _y = y;

    int count = 0;
    while (1) {
        switch (d) {
        case LEFT:
            _y--;
            break;
        case RIGHT:
            _y++;
            break;
        case UP:
            _x--;
            break;
        case DOWN:
            _x++;
            break;
        case LEFT_UP:
            _x--, _y--;
            break;
        case RIGHT_DOWN:
            _x++, _y++;
            break;
        case RIGHT_UP:
            _x--, _y++;
            break;
        case LEFT_DOWN:
            _x++, _y--;
            break;
        }
        if (_x < 0 || _x > ROW - 1 || _y < 0 || _y > COL - 1) {
            break;
        }
        if (board[x][y] == board[_x][_y]) {
            count++;
        }
        else {
            break;
        }
    }
    return count;
}
int IsOver(int board[ROW][COL])
{
    int count1 = ChessCount(board, LEFT) + ChessCount(board, RIGHT) + 1;
    int count2 = ChessCount(board, UP) + ChessCount(board, DOWN) + 1;
    int count3 = ChessCount(board, LEFT_UP) + ChessCount(board, RIGHT_DOWN) + 1;
    int count4 = ChessCount(board, LEFT_DOWN) + ChessCount(board, RIGHT_UP) + 1;
    if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5) {
        if (board[x][y] == Player1) {
            return PLAYER1_WIN;
        }
        else {
            return PLAYER2_WIN;
        }
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == 0) {
                return CONTINUE;
            }
        }
    }
    return DROW;
}

void ShowChessBoard(int board[ROW][COL])
{
    printf("\033c");
    printf("玩家1——●\n");
    printf("玩家2——○\n");
    printf("\n\n  ");
    for (int i = 0; i < COL; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("%3d", i);
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == Player1) {
                //player1
                printf(" ●");
            }
            else if (board[i][j] == Player2) {
                //player2
                printf(" ○");
            } 
            else {
                //Space
                printf(" + ");
            }
        }
        printf("\n");
    }
}

void game()
{
    int chessboard[ROW][COL];
    memset(chessboard, '\0', sizeof(chessboard));
    int result = CONTINUE;
    do {
        ShowChessBoard(chessboard);
        PlayerMove(chessboard, Player1);
        result = IsOver(chessboard);
        if (CONTINUE != result) {
            break;
        }
        ShowChessBoard(chessboard);
        PlayerMove(chessboard, Player2);
        result = IsOver(chessboard);
        if (CONTINUE != result) {
            break;
        }
    } while (1);

    ShowChessBoard(chessboard);
    switch (result) {
    case PLAYER1_WIN:
        printf("恭喜玩家1获胜!\n");
        break;
    case PLAYER2_WIN:
        printf("恭喜玩家2获胜了!\n");
        break;
    case DROW:
        printf("平局，不服可以再战!\n");
        break;
        
    }
}