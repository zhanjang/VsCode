//结构体,存储多个类型的数据
#include <stdio.h>
//定义结构体
struct birthday
{
    int year;
    int month;
    int day;
};
struct stu//可以通过#pragma pack()来更改默认对齐大小
{
    int num;
    char name[6];
    char sex;
    struct birthday date;
} stu1 = {1,"lihua\0",'F'};//定义结构体变量,否则无法使用  方法1
struct stu stu2;//定义结构体变量  方法2
struct a
{
    int day;
} stu[2];//结构体数组,建立两个相同的结构体;
int main()
{
    printf("%d\n",sizeof(stu1.name));
    printf("%d\n",sizeof(stu1.num));
    printf("%d\n",sizeof(stu1.sex));
    printf("%d",sizeof(stu1.date));
    printf("%d",sizeof(stu1));//为24字节,与内存对齐有关,num占用0-3字节,name数组占用4-9字节,sex占用10字节,date为4字节对齐,故11字节填充,date占用12-23字节,故实际占用大小为24字节
    stu1.date.year = 2007;//嵌套结构体通过多次访问来改写
    stu[0].day = 2;//结构体数组通过结构体的方式来访问并改写数据
    return 0;
}
/*默认对齐大小无固定,通过平台和编译器两方来确定一般情况下为下面的值
对齐规则,意思是起始的内存编号必须是对应规则的整数倍,从0开始计算
char 1字节
short 2字节
int 4字节
long long 8字节
float 8字节
数组的对齐规矩和定义数组的类型有关
结构体的对齐规则为其内部数据中占用最大的一个
其中vscode平台下默认大小为8,与数据类型比较取小的为对齐标准*/