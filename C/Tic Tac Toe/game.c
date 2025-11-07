#include <stdio.h>
#include "ifgame.h"
char chess[3][3];
void reset_board(char n[][3])//重置棋盘函数
{
    int i = 0,j = 0;
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            n[i][j] = ' ';
        } 
    }
}
int play(int player,char a)
{
    int n1 = 0,m1 = 0,clear = 0,n2 = 0,m2 = 0;
    for (n1 = 0;n1< 3;n1++)
    {
        for (m1 = 0; m1 < 3;m1++)
        {
            printf("%c ",chess[n1][m1]);
        }
        printf("\n");
    }
    while ((clear = getchar()) != '\n' && clear != EOF);//清理缓存区
    printf("输入你要下的位置");
    scanf("(%d,%d)",&n2,&m2);
    if (chess[n2-1][m2-1] == ' ')
    {
        chess[n2-1][m2-1] = a;
        ifgame(chess);
        return !player;
    }
    else
    {
        printf("该位置已被占用!\n");
        return player;
    }
}
int main()
{
    int player = 0;
    reset_board(chess);
    while (id)//游戏主体
    {
        if(player == 0)
        {
            player = play(player,'X');
        }
        else if(player == 1)
        {
            player = play(player,'O');
        }
    }
}