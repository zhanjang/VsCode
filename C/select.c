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
//switch case选择语句
int b(int num2)
{
    switch (num2)
    {
    case 1:
        printf("这个是1");
        break;
    case 2:
        printf("这个是2");
        break;
    default:
        printf("不是1,也不是2");
        break;
    }
}
//while循环
int c(int num3)
{
        while (num3 > 0)
    {
        printf("num3=%d\n", num3);
        num3--;
    }
}
int main()
{
    int num1 = 0;
    scanf("%d",&num1);
    int num2 = 0;
    scanf("%d",&num2);
    int num3 = 0;
    scanf("%d",&num3);
    a(num1);
    b(num2);
    c(num3);
}