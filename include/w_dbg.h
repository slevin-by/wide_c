#ifndef _W_DBG_H_
#define _W_DBG_H_

#ifdef _MSC_VER
#ifdef _WIN64
#include <Windows.h>
#define SET_BP  DebugBreak()
#else
#define SET_BP  __asm int 3
#endif // _WIN64
#else
#define SET_BP  asm("int $3");
#endif // _MSC_VER

#endif // _W_DBG_H_
