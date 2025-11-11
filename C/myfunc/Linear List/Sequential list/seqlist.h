#ifndef SEQLIST_H
#define SEQLIST_H
typedef struct Seqlist Slist;
struct Seqlist
{
    unsigned int num;//线性表具有的元素个数
    unsigned int capacity;//线性表能存储的元素个数
    void *data;//线性表的首元素地址
};
Slist* initialize(int element_count,int element_size);//创建一个线性表,并返回线性表的地址,element_count表示元素个数,element_size表示元素大小
#endif