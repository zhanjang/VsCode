#include <stdio.h>
int main()
{
int a[8] = {12,37,25,24,10,69,58,23};
int len,i,j,t;
len = sizeof(a)/sizeof(int);
for (j = 1;j<=len-1;j++)
 for (i = 1;i<=len-j;i++)
    if (a[i]>a[i+1])
    {
        t = a[i];
        a[i] = a[i+1];
        a[i+1] = t;
    }
printf("num\n");
for (i = 1;i<=len;i++)
{
    printf("%d = %d\n",i,a[i-1]);
}
return 0;
}