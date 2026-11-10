#pragma once

#include <stdlib.h>

#define N_X_SIZE_ERROR 1
#define INDEX_OUT_OF_BOUNDS_ERROR 2
#define BAD_ORDER 3
#define ZERO_ORDER 4

double FIR(int, unsigned int, char, char, const double *, size_t, const double *, size_t, const double *, size_t, int *);