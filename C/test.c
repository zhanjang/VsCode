#include<stdio.h>
int Add(int x,int y)
{
    int z = x + y;
    return z;
}
int main()
{
    int a,b; 
    scanf("%d %d",&a,&b);
    int d = Add(a,b);
    printf("%d",d);
}