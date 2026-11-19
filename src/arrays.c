#include "arrays.h"
#include <stdio.h>

void print_array(const double *arr, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}