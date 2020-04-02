#include <stdlib.h>
#include <float.h>
#include "function.h"

struct function
{
    formula f;
    fconfig* c;
};

struct fconfig
{
    double* values;
    int values_length;
};

fconfig* alloc_config(int length)
{
    fconfig* c = (fconfig*)calloc(1, sizeof(fconfig)); 
    if (c != NULL)
    {
        c->values = (double*)calloc(length, sizeof(double));
        c->values_length = length;
    }
    return c;
}

void free_config(fconfig* c)
{
    if (c != NULL)
        free(c->values);
    free(c);
}

function* alloc_function(formula f, int config_length)
{
    function* fun = (function*)calloc(1, sizeof(function));
    if (fun != NULL)
    {
        fun->f = f;
        fun->c = alloc_config(config_length);
    }
    return fun;
}

void free_function(function* fun)
{
    if (fun != NULL)
    {
        free_config(fun->c);
        free(fun);
    }
}

formula get_formula(function* fun)
{
    if (fun != NULL)
        return fun->f;
    return NULL;
}

fconfig* get_config(function* fun)
{
    if (fun != NULL)
        return fun->c;
    return NULL;
}

double eval(function* fun, double x)
{
    if (fun != NULL)
    {
        formula f = fun->f;
        fconfig* c = fun->c;
        return f(x, c);
    }
    return DBL_MAX; 
}

double eval_diff(function* fun, double p)
{
    double x = p - 0.000001;
    return (eval(fun, x) - eval(fun, p)) / (x - p);
}

double eval_fixed(function* fun, double x)
{
    return x - eval(fun, x);
}

double* get_values(fconfig* c)
{
    if (c != NULL)
        return c->values;
    return NULL;
}

int get_values_length(fconfig* c)
{
    return c->values_length;
}