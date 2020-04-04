#include <math.h>
#include <stdio.h>
#include "equations.h"

double polynomial(double x, fconfig* c)
{
    double y = 0;
    double* v = get_values(c);
    int length = get_values_length(c);
    for (int i = 0; i < length; i++)
        y += (v[i] * pow(x, length - i - 1));
    return y;
}