#ifndef _LIST_ELEMENT_
#define _LIST_ELEMENT_


typedef struct list_t {
    void *data;
    struct list_t *next;
    struct list_t *prev;
    int isEmpty;
    int size;
} List;

extern List *createList(void);
extern void destroyList(List *list);

extern void copyListAttr(List **dst, List *src);

extern void addFirstToList(List **list, void *data);
extern void addLastToList(List **list, void *data);

extern void removeFromList(List **list, void *data);
extern void removeFromListAt(List **list, int i);

extern void *getListDataAt(List **list, int i);
extern int findInList(List **list, void *data);

extern void printList(List *list);

#endif // _LIST_ELEMENT_