#ifndef W_OS_H
#define W_OS_H

#include <windows.h>

#ifdef _MSC_VER

#include <windows.h>

typedef HANDLE      w_handle_t;
typedef HANDLE      w_thread_t;
//typedef LPTHREAD_START_ROUTINE (w_thread_callback_t)(LPVOID);
typedef DWORD (__stdcall *w_thread_callback_t)(LPVOID);

#define w_thread_join(thread)   WaitForSingleObject(thread, INFINITE)
#define w_thread_exit(value)    ExitThread(value)

#define __w_inline

#else

#include <pthread.h>

typedef void *      w_handle_t;
typedef pthread_t   w_thread_t;
typedef void *(*w_thread_callback_t)(void *);

#define w_thread_join(thread)   pthread_join(thread, 0)
#define w_thread_exit(value)    pthread_exit(value)

#define __w_inline  inline

#endif // _MSC_VER

typedef struct w_mutex_t {
    w_handle_t mutex;
    int is_locked;
} w_mutex_t;

w_mutex_t w_mutex_create(void);
void w_mutex_destroy(w_mutex_t *);

void w_mutex_lock(w_mutex_t *);
void w_mutex_unlock(w_mutex_t *);

w_handle_t w_thread_create(w_thread_t *, w_thread_callback_t, void *);

#endif // W_OS_H

