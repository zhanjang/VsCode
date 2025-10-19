//版本3.0.0,选择排序算法,每次循环最前面的数与后面的依次比较,若满足条件,则记录对应下标,本轮循环结束时进行赋值转换
#include <stdio.h>
int main()
{
int a[8] = {12,37,25,24,10,69,58,23};
int len,j,i,t;
len = sizeof(a)/sizeof(int);
for(j = 0;j <= len-2;j++)
{
    int min_num = j;
    for(i = j +1;i <= len - 1;i++)
    {
        if(a[min_num]>a[i])
        {
            min_num = i;
        }
    }
    t = a[j];
    a[j] = a[min_num];
    a[min_num] = t;
}
printf("num\n");
for (i = 1;i<=len;i++)
{
    printf("%d = %d\n",i,a[i-1]);
}
return 0;
}