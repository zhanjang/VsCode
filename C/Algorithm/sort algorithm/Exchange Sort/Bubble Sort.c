//冒泡排序,逐个比较,每次比较完后若满足条件立刻进行大小调换,每完成一轮次比较
#include <stdio.h>
int main()
{
    int a[8] = {12,37,25,24,10,69,58,23};
    int len,i,j,t;
    len = sizeof(a)/sizeof(int);
    for (j = 1;j<len-1;j++)
    {
        for (i = 0;i<=len-j;i++)
        {
            if (a[i]>a[i+1])
            {
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
    }
    printf("num\n");
    for (i = 1;i<=len;i++)
    {
        printf("%d = %d\n",i,a[i-1]);
    }
    return 0;
}