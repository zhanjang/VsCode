//预处理命令,在编译之前处理
//包括引入头文件,宏定义,条件编译三种
#include <stdio.h>//引入头文件
#define PI 3.14//宏定义常量
#define area(r) ((PI)*(r)*(r))//宏定义函数
int main()
{
    printf("%f",area(2));
    return 0;
}