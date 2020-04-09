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
    double* result;
    double ellapsed_time;
    int iterations;
    int result_size;
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

double* get_result(method_data* data)
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

int get_result_size(method_data* data)
{
    if (data != NULL)
        return data->result_size;
    return 0;
}

void set_method_data(method_data* data, double* result, double ellapsed_time, int iterations)
{
    if (data != NULL)
    {
        data->result = result;
        data->ellapsed_time = ellapsed_time;
        data->iterations = iterations;
    }
}

method_data* gauss(matrix* m)
{
    return NULL;
}

method_data* gauss_partial(matrix* m)
{
    return NULL;
}

method_data* gauss_scaled(matrix* m)
{
    return NULL;
}