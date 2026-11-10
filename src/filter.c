#include "../include/filter.h"

double FIR(int n, unsigned int p, char use_default_pre_x, char use_default_x,
           const double *pre_x, size_t pre_x_size,
           const double *x, size_t x_size,
           const double *h, size_t h_size,
           int *err_code)
{
    if (h_size < 1)
    {
        *err_code = ZERO_ORDER;
        return 0.0f;
    }

    if (p != h_size - 1)
    {
        *err_code = BAD_ORDER;
        return 0.0f;
    }

    if (!use_default_pre_x && abs(n - h_size + 2) > pre_x_size)
    {
        *err_code = INDEX_OUT_OF_BOUNDS_ERROR;
        return 0.0f;
    }

    if (!use_default_x && n >= x_size)
    {
        *err_code = INDEX_OUT_OF_BOUNDS_ERROR;
        return 0.0f;
    }

    double result = 0.0;
    for (int i = 0; i < h_size; i++)
    {
        int offset = n - i;
        if (offset < 0 && use_default_pre_x)
        {
            continue;
        }
        else if (offset < 0 && !use_default_pre_x)
        {
            result += h[i] * pre_x[abs(offset + 1)];
            continue;
        }

        if (offset >= x_size && use_default_x)
        {
            continue;
        }

        result += h[i] * x[n - i];
    }

    return result;
}