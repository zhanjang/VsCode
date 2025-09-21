//分支结构
#include <stdio.h>
//if选择语句
int a(int num1)
{
    if (num1 > 0)
    {
        printf("非零\n");
    }
    else
    {
        printf("零或负数\n");
    }
}
//while循环
int b(int num2)
{
        while (num2 > 0)
    {
        printf("num2=%d\n", num2);
        num2--;
    }
}
int main()
{
    int num1 = 0;
    scanf("%d",&num1);
    int num2 = 0;
    scanf("%d",&num2);
    a(num1);
    b(num2);
}