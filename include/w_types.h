#ifndef _COMMON_H_
#define _COMMON_H_

#define EXPR_TO_BOOL(expr)  (expr != 0)

#define TRUE	1
#define FALSE	0

typedef signed char           int8_t;
typedef signed short          int16_t;
typedef signed int            int32_t;
typedef signed long long      int64_t;

typedef unsigned char           uint8_t;
typedef unsigned short          uint16_t;
typedef unsigned int            uint32_t;
typedef unsigned long long      uint64_t;

typedef unsigned char       byte_t;
typedef unsigned short      word_t;
typedef unsigned long       dword_t;
typedef unsigned long long  qword_t;

#endif // _COMMON_H_
