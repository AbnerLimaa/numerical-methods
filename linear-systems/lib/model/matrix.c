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

void mult_scalar(matrix* m, double k)
{
    if (m != NULL)
    {
        for (int i = 0; i < m->h; i++)
        {
            for (int j = 0; j < m->w; j++)
                m->A[i][j] *= k;
        }
    }
}

matrix* sum(matrix* m1, matrix* m2)
{
    if (m1 != NULL && m2 != NULL && m1->h == m2->h && m1->w && m2->w)
    {
        matrix* m3 = alloc_matrix(m1->w, m1->h);
        if (m3 != NULL)
        {
            for (int i = 0; i < m1->h; i++)
            {
                for(int j = 0; j < m1->w; j++)
                    m3->A[i][j] = m1->A[i][j] + m2->A[i][j];
            }
            return m3;
        }
    }
    return NULL;
}

matrix* mult(matrix* m1, matrix* m2)
{
    if (m1 != NULL && m2 != NULL && m1->w == m2->h)
    {
        matrix* m3 = alloc_matrix(m1->h, m1->w);
        if (m3 != NULL)
        {
            double sum;
            for (int i = 0; i < m1->h; i++)
            {
                for(int j = 0; j < m2->w; j++)
                {
                    sum = 0;
                    for (int k = 0; k < m2->h; k++)
                        sum += (m1->A[i][k] * m2->A[k][j]);
                    m3->A[i][j] = sum;
                }
            }
        }
    }
    return NULL;
}

matrix* transpose(matrix* m)
{
    if (m != NULL)
    {
        matrix* t = alloc_matrix(m->h, m->w);
        if (t != NULL)
        {
            for (int i = 0; i < m->h; i++)
            {
                for (int j = 0; j < m->w;j++)
                    t->A[j][i] = m->A[i][j];
            }
            return t;
        }
    }
    return NULL;
}

double determinant(matrix* m)
{
    
}

void lu_factorization(matrix* m, matrix* l, matrix* u)
{

}

void ldl_factorization(matrix* m, matrix* l, matrix* d, matrix* l_t)
{

}

void cholesky_factorization(matrix* m, matrix* l, matrix* l_t)
{

}