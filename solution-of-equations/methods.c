#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "methods.h"
#include "function.h"

#define K 10000
#define E 0.000001

double* find_values(function* fun)
{
    double* values = calloc(2, sizeof(double));
    int i = -100;
    while(i < 100)
    {
        double eval_i = eval(fun, i);
        double eval_next_i = eval(fun, i + 1);
        if ((eval_i >= 0 && eval_next_i <= 0) || (eval_i <= 0 && eval_next_i >= 0))
        {
            values[0] = i;
            values[1] = i + 1;
            return values;
        }
        i++;
    }
    return NULL;
}

double bissection(function* fun)
{
    if (fun == NULL)
        return DBL_MAX;

    double* values = find_values(fun);
    double result;

    if (values == NULL)
        return DBL_MAX;

    if (eval(fun, values[0]) == 0)
    {
        result = values[0];
        free(values);
        return result;
    }
    
    if (eval(fun, values[1]) == 0)
    {
        result = values[1];
        free(values);
        return result;
    }

    int i = 0;
    double a = values[0];
    double b = values[1];
    double m = (a + b) / 2;
    double last_m;
    do
    {
        last_m = m; 
        if((eval(fun, m) * eval(fun, a)) < 0)
            b = m;
        else
            a = m;
        m = (a + b) / 2;
        i++;
    } while (fabs((m - last_m)/m) > E && i < K);

    result = m;
    free(values);
    return result;
}

double fixed_point(function* f_fixed, function* f_diff)
{
    if (f_fixed == NULL || f_diff == NULL)
        return DBL_MAX;
        
    int i = 0;
    double m;
    double last_m = 0;
    while (i < K)
    {
        m = eval(f_fixed, last_m);
        if (fabs(m - last_m) <= E)
            return m;
        last_m = m;
        i++;
    }
    return m;
}

double newton_method(function* f_diff)
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