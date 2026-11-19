#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "stdlib.h"
#include "../include/filter.h"
#include "../include/arrays.h"

int main()
{
    int p, n;
    double *h;

    printf("Enter the order: ");

    if (scanf("%d", &p) != 1)
    {
        printf("Enter valid order!\r\n");
        return -1;
    }

    if (p <= 0)
    {
        printf("Error: order is less or equal to 0!\r\n");
        return -1;
    }

    h = calloc(p + 1, sizeof(double));

    if (h == NULL)
    {
        printf("Unable to create H-array");
        return -1;
    }

    printf("Enter the coefficients:\r\n");

    for (int i = 0; i < p + 1; i++)
    {
        if (scanf("%lf", &h[i]) != 1)
        {
            printf("Enter valid number to H[%d]!\r\n", i);
            return -1;
        }
    }

    printf("Enter the N-coeff: ");

    if (scanf("%d", &n) != 1)
    {
        printf("Enter valid N-th digit!\r\n");
        return -1;
    }

    if (n < 0)
    {
        printf("Error: N-th digit is less than 0!\r\n");
        return -1;
    }

    printf("Enter the input digits:\r\n");

    double x = 0.0;
    for (int i = 0; i <= n; i++)
    {
        printf("X[%d] = ", i);

        if (scanf("%lf", &x) != 1)
        {
            printf("Enter valid number to X[%d]!\r\n", i);
            return -1;
        }

        int err_code = 0;
        double y = continuous_fir(x, h, p, &err_code);

        if (err_code != 0)
        {
            printf("There was an error after FIR had been called: %d\r\n", err_code);
            return -1;
        }

        printf("\tY[%d] = %lf\r\n", i, y);
    }

    printf("Order: %d\nN-coeff: %d\r\n", p, n);
    printf("H-array: ");
    print_array(h, p + 1);

    free(h);

    return 0;
}