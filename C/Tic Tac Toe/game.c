#include <stdio.h>
#include "ifgame.h"
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
int main()
{
    int player = 1;
    char chess[3][3];
    reset_board(chess);
    while (id)//游戏主体
    {
        if(player == 1)
        {
            int n = 0,m = 0,clear = 0;
            for (n = 0;n< 3;n++)
            {
                for (m = 0; m < 3;m++)
                {
                    printf("%c ",chess[n][m]);
                }
                printf("\n");
            }
            while ((clear = getchar()) != '\n' && clear != EOF);//清理缓存区
            printf("输入你要下的位置");
            scanf("(%d,%d)",&n,&m);
            if (chess[n-1][m-1] == ' ')
            {
                chess[n-1][m-1] = 'X';
                ifgame(chess);
                player = 2;
            }
            else
            {
                printf("该位置已被占用!\n");
                player = 1;
            }
        }
        else if(player == 2)
        {
            int n = 0,m = 0,clear = 0;
            for (n = 0;n< 3;n++)
            {
                for (m = 0; m < 3;m++)
                {
                    printf("%c ",chess[n][m]);
                }
                printf("\n");
            }
            while ((clear = getchar()) != '\n' && clear != EOF);
            printf("输入你要下的位置");
            scanf("(%d,%d)",&n,&m);
            if (chess[n-1][m-1] == ' ')
            {
                chess[n-1][m-1] = 'O';
                ifgame(chess);
                player = 1;
            }
            else
            {
                printf("该位置已被占用!\n");
                player = 2;
            }          
        }
    }
}