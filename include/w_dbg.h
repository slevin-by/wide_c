#ifndef _W_DBG_H_
#define _W_DBG_H_

#ifdef __unix__
#define SET_BP  asm("int $3");
#else
#define SET_BP  \
    __asm { \
        int 3 \
    }
#endif // __unix__

#endif // _W_DBG_H_
