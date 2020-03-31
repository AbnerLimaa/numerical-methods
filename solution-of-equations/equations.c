#include <math.h>
#include <stdio.h>
#include "equations.h"

double polinomial(double x, parameters* p)
{
    double y = 0;
    double* c = get_coefficients(p);
    int length = get_length(p);
    for (int i = 0; i < length; i++)
        y += (c[i] * pow(x, length - i - 1));
    return y;
}