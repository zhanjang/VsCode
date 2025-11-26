#include "singlist.h"
#include <stdio.h>
int main()
{
    Dlist *list = dlist_creat();
    for (size_t i = 0; i < 10; i++)
    {
        int temp = 0;
        scanf("%d",&temp);
        dlist_add(list,i,temp);
    }
    printf("当前长度%d",dlist_size(list));
    dlist_add(list,5,100);
    printf("当前长度%d",dlist_size(list));
    dlist_set(list,5,-1);
    printf("当前删除第%d个元素,元素值为%d",5,dlist_remove(list,5));
    printf("当前长度%d",dlist_size(list));
    printf("元素2的所在位置是%d",dlist_index(list,2));
    dlist_destory(list);
    list =NULL;
}