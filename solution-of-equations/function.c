#include <stdlib.h>
#include "function.h"

struct parameters
{
    double* c;
    int n;
};

parameters* alloc_parameters(int n)
{
    parameters* p = (parameters*)calloc(1, sizeof(parameters)); 
    if (p != NULL)
    {
        p->c = (double*)calloc(n, sizeof(double));
        p->n = n;
    }
    return p;
}

void free_parameters(parameters* p)
{
    if (p != NULL)
        free(p->c);
    free(p);
}

double* get_coefficients(parameters* p)
{
    return p->c;
}

int get_length(parameters* p)
{
    return p->n;
}