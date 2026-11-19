#include "../include/filter.h"

double FIR(int n, unsigned int p, char use_default_pre_x, char use_default_x,
           const double *pre_x, size_t pre_x_size,
           const double *x, size_t x_size,
           const double *h, size_t h_size,
           int *err_code)
{
    if (p != h_size - 1)
    {
        *err_code = BAD_ORDER_ERROR;
        return 0.0f;
    }

    if (h_size < 1)
    {
        *err_code = ZERO_ORDER_ERROR;
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

double continuous_fir(double x, double *h, size_t p, int *err_code)
{
    if (p == 0)
    {
        *err_code = ZERO_ORDER_ERROR;
    }

    static double x_arr[AT_X_SIZE] = {0};
    static size_t x_size = 0;

    x_arr[x_size] = x;

    double result = 0.0;
    for (int i = 0; i < p + 1; i++)
    {
        int offset = x_size - i;
        if (offset < 0)
        {
            continue;
        }

        result += h[i] * x_arr[offset];
    }

    x_size++;

    return result;
}