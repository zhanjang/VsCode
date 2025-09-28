#include <stdio.h>
enum weekday//定义枚举常量
{
    sun,mon,tue,wed,thu,fri,sar
}a1;//枚举变量定义方法类似
int main()
{
    a1 = mon;//枚举变量只能赋予枚举值,不能赋予枚举序号
    printf("%d",a1);//枚举提体的枚举值为int类型数据
    a1 = (enum weekday)3;//用枚举序号赋值需要转换数据类型
    printf("%d",a1);
}