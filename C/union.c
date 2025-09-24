#include <stdio.h>
//结构体
union a
{
    int num;
    char sha;
} b;
int main()
{
    b.num = 10;
    printf("%d\n",b.num);
    b.sha = 'a';//修改操作会影响前面的变量的存储结果
    printf("%d\n",b.num);
    printf("%c",b.sha);
    return 0;
}