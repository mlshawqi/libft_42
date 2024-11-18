#include "libftprintf.h"

void ft_pointer(void *ptr, int *count)
{
    unsigned long addr = (unsigned long)ptr;

    *count += write(1, "0x", 2);

    if (addr == 0) {
        *count += write(1, "0", 1);
    } else {
        ft_hexalow(addr, count);
    }
}
