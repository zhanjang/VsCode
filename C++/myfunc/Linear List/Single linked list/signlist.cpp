#include <stdlib.h>
#include <stdio.h>
#include "singlist.h"
static struct Node* get_nodes(Dlist *list,int id);
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
    list->length = 0;
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
    if (list == NULL || list->head == NULL)
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
    list->length = 0; 
}
size_t dlist_size(Dlist *list)
{
    if (list != NULL)
    {
        return list->length;
    }
}
struct Node* get_nodes(Dlist *list,int id)//内部函数,返回第id个节点
{
    if (id < 0 || id >= list->length)
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
    exit(0);
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
    if (list == NULL || id < 0 ||id > list->length)
    {
        return;
    }
    if (list->length == 0)
    {
        dlist_push_front(list,num);
    }
    else if (id == list->length)
    {
        dlist_push_back(list,num);
    }
    else
    {
        struct Node* temp = get_nodes(list,id-1);
        struct Node* new = malloc(sizeof(struct Node));
        new->data = num;
        new->next = temp->next;
        temp->next = new;
        list->length++;
    }
}
Singtype dlist_remove(Dlist *list,int id)
{
    if (list == NULL || id < 0 ||id > list->length)
    {
        exit(0);
    }
    Singtype node;
    if (id == 0)
    {
        node = list->head->data;
        dlist_pop_front(list);
    }
    else if (id == (list->length)-1)
    {
        node = list->tail->data;
        dlist_pop_back(list);
    }
    else
    {
        struct Node* temp = get_nodes(list,id-1);
        node = temp->next->data;
        struct Node* cur = temp->next;
        temp->next = cur->next;
        free(cur);
        list->length--;
    }
    return node;
}
int dlist_index(Dlist *list,Singtype num)
{
    if (list != NULL)
    {
        struct Node* temp = list->head;
        for (size_t i = 0; i < list->length; i++,temp = temp->next)
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
    if (list == NULL)
    {
        return;
    }
    struct Node*temp = malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return;
    }
    temp->next = list->head;
    temp->data = num;
    list->head = temp;
    if (list->length == 0)
    {
        list->tail = temp;
    }
    list->length++;
}
void dlist_push_back(Dlist *list,Singtype num)
{
    if (list == NULL)
    {
        return;
    }
struct Node*temp = malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return;
    }
    temp->next = NULL;
    temp->data = num;
    list->tail->next = temp;
    list->tail = temp;
    list->length++;
}
void dlist_pop_front(Dlist *list)
{
    if (list == NULL || list->length == 0)
    {
        return;
    }
    struct Node* temp = list->head;
    if (list->length == 1)
    {
        free(temp);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
    list->head = temp->next;
    free(temp);
    }
    list->length--;
}
void dlist_pop_back(Dlist *list)
{
    if (list == NULL || list->length == 0)
    {
        return;
    }
    struct Node* temp = list->head;
    if (list->length == 1)
    {
        free(temp);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        temp = get_nodes(list,(list->length)-2);
        list->tail = temp;
        free(temp->next);
        temp->next = NULL;
    }
    list->length--;
}