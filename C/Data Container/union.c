#include <stdio.h>
//共用体,所有数据共用一块内存,内存大小等于共用体中长度最长的数据
union a//定义共用体
{
    int num;
    char sha;
} b1;//定义共用体变量
union a b2;//定义共用体变量
int main()
{
    b1.num = 10;
    printf("%d\n",b1.num);
    b1.sha = 'a';//修改操作会影响前面的变量的存储结果
    printf("%d\n",b1.num);
    printf("%c",b1.sha);
    return 0;
}