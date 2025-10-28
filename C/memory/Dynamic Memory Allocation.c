//动态内存分配
//建立动态数组
#include <stdio.h>
#include <malloc.h>//动态内存函数的头文件
int main()
{
    int *p = NULL,num = 0;
    printf("输入数组大小:");
    scanf("%d",&num);
    p =(int*)malloc(sizeof(int)*num);//创建一个数组,大小为num 前面的(int*)为强制数据类型转换,函数返回为void*,需要转换后存储
    free(p);//释放内存
    p = NULL;//将p的指针绑定会NULL避免野指针等问题
}