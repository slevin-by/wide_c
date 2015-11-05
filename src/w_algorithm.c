#include "../include/w_algorithm.h"

unsigned short revWord(unsigned short w)
{
    unsigned short rev_w = 0;
    unsigned short mask = 0x00FF;
    unsigned char temp_b;
    
    temp_b = w & mask;
    rev_w += temp_b;
    
    rev_w <<= 8;
    mask <<= 8;
    
    temp_b = (uint8_t)((w & mask) >> 8);
    rev_w += temp_b;
    
    return rev_w;
}

unsigned int revDWord(unsigned int d)
{
    unsigned int rev_d = 0;
    unsigned int mask = 0x000000FF;
    unsigned char temp_b;
    
    temp_b = d & mask;
    rev_d += temp_b;
    
    rev_d <<= 8;
    mask <<= 8;
    
    temp_b = (uint8_t)((d & mask) >> 8);
    rev_d += temp_b;
    
    rev_d <<= 8;
    mask <<= 8;
    
    temp_b = (uint8_t)((d & mask) >> 16);
    rev_d += temp_b;
    
    rev_d <<= 8;
    mask <<= 8;
    
    temp_b = (uint8_t)((d & mask) >> 24);
    rev_d += temp_b;
    
    return rev_d;
}
