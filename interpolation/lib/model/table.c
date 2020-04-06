#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "table.h"

struct table
{
    int length;
    double* x;
    double* y;
};

table* alloc_table(int length)
{
    table* t = (table*)calloc(1, sizeof(table));
    if (t != NULL)
    {
        t->length = length;
        t->x = (double*)calloc(length, sizeof(double));
        t->y = (double*)calloc(length, sizeof(double));
        return t;   
    }
    return NULL;
}

void free_table(table* t)
{
    if (t != NULL)
    {
        free(t->x);
        free(t->y);
        free(t);
    }
}

int get_length(table* t)
{
    if (t != NULL)
        return t->length;
    return INT_MAX;
}

double get_x(table* t, int i)
{
    if (t != NULL && i >= 0 && i < t->length)
        return t->x[i];
    return DBL_MAX;
}

void set_x(table* t, int i, double value)
{
    if (t != NULL && i >= 0 && i < t->length)
        t->x[i] = value;
}

double get_y(table* t, int i)
{
    if (t != NULL && i >= 0 && i < t->length)
        return t->y[i];
    return DBL_MAX;
}

void set_y(table* t, int i, double value)
{
    if (t != NULL && i >= 0 && i < t->length)
        t->y[i] = value;
}