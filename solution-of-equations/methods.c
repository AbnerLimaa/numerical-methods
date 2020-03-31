#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "methods.h"

double* find_values(double (*fun)(double, parameters*), parameters* p)
{
    double* values = calloc(2, sizeof(double));
    int i = -100;
    while(i < 100)
    {
        if ((fun(i, p) >= 0 && fun(i + 1, p) <= 0) || (fun(i, p) <= 0 && fun(i + 1, p) >= 0))
        {
            values[0] = i;
            values[1] = i + 1;
            return values;
        }
        i++;
    }
    return NULL;
}

double bissection(double (*fun)(double, parameters*), parameters* p)
{
    double* values = find_values(fun, p);
    double result;
    if (values == NULL)
        return DBL_MAX;

    if (fun(values[0], p) == 0)
    {
        result = values[0];
        free(values);
        return result;
    }
    
    if (fun(values[1], p) == 0)
    {
        result = values[1];
        free(values);
        return result;
    }

    int i = 0;
    double e = 0.000001;
    double a = values[0];
    double b = values[1];
    double m = (a + b) / 2;
    double last_m;
    do
    {
        last_m = m; 
        if((fun(m, p) * fun(a, p)) < 0)
            b = m;
        else
            a = m;
        m = (a + b) / 2;
        i++;
    } while (fabs((m - last_m)/m) > e && i < 10000);

    result = m;
    free(values);
    return result;
}

double fixed_point(double (*fun)(double, parameters*), parameters* p)
{

}

double secant_method(double (*fun)(double, parameters*), parameters* p)
{

}

double false_position(double (*fun)(double, parameters*), parameters* p)
{

}

double steffensen_method(double (*fun)(double, parameters*), parameters* p)
{

}

double horner_method(double (*fun)(double, parameters*), parameters* p)
{

}

double muller_method(double (*fun)(double, parameters*), parameters* p)
{

}