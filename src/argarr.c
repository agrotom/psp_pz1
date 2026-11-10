#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/argarr.h"

int parse_array(const char *str, double *arr, int max_size)
{
    if (str == NULL || arr == NULL || max_size <= 0)
        return -1;

    int count = 0;
    const char *p = str;

    while (*p != '\0')
    {
        if (count >= max_size)
            return -1;

        char *end;
        errno = 0;

        double value = strtod(p, &end);

        if (end == p || errno == ERANGE)
            return -1;

        arr[count++] = value;

        if (*end == '\0')
            return count;

        if (*end != ',')
            return -1;

        p = end + 1;

        if (*p == '\0')
            return -1;
    }

    return count;
}

void print_array(const double *arr, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}