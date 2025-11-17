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
    if (list->head == NULL || list == NULL)
    {
        return;
    }
    struct Node* temp = list->head;
    while ((temp != NULL))
    {
        temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
    list->head = NULL;
    list->tail = NULL;
    list->lenght = 0; 
}
size_t dlist_size(Dlist *list)
{
    if (list != NULL)
    {
        return list->lenght;
    }
}
struct Node* get_nodes(Dlist *list,int id)//内部函数,返回第id个节点
{
    if (id < 0 || id > list->lenght)
    {
        return NULL;
    }
    struct Node* temp = list->head;
    for (size_t i = 0; i < id; i++)
    {
        temp = temp->next;
    }
    return temp;
}
Singtype dlist_get(Dlist *list,int id)
{
    if (list != NULL)
    {
        struct Node* n = get_nodes(list,id);
        if (n != NULL)
        {
            return n->data;
        }
    }
}
void dlist_set(Dlist *list,int id,Singtype num)
{
    if (list != NULL)
    {
        struct Node* n = get_nodes(list,id);
        if (n != NULL)
        {
            n->data = num;
        }
    }
}
void dlist_add(Dlist *list,int id,Singtype num)
{

}
Singtype dlist_remove(Dlist *list,int id)
{

}
int dlist_index(Dlist *list,Singtype num)
{
    if (list != NULL)
    {
        struct Node* temp = list->head;
        for (size_t i = 0; i < list->lenght; i++,temp = temp->next)
        {
            if (temp->data == num)
            {
                return i;
            }
        }
        return -1;
    }
}
void dlist_push_front(Dlist *list,Singtype num)
{
    struct Node*temp = malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return;
    }
    temp->next = list->head;
    temp->data = num;
    list->head = temp;
}
void dlist_push_back(Dlist *list,Singtype num)
{

}
void dlist_pop_front(Dlist *list)
{

}
void dlist_pop_back(Dlist *list)
{

}