#include "../include/w_list.h"
#include <stdio.h>
#include <stdlib.h>

List *createList(void)
{
    List *newList = (List *)malloc(sizeof(List));
    newList->data = newList->prev = newList->next = NULL;
    newList->isEmpty = TRUE;
    newList->size = 0;
    return newList;
}

void destroyList(List *list)
{
    if (list)
        free(list);
}

void copyListAttr(List **dst, List *src)
{
	(*dst)->isEmpty = src->isEmpty;
	(*dst)->size = src->size;
}

void addFirstToList(List **list, void *data)
{
    ++((*list)->size);
    
    if ((*list)->data == NULL && (*list)->prev == NULL && (*list)->next == NULL && (*list)->isEmpty)
    {
        (*list)->data = data;
        (*list)->isEmpty = FALSE;
        return;
    }
    
    List *newList = (List *)malloc(sizeof(List));
    newList->data = data;
    newList->prev = NULL;
    newList->next = *list;
    newList->size = (*list)->size;
    newList->isEmpty = (*list)->isEmpty;
    
    (*list)->prev = newList;
    *list = newList;
}

void addLastToList(List **list, void *data)
{
    ++((*list)->size);
    
    if ((*list)->data == NULL && (*list)->prev == NULL && (*list)->next == NULL && (*list)->isEmpty)
    {
        (*list)->data = data;
        (*list)->isEmpty = FALSE;
        return;
    }
    
    List *oldList  = *list;
    while ((*list)->next != NULL)
        (*list) = (*list)->next;
    
    List *newList = (List *)malloc(sizeof(List));
    newList->data = data;
    newList->prev = *list;
    newList->next = NULL;
    newList->size = (*list)->size;
    newList->isEmpty = (*list)->isEmpty;
    
    (*list)->next = newList;
    *list = oldList;
}


void removeFromList(List **list, void *data)
{
    if ((*list)->size == 0)
		return;

	List *head = (*list);

	while ((*list)->data != data && (*list))
	{
	    copyListAttr(&(*list)->next, (*list));
		(*list) = (*list)->next;
	}

	if (!(*list))
		return;

	if ((*list)->next == NULL && (*list)->prev)
	{
		List *tmpList = (*list);
		(*list)->prev->next = NULL;
		free(tmpList);
	}
	else if ((*list)->prev == NULL && (*list)->next)
	{
		(*list)->next->prev = NULL;
		head = (*list)->next;
	}
	else if ((*list)->prev == NULL && (*list)->next == NULL)
	{
		(*list)->isEmpty = 1;
		(*list)->data = NULL;
		(*list)->size = 0;
		return;
	}
	else
	{
		List *tmpList = (*list);
		(*list)->prev->next = (*list)->next;
		(*list)->next->prev = (*list)->prev;
		free(tmpList);
	}

	(*list) = head;
	(*list)->size--;
}

void removeFromListAt(List **list, int i)
{
    if (i < 0 || i >= (*list)->size)
		return NULL;

	List *head = *list;
	int currIndex = 0;
	while (currIndex != i && (*list))
	{
		copyListAttr(&(*list)->next, (*list));
		(*list) = (*list)->next;
		currIndex++;
	}

	removeFromList(&head, (*list)->data);
	(*list) = head;
}

void *getListDataAt(List **list, int i)
{
    if (i < 0 || i >= (*list)->size)
		return NULL;

	List *oldList = *list;
	int currIndex = 0;
	while (currIndex != i && (*list))
	{
		(*list) = (*list)->next;
		currIndex++;
	}

	void *ret = (*list)->data;

	(*list) = oldList;

	return ret;
}

int findInList(List **list, void *data)
{
    if ((*list)->isEmpty)
		return 0;
    
	List *oldList = *list;
	while (*list)
	{
	    if ((*list)->data == data)
			break;
		(*list) = (*list)->next;
	}
	
	int ret = 1;
	if (!(*list))
	    ret = 0;

	(*list) = oldList;

	return ret;
}

void printList(List *list)
{
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}
