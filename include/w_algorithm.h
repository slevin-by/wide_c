#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

unsigned short w_rev_word(unsigned short w);
unsigned int w_rev_dword(unsigned int d);
unsigned long long w_rev_qword(unsigned long long q);

void w_swap(void **a, void **b);

#define W_SORT_ASC  1
#define W_SORT_DESC 0

void w_bubble_sort(int *arr, int size, int is_asc);

#endif // _ALGORITHM_H_
