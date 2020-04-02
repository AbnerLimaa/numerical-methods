#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "methods.h"
#include "function.h"

#define K 100000
#define E 0.000001

double* find_range(function* fun)
{
    if (fun != NULL)
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
    }
    return NULL;
}

int test_range(function* f, double* range, double* result)
{
    int state = 0;

    if (f != NULL && range != NULL)
    {
        if (eval(f, range[0]) == 0)
        {
            memcpy(result, &range[0], sizeof(double));
            free(range);
            state = 1;
        }
        else if (eval(f, range[1]) == 0)
        {
            memcpy(result, &range[1], sizeof(double));
            free(range);
            state = 1;
        }
        else
            state = 2;
    }

    return state;
}

double bissection(function* f)
{
    double result;
    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0)
        return DBL_MAX;
    if (state == 1)
        return result;
    
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
    double result;
    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0)
        return DBL_MAX;
    if (state == 1)
        return result;

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

    result = m;
    free(range);
    return result;
}

double newton_method(function* f)
{
    double result;
    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0)
        return DBL_MAX;
    if (state == 1)
        return result;

    int i = 0; 
    double m;
    double last_m = (range[0] + range[1]) / 2;
    while (i < K)
    {
        m = last_m - (eval(f, last_m) / eval_diff(f, last_m, 1));
        if (fabs(m - last_m) <= E)
            i = K;
        last_m = m;
        i++;
    }

    result = m;
    free(range);
    return result;
}

double secant_method(function* f)
{
    double result;
    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0)
        return DBL_MAX;
    if (state == 1)
        return result;

    int i = 0;
    double half_interval = (range[1] - range[0]) / 2;
    double p = (range[0] + range[1]) / 2;
    double p0 = p - (half_interval / 2);
    double p1 = p + (half_interval / 2);
    double q0 = eval(f, p0);
    double q1 = eval(f, p1);
    
    while (i < K)
    {
        p = p1 - ((q1 * (p1 - p0)) / (q1 - q0));
        if (fabs(p - p1) <= E)
            i = K;
        p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = eval(f, p);
        i++;
    }

    result = p;
    free(range);
    return result;
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