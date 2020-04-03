#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "methods.h"
#include "function.h"
#include "ticker.h"

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

method_data* bissection(function* f)
{
    method_data* data = alloc_method_data(50);
    double result = 0;
    double ellapsed_time = 0;
    int i = 0;

    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0 || data == NULL)
        return NULL;

    strcpy(data->name, "Bissection Method");
    set_method_data(data, result, 0, i);
    if (state == 1)
        return data;
    
    ticker* t = alloc_ticker();
    if (t != NULL)
    {
        start(t);
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
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, m, ellapsed_time, i);

        free_ticker(t);
    }

    free(range);
    return data;
}

method_data* fixed_point(function* f)
{
    method_data* data = alloc_method_data(50);
    double result = 0;
    double ellapsed_time = 0;
    int i = 0;

    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0 || data == NULL)
        return NULL;
    strcpy(data->name, "Fixed Point Method");
    set_method_data(data, result, 0, i);
    if (state == 1)
        return data;

    ticker * t = alloc_ticker();
    if (t != NULL)
    {
        start(t);
        double m;
        double last_m = (range[0] + range[1]) / 2;
        while (i < K)
        {
            m = eval_fixed(f, last_m);
            if (fabs(m - last_m) <= E)
                break;
            last_m = m;
            i++;
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, m, ellapsed_time, i);

        free_ticker(t);
    }

    free(range);
    return data;
}

method_data* newton_method(function* f)
{
    method_data* data = alloc_method_data(50);
    double result = 0;
    double ellapsed_time = 0;
    int i = 0;

    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0 || data == NULL)
        return NULL;
    strcpy(data->name, "Newton Method");
    set_method_data(data, result, 0, i);
    if (state == 1)
        return data;
 
    ticker* t = alloc_ticker();
    if (t != NULL)
    {
        start(t);
        double m;
        double last_m = (range[0] + range[1]) / 2;
        while (i < K)
        {
            m = last_m - (eval(f, last_m) / eval_diff(f, last_m, 1));
            if (fabs(m - last_m) <= E)
                break;
            last_m = m;
            i++;
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, m, ellapsed_time, i);

        free_ticker(t);
    }
    
    free(range);
    return data;
}

method_data* secant_method(function* f)
{
    method_data* data = alloc_method_data(50);
    double result;
    double ellapsed_time;
    int i = 0;

    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0 || data == NULL)
        return NULL;
    strcpy(data->name, "Secant Method");
    set_method_data(data, result, 0, i);
    if (state == 1)
        return data;

    ticker* t = alloc_ticker();
    if (t != NULL)
    {
        start(t);
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
                break;
            p0 = p1;
            q0 = q1;
            p1 = p;
            q1 = eval(f, p);
            i++;
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, p, ellapsed_time, i);

        free_ticker(t);
    }

    free(range);
    return data;
}

method_data* false_position(function* f)
{
    method_data* data = alloc_method_data(50);
    double result;
    double ellapsed_time;
    int i = 0;

    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0 || data == NULL)
        return NULL;
    strcpy(data->name, "False Position Method");
    set_method_data(data, result, 0, i);
    if (state == 1)
        return data;

    ticker* t = alloc_ticker();
    if (t != NULL)
    {
        start(t);
        double half_interval = (range[1] - range[0]) / 2;
        double p = (range[0] + range[1]) / 2;
        double p0 = p - (half_interval / 2);
        double p1 = p + (half_interval / 2);
        double q;
        double q0 = eval(f, p0);
        double q1 = eval(f, p1);
        
        while (i < K)
        {
            p = p1 - ((q1 * (p1 - p0)) / (q1 - q0));
            if (fabs(p - p1) <= E)
                break;
            q = eval(f, p);
            if (q * q1 < 0)
            {
                p0 = p1;
                q0 = q1;
            }
            p1 = p;
            q1 = q;
            i++;
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, p, ellapsed_time, i);

        free_ticker(t);
    }

    free(range);
    return data;
}

method_data* steffensen_method(function* f)
{
    method_data* data = alloc_method_data(50);
    double result;
    double ellapsed_time;
    int i = 0;

    double* range = find_range(f);
    int state = test_range(f, range, &result);

    if (state == 0 || data == NULL)
        return NULL;
    strcpy(data->name, "Steffensen Method");
    set_method_data(data, result, 0, i);
    if (state == 1)
        return data;

    ticker* t = alloc_ticker();
    if (t != NULL)
    {
        start(t);
        double p;
        double p0 = (range[0] + range[1]) / 2;
        double p1;
        double p2;
        while (i < K)
        {
            p1 = eval_fixed(f, p0);
            p2 = eval_fixed(f, p1);
            p = p0 - (pow(p1 - p0, 2) / (p2 - (2 * p1) + p0));
            if (fabs(p - p0) <= E)
                break;
            p0 = p;
            i++;
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, p, ellapsed_time, i);

        free_ticker(t);
    }
    
    free(range);
    return data;
}

method_data* horner_method(function* f)
{
    return NULL;
}

method_data* muller_method(function* f)
{
    return NULL;
}