#include <stdio.h>
#ifndef SINGLIST_H
#define SINGLIST_H/*检查头文件是否被引入,防止反复引用*/
typedef struct Singlist Dlist;
struct Node
{
    Singtype data;//存储数据
    struct Node* next;//指向下一个链表
};
struct Singlist
{
    size_t lenght;//链表的长度
    struct Node* head;//链表的头部指针
    struct Node* tail;//链表的尾部指针
};
typedef int Singtype;//方便后续进行元素类型的替换
Dlist* dlist_creat();//创建一个单链表
void dlist_destory(Dlist *list);//删除一个单链表
void dlist_clear(Dlist *list);//清空单链表中的所有元素
size_t dlist_size(Dlist *list);//获取单链表的长度
Singtype dlist_get(Dlist *list,int id);//获取单链表中第id个元素
void dlist_set(Dlist *list,int id,Singtype num);//设置第id位的元素
void dlist_add(Dlist *list,int id,Singtype num);//在第id位插入一个元素
Singtype dlist_remove(Dlist *list,int id);//删除第id位的元素,并返回对应的值
int dlist_index(Dlist *list,Singtype num);//查找的第一个值位num的元素的位置,没找到返回-1
void dlist_push_front(Dlist *list,Singtype num);//在链表头插入元素
void dlist_push_back(Dlist *list,Singtype num);//在链表尾插入元素
void dlist_pop_front(Dlist *list);//删除第一个元素
void dlist_pop_back(Dlist *list);//删除最后一个元素
#endif