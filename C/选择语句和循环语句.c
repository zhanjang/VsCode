#include <stdio.h>
//选择语句
int main()
{
    int num1 = 0;
    scanf("%d",num1);
    if (num1 > 0)
    {
        printf("非零\n");
    }
    else
    {
        printf("零或负数\n");
    }
//循环语句
    int num2 = 0;
    scanf("%d",num2);
    while (num2 > 0)
    {
        printf("num2=%d\n", num2);
        num2--;
    }
}