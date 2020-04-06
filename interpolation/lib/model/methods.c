#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include <ticker.h>
#include "methods.h"

#define K 100000
#define E 0.000001

struct method_data
{
    char* name;
    double result;
    double ellapsed_time;
    int iterations;
};

method_data* alloc_method_data(int name_length)
{
    method_data* data = (method_data*)calloc(1, sizeof(method_data));
    if (data != NULL)
    {
        data->name = (char*)calloc(name_length, sizeof(char));
        return data;
    }
    return NULL;
}

void free_method_data(method_data* data)
{
    if (data != NULL)
    {
        free(data->name);
        free(data);
    }
}

char* get_name(method_data* data)
{
    if (data != NULL)
        return data->name;
    return NULL;
}

double get_result(method_data* data)
{
    if (data != NULL)
        return data->result;
    return 0;
}

double get_ellapsed_time(method_data* data)
{
    if (data != NULL)
        return data->ellapsed_time;
    return 0;
}

int get_iterations(method_data* data)
{
    if (data != NULL)
        return data->iterations;
    return 0;
}

void set_method_data(method_data* data, double result, double ellapsed_time, int iterations)
{
    if (data != NULL)
    {
        data->result = result;
        data->ellapsed_time = ellapsed_time;
        data->iterations = iterations;
    }
}

double lagrange_function(table* t, int k, double x)
{
    if (t != NULL && k >= 0 && k < get_length(t))
    {
        double result = 1;
        double xi = 0;
        double xk = get_x(t, k);
        int n = get_length(t);

        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                xi = get_x(t, i);
                result *= ((x - xi) / (xk - xi));
            }
        }

        return result;
    }
    return DBL_MAX;
}

method_data* lagrange(table* t, double x)
{
    if (t != NULL)
    {
        method_data* data = alloc_method_data(50);
        ticker* tic = alloc_ticker();

        if (tic == NULL || data == NULL)
            return NULL;
        
        strcpy(data->name, "Lagrange Method");
        double result = 0;
        double ellapsed_time = 0;
        int i = 0;

        start(tic);
        double yi = 0;
        int n = get_length(t);

        while (i < n)
        {
            yi = get_y(t, i);
            result += (yi * lagrange_function(t, i, x));
            i++;
        }
        end(tic);

        ellapsed_time = spent_time(tic);
        set_method_data(data, result, ellapsed_time, i);
        
        return data;
    }
    return NULL;
}

method_data* neville(table* t, double x)
{
    return NULL;
}

method_data* divided_differences(table* t, double x)
{
    return NULL;
}

method_data* hermite(table* t, double x)
{
    return NULL;
}

method_data* natural_cubic_spline(table* t, double x)
{
    return NULL;
}

method_data* clamped_cubic_spline(table* t, double x)
{
    return NULL;
}