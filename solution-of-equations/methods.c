#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "methods.h"
#include "function.h"

#define K 100000
#define E 0.000001

double* find_range(function* fun)
{
    double* range = calloc(2, sizeof(double));
    int i = -100;
    while(i < 100)
    {
        double eval_i = eval(fun, i);
        double eval_next_i = eval(fun, i + 1);
        if ((eval_i >= 0 && eval_next_i <= 0) || (eval_i <= 0 && eval_next_i >= 0))
        {
            range[0] = i;
            range[1] = i + 1;
            return range;
        }
        i++;
    }
    return NULL;
}

double bissection(function* f)
{
    if (f == NULL)
        return DBL_MAX;

    double* range = find_range(f);
    double result;

    if (range == NULL)
        return DBL_MAX;

    if (eval(f, range[0]) == 0)
    {
        result = range[0];
        free(range);
        return result;
    }
    
    if (eval(f, range[1]) == 0)
    {
        result = range[1];
        free(range);
        return result;
    }

    int i = 0;
    double a = range[0];
    double b = range[1];
    double m = (a + b) / 2;
    double last_m;
    do
    {
        last_m = m; 
        if((eval(f, m) * eval(f, a)) < 0)
            b = m;
        else
            a = m;
        m = (a + b) / 2;
        i++;
    } while (fabs((m - last_m)/m) > E && i < K);

    result = m;
    free(range);
    return result;
}

double fixed_point(function* f)
{
    if (f == NULL)
        return DBL_MAX;
        
    double* range = find_range(f);
    double result;

    if (range == NULL)
        return DBL_MAX;

    if (eval(f, range[0]) == 0)
    {
        result = range[0];
        free(range);
        return result;
    }
    
    if (eval(f, range[1]) == 0)
    {
        result = range[1];
        free(range);
        return result;
    }

    int i = 0;
    double m;
    double last_m = (range[0] + range[1]) / 2;
    while (i < K)
    {
        m = eval_fixed(f, last_m);
        if (fabs(m - last_m) <= E)
            i = K;
        last_m = m;
        i++;
    }

    free(range);
    return m;
}

double newton_method(function* f)
{
    return DBL_MAX;
}

double secant_method(function* f)
{
    return DBL_MAX;
}

double false_position(function* f)
{
    return DBL_MAX;
}

double steffensen_method(function* f)
{
    return DBL_MAX;
}

double horner_method(function* f)
{
    return DBL_MAX;
}

double muller_method(function* f)
{
    return DBL_MAX;
}