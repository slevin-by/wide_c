#ifndef W_STRING_H
#define W_STRING_H

typedef struct string_t {
    char *data;
    int size;
    int reserved;
    int isEmpty;
} String;

extern String *w_string_create_void(void);
extern String *w_string_create(char *s);
extern void w_string_destroy(String *s);

extern void w_string_append(String *s, char c);
extern void w_string_concat(String *s, char *c_str);
extern void w_string_assign(String *s, char *c_str);

extern char *w_string_get(String *s);

extern char w_string_get_at(String *s, int i);
extern int w_string_set_at(String *s, int i, char c);

#endif // W_STRING_H

