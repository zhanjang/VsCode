#ifndef SEQLIST_H
#define SEQLIST_H
/*检查头文件是否被引入,反正反复引用*/
typedef struct Seqlist Slist;
typedef int Seqtype;//方便后续进行元素类型的替换
struct Seqlist
{
    size_t num;//线性表具有的元素个数
    size_t capacity;//线性表能存储的元素个数
    Seqtype *data;//线性表的首元素地址
};
Slist* slist_creat(int element_count);//创建一个线性表,并返回线性表的地址,element_count表示元素个数
void slist_destroy(Slist* list);//删除一个线性表,list表示线性表的地址
void slist_clear(Slist *list);//将线性表的元素个数清空
size_t slist_size(Slist *list);//查询线性表的元素个数
size_t slist_capacity(Slist *list);//查询线性表的最大容量
Seqtype slist_get(Slist *list,int id);//获取线性表中第i个元素
void slist_set(Slist *list,int id,Seqtype d);//将第id位置的元素设置为d
void slist_insert(Slist *list,int id,Seqtype d);//在id位置插入元素d
Seqtype slist_remove(Slist *list,int id);//删除id位置的元素,并返回这个元素值
int slist_index(Slist *list,Seqtype key);//返回值为key的位置
#endif