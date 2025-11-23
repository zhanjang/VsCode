#include <stdio.h>
#include <windows.h>
#include "seqlist.h"
int main()
{
    Slist *intp = slist_creat(10);
    for (size_t i = 0; i < 10; i++)
    {
        int a = 0;
        scanf("%d",&a);
        slist_set(intp,i,a);
    }
    printf("当前线性表长度%d,最大容量为%d\n",slist_size(intp),slist_capacity(intp));
    for (size_t z = 0; z < slist_size(intp); z++)
    {
        printf("第%d个元素为%d\n",z+1,slist_get(intp,z));
        Sleep(2000);
    }
    slist_insert(intp,5,100);
    printf("当前线性表长度%d,最大容量为%d\n",slist_size(intp),slist_capacity(intp));
    for (size_t z = 0; z < slist_size(intp); z++)
    {
        printf("第%d个元素为%d\n",z+1,slist_get(intp,z));
        Sleep(2000);
    }
    printf("删除的元素是第%d位的%d\n",5,slist_remove(intp,5));
    printf("当前线性表长度%d,最大容量为%d\n",slist_size(intp),slist_capacity(intp));
    for (size_t z = 0; z < slist_size(intp); z++)
    {
        printf("第%d个元素为%d\n",z+1,slist_get(intp,z));
        Sleep(2000);
    }
    printf("元素1的位置是%d",slist_index(intp,1));
    slist_destroy(intp);
    intp = NULL;
    return 0;
}