#include "../include/w_os.h"
#include "../include/w_types.h"
#include <stdlib.h>

w_mutex_t w_mutex_create()
{
    w_mutex_t mutex = {
        .mutex = W_NULL,
        .is_locked = W_FALSE
    };

#ifdef _MSC_VER
    char name[256];
    memset(name, 0, 256 * sizeof(char));
    strcpy(name, "mutex_");
    strcat(name, __LINE__);

    mutex.mutex = CreateMutexA(NULL, 0, name);
#else
    pthread_mutex_init(&(mutex.mutex), W_NULL);
#endif // _MSC_VER

    return mutex;
}

__w_inline void w_mutex_destroy(w_mutex_t *mutex)
{
#ifndef _MSC_VER
    pthread_mutex_destroy(&(mutex->mutex));
#endif // _MSC_VER
    memset(mutex, W_NULL, sizeof(*mutex));
}

__w_inline w_handle_t w_thread_create(w_thread_t *thread, w_thread_callback_t w_callback, void *arg)
{
#ifdef _MSC_VER
    thread = CreateThread(W_NULL, 0, w_callback, arg, 0, W_NULL);
    return EXPR_TO_BOOL(thread);
#else
    return (w_handle_t)pthread_create(thread, W_NULL, w_callback, arg);
#endif // _MSC_VER
}

__w_inline void w_mutex_lock(w_mutex_t *m)
{
#ifdef _MSC_VER
    WaitForSingleObject(m->mutex, INFINITE);
#else
    pthread_mutex_lock(&(m->mutex));
#endif // _MSC_VER
}

__w_inline void w_mutex_unlock(w_mutex_t *m)
{
#ifdef _MSC_VER
    ReleaseMutex(m->mutex);
#else
    pthread_mutex_unlock(&(m->mutex));
#endif // _MSC_VER
}
