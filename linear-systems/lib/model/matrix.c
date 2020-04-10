#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "matrix.h"

struct matrix
{
    double** A;
    int w;
    int h;
};

matrix* alloc_matrix(int width, int heigth)
{
    matrix* m = (matrix*)calloc(1, sizeof(matrix));
    if (m != NULL && width > 1 && heigth > 1)
    {
        m->A = (double**)calloc(heigth, sizeof(double*));
        for (int i = 0; i < heigth; i++)
            m->A[i] = (double*)calloc(width, sizeof(double));
        m->w = width;
        m->h = heigth;
        return m;
    }
    return NULL;
}

void free_matrix(matrix* m)
{
    if (m != NULL)
    {
        for (int i = 0; i < m->h; i++)
            free(m->A[i]);
        free(m->A);
        free(m);
    }
}

int get_width(matrix* m)
{
    if (m != NULL)
        return m->w;
}

int get_heigth(matrix* m)
{
    if (m != NULL)
        return m->h;
}

double get(matrix* m, int i, int j)
{
    if (m != NULL && i >= 0 && i < m->h && j >= 0 && j < m->w)
        return m->A[i][j];
}

void set(matrix* m, int i, int j, double x)
{
    if (m != NULL && i >= 0 && i < m->h && j >= 0 && j < m->w)
        m->A[i][j] = x;
}

void switch_lines(matrix* m, int i, int j)
{
    if (m != NULL && i >= 0 && i < m->h && j >= 0 && j < m->h)
    {
        double aux;
        for (int w = 0; w < m->w; w++)
        {
            aux = m->A[i][w];
            m->A[i][w] = m->A[j][w];
            m->A[j][w] = aux;
        }
    }
}

void multiply_line(matrix* m, int i, double k)
{
    if (m != NULL && i >= 0 && i < m->h && k != 0)
    {
        for (int w = 0; w < m->w; w++)
            m->A[i][w] *= k;
    }
}

void eliminate(matrix* m, int i, int j, double k)
{
    if (m != NULL && i >= 0 && i < m->h && j >= 0 && j < m->h)
    {
        for (int w = 0; w < m->w; w++)
            m->A[j][w] -= (m->A[i][w] * k);
    }
}