#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"
Seqlist::Seqlist(int num = 10)//构造函数,创建对象时自动调用,创建一个能存num个数据的线性表
{
    m_num = 0;
    m_capacity = num;
    m_data = (Seqtype *)malloc(sizeof(Seqtype)*num);
}
Seqlist::~Seqlist()//析构函数,销毁时自动调用
{
}
void slist_clear(Slist *list)//清空线性表内的元素
{
    if (list == NULL)//检查传入指针是否为空
    {
        printf("pointer is null\n");
        return;
    }
    list->num = 0;//将元素个数设置为0
}
size_t slist_size(Slist *list)//获取线性表内具有的元素个数
{
    if (list == NULL)//检查传入指针是否为空
    {
        printf("pointer is null\n");
        return 0;
    }
    return list->num;//返回线性表的num值,num值记录元素个数
}
size_t slist_capacity(Slist *list)//获取线性表内具有的元素个数
{
    if (list == NULL)//检查传入指针是否为空
    {
        printf("pointer is null\n");
        return 0;
    }
    return list->capacity;//返回线性表的capacity值,capacity值记录最大容量
}
Seqtype slist_get(Slist *list,int id)//查找id位置的元素的值
{
    if (list != NULL && list->data != NULL && id >= 0 && id < list->num)//判断传入的list和id是否符合条件
    {
        return list->data[id];//返回id处的元素
    }
    exit(0);
}
void slist_set(Slist *list,int id,Seqtype d)//将id处的值设置为d
{
    if (list != NULL && list->data != NULL && id >= 0 && id < list->capacity)//判断传入的list和id是否符合条件
    {
        list->data[id] = d;
    }
    if (list->num < id)//如果线性表记录的元素个数小于设置处的个数,则直接将id设置为长度
    {
        list->num = id+1;
    }
}
void slist_insert(Slist *list,int id,Seqtype d)//在id处插入值d,其他元素顺势后移
{
    Seqtype *temp = list->data;//创建一个临时数据指针,用来处理所有的操作
    if (list != NULL && list->data != NULL && id >= 0 && id < list->capacity)//判断传入的list和id是否符合条件
        if (list -> capacity < list-> num + 1)//如果原数据表的容量小于插入元素后的容量,则执行扩容代码
        {
            list->capacity *= 2;//将扩容后的容量设置为原先的两倍
            temp = malloc(sizeof(Seqtype)*(list->capacity));//对temp进行空间的分配,完成后面的扩容操作
            if (temp == NULL)//检查是否分配成功
            {
                printf("not enough memory\n");
                exit(0);
            }
            for (size_t i = 0; i < list->num; i++)//进行元素复制 
            {
            temp[i] = list->data[i];
            }
            free(list->data);//释放原来的data的内存
            list->data = temp;//将temp中的赋值给list以完成扩容操作
        }
        for (size_t i = list->num; i > id; i--)//将包括id在内的后面的元素向后进行移动
        {
        list->data[i] = list->data[i - 1];
        }
        list->data[id] = d;//在id处插入d
        list->num += 1;//完成后将num+1
}
Seqtype slist_remove(Slist *list,int id)//删除id处的元素,并返回元素的内容
{
    if (list != NULL && list->data != NULL && id >= 0 && id < list->num)////判断传入的list和id是否符合条件
    {
        Seqtype res = list->data[id];//创建一个变量存储id处的元素
        for (size_t i = id + 1;i < list->num;i++)//将id后面的元素向前移动
        {
            list->data[i-1] = list->data[i];
        }
        list->num -= 1;//完成后将num-1
        return  res;//返回id处的元素
    }
}
int slist_index(Slist *list,Seqtype key)//查找元素为key的id
{
    for (size_t i = 0;i < list->num;i++)//循环查找,具体查找方法可以进行替换
    {
        if (list->data[i] == key)
        {
            return i;//查找成功则返回对应地id
        }
    }
    return -1;//如果key不存在则返回-1
}