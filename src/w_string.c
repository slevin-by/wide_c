#include "../include/w_string.h"
#include <stdlib.h>
#include <string.h>

String *w_string_create_void(void)
{
    String *str = (String *)calloc(1, sizeof(String));
    str->data = (char *)calloc(256, sizeof(char));
    str->isEmpty = 1;
    str->size = 255;
    str->reserved = 0;
}

String *w_string_create(char *s)
{
    int len = strlen(s);

    String *str = (String *)calloc(1, sizeof(String));
    str->data = (char *)calloc(len+1, sizeof(char));
    str->isEmpty = 1;
    str->size = len;
    str->reserved = len;

    strcpy(str->data, s);

    return str;
}

void w_string_destroy(String *s)
{
    if (s)
        free(s);
}

void w_string_append(String *s, char c)
{
    if (s->reserved < s->size)
    {
        s->data[s->reserved] = c;
        ++(s->reserved);
    }
    else
    {
        s->data = (char *)realloc(s->data, 2 * (s->size + 1) * sizeof(char));

        if (s->reserved == 0)
            memset(s->data, 0, s->size);

        s->data[s->reserved] = c;
        s->size += 1;
        s->size *= 2;
        ++(s->reserved);
    }

    s->isEmpty = 0;
}

void w_string_concat(String *s, char *c_str)
{
    int len = strlen(c_str);
    if (!((s->size - s->reserved) > len))
    {
        s->size += (len + 1);
        s->data = (char *)realloc(s->data, s->size * sizeof(char));
    }

    strcat(s->data, c_str);
    s->isEmpty = 0;
    s->reserved += len;
}

void w_string_assign(String *s, char *c_str)
{
    int len = strlen(c_str);
    if (s->size <= len)
    {
        s->size += (len + 1);
        s->reserved = len;
        s->data = (char *)realloc(s->data, s->size * sizeof(char));
    }

    memset(s->data, 0, s->size);
    strcpy(s->data, c_str);
}

char *w_string_get(String *s)
{
    char *ret = (char *)calloc(s->size+1, sizeof(char));
    memcpy(ret, s->data, (s->size-1) * sizeof(char));
    return ret;
    //memcpy_s(ret, s->size, s->data, s->size);
}

char w_string_get_at(String *s, int i)
{
    if (i >= 0 && i < s->reserved && !s->isEmpty)
        return s->data[i];
    return NULL;
}

int w_string_set_at(String *s, int i, char c)
{
    if (i >= 0 && i < s->reserved)
    {
        s->data[i] = c;
        s->isEmpty = 0;
        return 1;
    }
    else
        return 0;
}
