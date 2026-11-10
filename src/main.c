#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "stdlib.h"
#include "../include/argarr.h"
#include "../include/filter.h"

#define MAX_SIZE 1024

double *create_array(size_t size)
{
    double *arr = malloc(size * sizeof(double));
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    return arr;
}

size_t read_array(double *arr)
{
    size_t count = 0;
    double a = 0;
    while (scanf("%lf", &a) == 1)
    {
        arr[count] = a;
        count++;
    }

    if (!feof(stdin))
    {
        scanf("%*s");
    }

    return count;
}

int main(int argc, char **argv)
{
    char default_x = 1, default_pre_x = 1;
    int opt;

    while ((opt = getopt(argc, argv, "p:x:")) != -1)
    {
        switch (opt)
        {
        case 'p':
            if (strcmp(optarg, "true") == 0)
            {
                default_pre_x = 1;
            }
            break;
        case 'x':
            if (strcmp(optarg, "true") == 0)
            {
                default_x = 1;
            }
            break;
        }
    }

    int p = 0;
    int n = 0;

    printf("Order (P): ");
    scanf("%d", &p);
    printf("n: ");
    scanf("%d", &n);

    size_t pre_x_size, x_size, h_size;
    double *pre_x, *x, *h;

    pre_x = create_array(MAX_SIZE);
    x = create_array(MAX_SIZE);
    h = create_array(MAX_SIZE);

    printf("Enter pre_x array:\n");
    pre_x_size = read_array(pre_x);
    printf("Enter x array:\n");
    x_size = read_array(x);
    printf("Enter h array:\n");
    h_size = read_array(h);

    printf("Initial values\n");
    printf("\tUse default pre_x: %d\n", default_pre_x);
    printf("\tUse default x: %d\n", default_x);
    printf("\tP \t= %d\n", p);
    printf("\tN \t= %d\n", p - 1);
    printf("\tPre x array (%ld): ", pre_x_size);
    print_array(pre_x, pre_x_size);
    printf("\tX array (%ld): ", x_size);
    print_array(x, x_size);
    printf("\tH array (%ld): ", h_size);
    print_array(h, h_size);

    int error = 0;

    double y = FIR(n, p, default_pre_x, default_x, pre_x, pre_x_size, x, x_size, h, h_size, &error);

    if (error != 0)
    {
        printf("error: %d\n", error);
        exit(error);
    }
    else
    {
        printf("\tY[%d] \t= %lf\n", n, y);
    }

    return 0;
}