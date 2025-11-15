#include <stdlib.h>
#include <stdio.h>
#include "singlist.h"
Dlist* dlist_creat()
{
    Dlist* list = malloc(sizeof(struct Singlist));
    if (list == NULL)
    {
        printf("not enough memory for list structre\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->lenght = 0;
    return list;
}
void dlist_destory(Dlist *list)
{
    if (list == NULL)
    {
        return;
    }
    dlist_clear(list);
    free(list);
}
void dlist_clear(Dlist *list)
{
    if (list->head == NULL)
    {
        return;
    }
    while ((list != NULL))
    {
        struct Node* temp = list->head->next;
        if (temp == NULL)
        {
            free(list->head);
            break;
        }
        else
        {
            free(list->head);
            list->head = temp;
        }
    }
    list->head = NULL;
    list->tail = NULL;
    list->lenght = 0; 
}