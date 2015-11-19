#include "../include/w_algorithm.h"

unsigned short w_rev_word(unsigned short w)
{
    unsigned short rev_w = 0;
    unsigned short mask = 0x00FF;
    unsigned char temp_b;
    
    temp_b = w & mask;
    rev_w += temp_b;
    
    rev_w <<= 8;
    mask <<= 8;
    
    temp_b = (unsigned char)((w & mask) >> 8);
    rev_w += temp_b;
    
    return rev_w;
}

unsigned int w_rev_dword(unsigned int d)
{
    unsigned int rev_d = 0;
    unsigned int mask = 0x000000FF;
    unsigned char temp_b;
    
    temp_b = d & mask;
    rev_d += temp_b;
    
    rev_d <<= 8;
    mask <<= 8;
    
    temp_b = (unsigned char)((d & mask) >> 8);
    rev_d += temp_b;
    
    rev_d <<= 8;
    mask <<= 8;
    
    temp_b = (unsigned char)((d & mask) >> 16);
    rev_d += temp_b;
    
    rev_d <<= 8;
    mask <<= 8;
    
    temp_b = (unsigned char)((d & mask) >> 24);
    rev_d += temp_b;
    
    return rev_d;
}

void w_swap(void **a, void **b)
{
    void *temp = *a;
    *a = *b;
    *b = temp;
}

void w_bubble_sort(int *arr, int size, int is_asc)
{
    int i = 0, j = 0;
    for (i = 1; i < size; i++)
    {
        for (j = size-1; j >= i; j--)
        {
            if (is_asc ? (arr[j-1] > arr[j]) : (arr[j-1] < arr[j]))
                w_swap(&arr[j-1], &arr[j]);
        }
    }
}
