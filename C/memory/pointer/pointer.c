//指针
#include <stdio.h>
//定义指针
int b = 6,*a = &b;
int main()
{
    printf("%d,%d,%#X\n",b,*a,a);//叫*号输出内存地址里面的内容,不加*号用x占位输出16进制的内存地址
    //指针的加减法
    int* a1;
    char* a2;
    float* a3;
    printf("a%#Xb%#Xc%#X\n",a1,a2,a3);//指针加减对内存地址进行操作,根据定义指针的类型进行操作,int 4字节,char 1字节,float 4字节
    a1++;a2++;a3++;
    printf("a%#Xb%#Xc%#X\n",a1,a2,a3);
    a1--;a2--;a3--;
    printf("a%#Xb%#Xc%#X\n",a1,a2,a3);
    int arr[] = {20,31,85,36};
    int* p = arr;//数组指针,数组本身就是一个内存地址,故没有取址符
    int len = sizeof(arr)/sizeof(int);//求数组长度,不能写成sizeof(p)/sizeof(int)p在这里代表的是它本身的长度,并非数组的长度
    //通过数组指针来遍历数组
    int i;
    for(i = 0;i<len;i++)
    {
        printf("%d\n",*(p+i));//此处加减为指针加减,故每次加自动跳4个字节
    }
}