#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"
Slist* initialize(int element_count, int element_size)
{
    Slist *list = malloc(sizeof(Slist));
    if (list == NULL)
    {
        printf("not enough memory for list structre");
        exit(0);
    }
    
    list->capacity = element_count;
    list->num = 0;
    list->data = malloc(element_count * element_size);
    if (list->data == NULL) {
        printf("not enough memory for data");
        free(list);
        exit(0);
    }
    return list;
}