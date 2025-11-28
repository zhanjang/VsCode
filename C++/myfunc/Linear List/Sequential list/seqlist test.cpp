#include <iostream>
#include <windows.h>
#include "seqlist.h"
int main()
{
    Seqlist intp(10);
    for (size_t i = 0; i < 10; i++)
    {
        int a = 0;
        std::cin>>a;
        intp.Set(i,a);
    }
    std::cout<<"当前线性表长度"<<intp.Size()<<",最大容量为"<<intp.Capacity()<<std::endl;
    for (size_t i = 0; i < intp.Size(); i++)
    {
        std::cout<<"第"<<i+1<<"个元素为"<<intp.Get(i)<<std::endl;
        Sleep(2000);
    }
    intp.Insert(5,100);
    std::cout<<"当前线性表长度"<<intp.Size()<<",最大容量为"<<intp.Capacity()<<std::endl;
    for (size_t i = 0; i < intp.Size(); i++)
    {
        std::cout<<"第"<<i+1<<"个元素为"<<intp.Get(i)<<std::endl;
        Sleep(2000);
    }
    std::cout<<"删除的元素是第"<<5<<"位的"<<intp.Remove(5)<<std::endl;
    std::cout<<"当前线性表长度"<<intp.Size()<<",最大容量为"<<intp.Capacity()<<std::endl;
    for (size_t i = 0; i < intp.Size(); i++)
    {
        std::cout<<"第"<<i+1<<"个元素为"<<intp.Get(i)<<std::endl;
        Sleep(2000);
    }
    std::cout<<"元素1的位置是"<<intp.Index(1);
    return 0;
}