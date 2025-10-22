//斐波那契数列,递归实现
#include <stdio.h>
int fibonacci(int n)
{
    if (n == 2)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 0;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    int a = 0;
    scanf("%d",&a);
    printf("数列的%d项为%d",a,fibonacci(a));
    return 0;
}