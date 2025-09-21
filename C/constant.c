//常量
/*c中的常量需要声明有三种方式实现
	1.在变量前声明const(注此处为常变量即仍为变量只是不能更改数据内容与后面两种有本质区别)
	2.在函数之外使用define来定义
	3.enum定义枚举常量用法类似2
*/
#include <stdio.h>
#define MAX 100 //将MAX定义为常量值为100
enum Color
{
    red, //0
    green, //1
    blue //2
}; //枚举常量

int main()
{
    const int a = 10; //常变量,本质任然是变量,只是能更改
}