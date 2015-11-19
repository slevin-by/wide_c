#ifndef _W_DBG_H_
#define _W_DBG_H_

#ifdef _MSC_VER
#define SET_BP  \
    __asm { \
        int 3 \
    }
#else
#define SET_BP  asm("int $3");
#endif // _MSC_VER

#endif // _W_DBG_H_
