//结构体,存储多个类型的数据
#include <stdio.h>
//定义结构体
struct birthday
{
    int year;
    int month;
    int day;
};
struct stu
{
    int num;
    char name[6];
    char sex;
    struct birthday date;
} stu1 = {1,"lihua\0",'F'};//需要在结尾处定义结构体变量才能使用,类似面向对象的类和实例的关系
struct a
{
    int day;
} stu[2];//结构体数组,建立两个相同的结构体;
int main()
{
    stu1.date.year = 2007;//嵌套结构体通过多次访问来改写
    stu[0].day = 2;//结构体数组通过结构体的方式来访问并改写数据
    return 0;
}