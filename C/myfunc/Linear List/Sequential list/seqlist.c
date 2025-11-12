#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"
Slist* initialize(int element_count)
{
    Slist *list = malloc(sizeof(Slist));
    if (list == NULL)
    {
        printf("not enough memory for list structre");
        exit(0);
    }
    
    list->capacity = element_count;
    list->num = 0;
    list->data = malloc(element_count*sizeof(Seqtype));
    if (list->data == NULL) {
        printf("not enough memory for data");
        free(list);
        return NULL;
    }
    return list;
}
void del_list(Slist* list)
{
    if (list == NULL)
    {
        printf("pointer is null");
        return;
    }
    list->capacity = 0;
    list->num = 0;
    free(list->data);
    list->data = NULL;
    free(list);
}
void clear_all_data(Slist *list)
{
    if (list == NULL)
    {
        printf("pointer is null");
        return;
    }
    list->num = 0;
}
size_t size(Slist *list)
{
    if (list == NULL)
    {
        printf("pointer is null");
        return 0;
    }
    return list->num;
}
Seqtype get(Slist *list,int id)
{

}