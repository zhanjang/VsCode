#ifndef SEQLIST_H
#define SEQLIST_H
typedef struct Seqlist Slist;
typedef int Seqtype;
struct Seqlist
{
    size_t num;//线性表具有的元素个数
    size_t capacity;//线性表能存储的元素个数
    Seqtype *data;//线性表的首元素地址
};
Slist* initialize(int element_count);//创建一个线性表,并返回线性表的地址,element_count表示元素个数
void del_list(Slist* list);//删除一个线性表,list表示线性表的地址
void clear_all_data(Slist *list);//将线性表的元素个数清空
size_t size(Slist *list);//查询线性表的元素个数
Seqtype get(Slist *list,int id);//获取线性表中第i个元素
#endif