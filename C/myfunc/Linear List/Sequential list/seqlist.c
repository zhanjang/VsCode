#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"
Slist* slist_creat(int element_count)
{
    Slist *list = malloc(sizeof(Slist));
    if (list == NULL)//检查list是否创建成功
    {
        printf("not enough memory for list structre\n");
        return NULL;
    }
    list->capacity = element_count;
    list->num = 0;
    list->data = malloc(element_count*sizeof(Seqtype));
    if (list->data == NULL)//检查data是否创建成功
    {
        printf("not enough memory for data\n");
        free(list);//如果失败则释放list的内存并返回NULL
        return NULL;
    }
    return list;
}
void slist_destroy(Slist* list)
{
    if (list == NULL)
    {
        printf("pointer is null\n");
        return;
    }
    list->capacity = 0;
    list->num = 0;
    free(list->data);
    list->data = NULL;
    free(list);
}
void slist_clear(Slist *list)
{
    if (list == NULL)
    {
        printf("pointer is null\n");
        return;
    }
    list->num = 0;
}
size_t slist_size(Slist *list)
{
    if (list == NULL)
    {
        printf("pointer is null\n");
        return 0;
    }
    return list->num;
}
Seqtype slist_get(Slist *list,int id)
{
    if (list != NULL && list->data != NULL && id >= 0 && id < list->num)
    {
        return list->data[id];
    }
    exit(0);
}
void slist_set(Slist *list,int id,Seqtype d)
{
    if (list != NULL && list->data != NULL && id >= 0 && id < list->num)
    {
        list->data[id] = d;
    }
}
void slist_insert(Slist *list,int id,Seqtype d)
{
    Seqtype *temp = list->data;
    if (list != NULL && list->data != NULL && id >= 0 && id < list->num)
        if (list -> capacity < list-> num + 1)
        {
            list->capacity *= 2;
            temp = malloc(sizeof(Seqtype)*(list->capacity));
            if (temp == NULL)
            {
                printf("not enough memory\n");
                exit(0);
            }
            for (size_t i = 0; i < list->num; i++) 
            {
            temp[i] = list->data[i];
            }
            free(list->data);
            list->data = temp;
        }
        for (size_t i = list->num; i > id; i--) 
        {
        list->data[i] = list->data[i - 1];
        }
        list->data[id] = d;
        list->num += 1;
}
Seqtype slist_remove(Slist *list,int id)
{
    if (list != NULL && list->data != NULL && id >= 0 && id < list->num)
    {
        Seqtype res = list->data[id];
        for (size_t i = id + 1;i < list->num;i++)
        {
            list->data[i-1] = list->data[i];
        }
        list->num -= 1;
        return  res;
    }
}
int slist_index(Slist *list,Seqtype key)
{
    for (size_t i = 0;i < list->num;i++)
    {
        if (list->data[i] == key)
        {
            return i;
        }
    }
    return -1;
}