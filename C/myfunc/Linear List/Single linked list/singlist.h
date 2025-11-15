#include <stdio.h>
#ifndef SINGLIST_H
#define SINGLIST_H/*检查头文件是否被引入,防止反复引用*/
typedef struct Singlist Dlist;
struct Singlist
{
    size_t lenght;//链表的长度
    struct Node* head;//链表的头部指针
    struct Node* tail;//链表的尾部指针
};
typedef int Signtype;//方便后续进行元素类型的替换
struct Node
{
    Signtype data;//存储数据
    struct Node* next;//指向下一个链表
};
Dlist* dlist_creat();//创建一个单链表
void dlist_destory(Dlist *list);//删除一个单链表
void dlist_clear(Dlist *list);//清空单链表中的所有元素
#endif