#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include <ticker.h>
#include "methods.h"

#define N 10000
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

void set_method_data(method_data* data, double* result, double ellapsed_time, int iterations, int result_size)
{
    if (data != NULL)
    {
        data->result = result;
        data->ellapsed_time = ellapsed_time;
        data->iterations = iterations;
        data->result_size = result_size;
    }
}

double distance(double* v1, double* v2, int n)
{
    if (v1 != NULL && v2 != NULL)
    {
        double sum = 0;
        for(int i = 0; i < n; i++)
            sum += pow(v1[i] - v2[i], 2);
        return sqrt(sum);
    }
    return DBL_MAX;
}

method_data* gauss(matrix* m)
{
    if (m != NULL && get_width(m) == get_heigth(m) + 1)
    {
        method_data* data = alloc_method_data(50);
        ticker* t = alloc_ticker();
        if (data == NULL || t == NULL)
            return NULL;

        int w = get_width(m);
        int h = get_heigth(m);

        strcpy(data->name, "Gauss Method");
        double* result = (double*)calloc(w - 1, sizeof(double));
        double ellapsed_time = 0;
        int iterations = 0;
        int result_size = w - 1;

        start(t);
        for (int i = 0; i < h - 1; i++)
        {
            if (get(m, i, i) == 0)
            {
                int least = i + 1;
                double aji;
                for (int j = i + 2; j < h; j++)
                {
                    aji = get(m, j, i);
                    if ((aji != 0 && aji < get(m, least, i)) || get(m, least, i) == 0)
                        least = j;
                    iterations++;
                }
                if (get(m, least, i) != 0)
                    switch_lines(m, i, least);
                else
                {
                    free_ticker(t);
                    free_method_data(data);
                    return NULL;
                }
            }
            for (int j = i + 1; j < h; j++)
            {
                double mji = get(m, j, i) / get(m, i, i);
                eliminate(m, i, j, mji);
                iterations++;
            }
        }

        if (get(m, h - 1, w - 2) == 0)
        {
            free_ticker(t);
            free_method_data(data);
            return NULL;
        }

        result[w - 2] = get(m, h - 1, w - 1) / get(m, h - 1, w - 2);
        for(int i = w - 3; i >= 0; i--)
        {
            double sum = 0;
            for (int j = i + 1; j < w - 1; j++)
            {
                sum += (result[j] * get(m, i, j));
                iterations++;
            }
            result[i] = ((get(m, i, w - 1) - sum) / get(m, i, i));
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, result, ellapsed_time, iterations, result_size);

        free_ticker(t);
        return data;
    }
    return NULL;
}

method_data* gauss_partial(matrix* m)
{
    if (m != NULL && get_width(m) == get_heigth(m) + 1)
    {
        method_data* data = alloc_method_data(50);
        ticker* t = alloc_ticker();
        if (data == NULL || t == NULL)
            return NULL;

        int w = get_width(m);
        int h = get_heigth(m);

        strcpy(data->name, "Gauss Method With Partial Pivoting");
        double* result = (double*)calloc(w - 1, sizeof(double));
        double ellapsed_time = 0;
        int iterations = 0;
        int result_size = w - 1;

        start(t);
        for (int i = 0; i < h - 1; i++)
        {
            int greatest = i;
            double aji;
            for (int j = i + 1; j < h; j++)
            {
                aji = get(m, j, i);
                if (fabs(aji) > fabs(get(m, greatest, i)))
                    greatest = j;
                iterations++;
            }
            if (get(m, greatest, i) != 0)
                switch_lines(m, i, greatest);
            else
            {
                free_ticker(t);
                free_method_data(data);
                return NULL;
            }
            for (int j = i + 1; j < h; j++)
            {
                double mji = get(m, j, i) / get(m, i, i);
                eliminate(m, i, j, mji);
                iterations++;
            }
        }

        if (get(m, h - 1, w - 2) == 0)
        {
            free_ticker(t);
            free_method_data(data);
            return NULL;
        }

        result[w - 2] = get(m, h - 1, w - 1) / get(m, h - 1, w - 2);
        for(int i = w - 3; i >= 0; i--)
        {
            double sum = 0;
            for (int j = i + 1; j < w - 1; j++)
            {
                sum += (result[j] * get(m, i, j));
                iterations++;
            }
            result[i] = ((get(m, i, w - 1) - sum) / get(m, i, i));
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, result, ellapsed_time, iterations, result_size);

        free_ticker(t);
        return data;
    }
    return NULL;
}

method_data* gauss_scaled(matrix* m)
{
    if (m != NULL && get_width(m) == get_heigth(m) + 1)
    {
        method_data* data = alloc_method_data(50);
        ticker* t = alloc_ticker();
        if (data == NULL || t == NULL)
            return NULL;

        int w = get_width(m);
        int h = get_heigth(m);

        strcpy(data->name, "Gauss Method With Scaled Partial Pivoting");
        double* result = (double*)calloc(w - 1, sizeof(double));
        double ellapsed_time = 0;
        int iterations = 0;
        int result_size = w - 1;

        start(t);
        double S[h];
        for (int i = 0; i < h; i++)
        {
            double greatest = get(m, i, greatest);
            S[i] = greatest;
            for (int j = 0; j < w - 1; j++)
            {
                double aij = get(m, i, j);
                if (fabs(greatest) < fabs(aij))
                    S[i] = fabs(aij);
                iterations++;
            } 
        }

        for (int i = 0; i < h - 1; i++)
        {
            int greatest = i;
            double aji;
            for (int j = i + 1; j < h; j++)
            {
                aji = get(m, j, i);
                if ((fabs(aji) / S[j]) > (fabs(get(m, greatest, i) / S[greatest])))
                    greatest = j;
                iterations++;
            }
            if (get(m, greatest, i) != 0)
            {
                double aux = S[i];
                S[i] = S[greatest];
                S[greatest] = aux;
                switch_lines(m, i, greatest);
            }
            else
            {
                free_ticker(t);
                free_method_data(data);
                return NULL;
            }
            for (int j = i + 1; j < h; j++)
            {
                double mji = get(m, j, i) / get(m, i, i);
                eliminate(m, i, j, mji);
                iterations++;
            }
        }

        if (get(m, h - 1, w - 2) == 0)
        {
            free_ticker(t);
            free_method_data(data);
            return NULL;
        }

        result[w - 2] = get(m, h - 1, w - 1) / get(m, h - 1, w - 2);
        for(int i = w - 3; i >= 0; i--)
        {
            double sum = 0;
            for (int j = i + 1; j < w - 1; j++)
            {
                sum += (result[j] * get(m, i, j));
                iterations++;
            }
            result[i] = ((get(m, i, w - 1) - sum) / get(m, i, i));
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, result, ellapsed_time, iterations, result_size);

        free_ticker(t);
        return data;
    }
    return NULL;
}

method_data* jacobi(matrix* m)
{
    if (m != NULL && get_width(m) == get_heigth(m) + 1)
    {
        method_data* data = alloc_method_data(50);
        ticker* t = alloc_ticker();
        if (data == NULL || t == NULL)
            return NULL;

        int w = get_width(m);
        int h = get_heigth(m);

        strcpy(data->name, "Jacobi Method");
        double* result = (double*)calloc(h, sizeof(double));
        double ellapsed_time = 0;
        int iterations = 0;
        int result_size = h;

        start(t);
        int k = 0;
        double* x = (double*)calloc(h, sizeof(double));

        while (k < N)
        {
            for (int i = 0; i < h; i++)
            {
                double sum = 0;
                for (int j = 0; j < h; j++)
                {
                    if (i != j)
                        sum += (get(m, i, j) * x[j]);
                    iterations++;
                }
                result[i] = (1 / get(m, i, i)) * (get(m, i, w - 1) - sum);
            }

            if (distance(result, x, h) < E)
                k = N;

            for (int i = 0; i < h; i++)
            {
                x[i] = result[i];
                iterations++;
            }

            k++;
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, result, ellapsed_time, iterations, result_size);

        free_ticker(t);
        free(x);
        return data;
    }
    return NULL;
}

method_data* gauss_seidel(matrix* m)
{
    if (m != NULL && get_width(m) == get_heigth(m) + 1)
    {
        method_data* data = alloc_method_data(50);
        ticker* t = alloc_ticker();
        if (data == NULL || t == NULL)
            return NULL;

        int w = get_width(m);
        int h = get_heigth(m);

        strcpy(data->name, "Gauss-Seidel Method");
        double* result = (double*)calloc(h, sizeof(double));
        double ellapsed_time = 0;
        int iterations = 0;
        int result_size = h;

        start(t);
        int k = 0;
        double* x = (double*)calloc(h, sizeof(double));

        while (k < N)
        {
            for (int i = 0; i < h; i++)
            {
                double sum1 = 0;
                double sum2 = 0;
                for (int j = 0; j < h; j++)
                {
                    if (j < i - 1)
                        sum1 += (get(m, i, j) * result[j]);
                    if (j > i)
                        sum2 += (get(m, i, j) * x[j]);
                    iterations++;
                }
                result[i] = (1 / get(m, i, i)) * (get(m, i, w - 1) - sum1 - sum2);
            }

            if (distance(result, x, h) < E)
                k = N;

            for (int i = 0; i < h; i++)
            {
                x[i] = result[i];
                iterations++;
            }

            k++;
        }
        end(t);

        ellapsed_time = spent_time(t);
        set_method_data(data, result, ellapsed_time, iterations, result_size);

        free_ticker(t);
        free(x);
        return data;
    }
    return NULL;
}