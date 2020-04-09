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
    if (t != NULL)
    {
        method_data* data = alloc_method_data(50);
        ticker* tic = alloc_ticker();

        if (tic == NULL || data == NULL)
            return NULL;
        
        strcpy(data->name, "Neville Method");
        double result = 0;
        double ellapsed_time = 0;
        int iterations = 0;

        start(tic);
        int n = get_length(t);
        double Q[n][n];
        double xi = 0;
        double xi_j = 0;

        for(int i = 0; i < n; i++)
            Q[i][0] = get_y(t, i);

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                xi = get_x(t, i);
                xi_j = get_x(t, i - j);
                Q[i][j] = ((((x - xi_j) * Q[i][j - 1]) - ((x - xi) * Q[i - 1][j - 1])) / (xi - xi_j));
                iterations++;
            }
        }
        end(tic);

        ellapsed_time = spent_time(tic);
        result = Q[n - 1][n - 1];
        set_method_data(data, result, ellapsed_time, iterations);
        
        return data;
    }
    return NULL;
}

method_data* divided_differences(table* t, double x)
{
    if (t != NULL)
    {
        method_data* data = alloc_method_data(50);
        ticker* tic = alloc_ticker();

        if (tic == NULL || data == NULL)
            return NULL;
        
        strcpy(data->name, "Divided Differences Method");
        double result = 0;
        double ellapsed_time = 0;
        int iterations = 0;

        start(tic);
        int n = get_length(t);
        double F[n][n];

        for(int i = 0; i < n; i++)
            F[i][0] = get_y(t, i);

        for(int i = 1; i < n; i++)
        {
            double product = 1;
            for(int j = 1; j <= i; j++)
            {
                F[i][j] = ((F[i][j - 1] - F[i - 1][j - 1]) / (get_x(t, i) - get_x(t, i - j)));
                product *= (x - get_x(t, j - 1));
                if (i == j)
                    result += (F[i][i] * product);
                iterations++;
            }
        }
        end(tic);

        ellapsed_time = spent_time(tic);
        result += F[0][0];
        set_method_data(data, result, ellapsed_time, iterations);
        
        return data;
    }
    return NULL;
}

method_data* hermite(table* t1, table* t2, double x)
{
    if (t1 != NULL && t2 != NULL && get_length(t1) == get_length(t2))
    {
        method_data* data = alloc_method_data(50);
        ticker* tic = alloc_ticker();

        if (tic == NULL || data == NULL)
            return NULL;
        
        strcpy(data->name, "Hermite Method");
        double result = 0;
        double ellapsed_time = 0;
        int iterations = 0;

        start(tic);
        int n = get_length(t1);
        double Q[2*n][2*n];
        double Z[2*n];

        for(int i = 0; i < n; i++)
        {
            Z[2 * i] = get_x(t1, i);
            Z[(2 * i) + 1] = get_x(t1, i);

            Q[2 * i][0] = get_y(t1, i);
            Q[(2 * i) + 1][0] = get_y(t1, i);

            if (i != 0)
                Q[2 * i][1] = ((Q[2 * i][0] - Q[(2 * i) - 1][0]) / (Z[2 * i] - Z[(2 * i) - 1]));
            Q[(2 * i) + 1][1] = get_y(t2, i);
        }

        int current_x = 0;
        double product = x - get_x(t1, 0);
        for (int i = 2; i < 2 * n; i++)
        {
            if (i % 2 != 0)
                current_x = i / 2;
            product *= (x - get_x(t1, current_x));
            for (int j = 2; j <= i; j++)
            {
                Q[i][j] = ((Q[i][j - 1] - Q[i - 1][j - 1]) / (Z[i] - Z[i - j]));
                if (i == j)
                    result += (Q[i][j] * product);
                iterations++;
            }
        }
        end(tic);

        ellapsed_time = spent_time(tic);
        result += (Q[0][0] + Q[1][1] * (x - get_x(t1, 0)));
        set_method_data(data, result, ellapsed_time, iterations);
        
        return data;
    }
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