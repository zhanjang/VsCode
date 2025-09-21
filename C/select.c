//分支结构
#include <stdio.h>
int main()
{
    int num1 = 0;
    scanf("%d",&num1);
    int num2 = 0;
    scanf("%d",&num2);
    ifelse(num1);
    whilecontrl(num2);
}
int ifelse(int num1)
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
int whilecontrl(int num2)
{
        while (num2 > 0)
    {
        printf("num2=%d\n", num2);
        num2--;
    }
}