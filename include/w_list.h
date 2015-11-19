#ifndef _LIST_ELEMENT_
#define _LIST_ELEMENT_

typedef struct list_t {
    void *data;
    struct list_t *next;
    struct list_t *prev;
    int isEmpty;
    int size;
} List;

extern List *w_list_create(void);
extern void w_list_destroy(List *list);

extern void w_list_copy_attr(List **dst, List *src);

extern void w_list_add_first(List **list, void *data);
extern void w_list_add_last(List **list, void *data);

extern void w_list_remove_data(List **list, void *data);
extern void w_list_remove_at(List **list, int i);

extern void *w_list_get_at(List **list, int i);
extern int w_list_find_data(List **list, void *data);

extern void w_list_print(List *list);

#endif // _LIST_ELEMENT_
