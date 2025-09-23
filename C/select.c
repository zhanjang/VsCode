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
        printf("这个是1\n");
        break;
    case 2:
        printf("这个是2\n");
        break;
    default:
        printf("不是1,也不是2\n");
        break;
    }
}
//while循环先判断条件再执行循环
int c(int num3)
{
    int i = 1,sum1 = 0;
        while (i <= num3)
    {
        sum1 += i;
        i++;
    }
    printf("1加到%d的结果为%d\n",num3,sum1);
}
//do while循环先执行循环再判读条件
int d(int num4)
{
    int g = 1,sum2 = 0;
    do
    {
        sum2 += g;
        g++;
    }
    while (g <= 100);
    printf("1加到%d的结果为%d\n",num4,sum2);
}
//for循环
int f(int num5)
{
    int h,sum3 = 0;
    for(h = 1/*初始表达式*/;h <= num5/*循环条件*/;h++/*更新表达式*/)
    {
        sum3 += h;
    }
    printf("结果为%d",sum3);
}
int main()
{
    int num1 = 0;
    scanf("%d",&num1);
    int num2 = 0;
    scanf("%d",&num2);
    int num3 = 0;
    scanf("%d",&num3);
    int num4 = 0;
    scanf("%d",&num4);
    int num5 = 0;
    scanf("%d",&num5);
    a(num1);
    b(num2);
    c(num3);
    d(num4);
    f(num5);
    return 0;
}