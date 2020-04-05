#include <stdlib.h>
#include <float.h>
#include <stdio.h>
#include "number.h"

struct real
{
    double value;
};

struct complex
{
    double real;
    double imaginary;
};

real* alloc_real(double value)
{
    real* r = (real*)calloc(1, sizeof(real));
    if (r != NULL)
    {
       r->value = value;
       return r;
    }
    return NULL;
}

void free_real(real* r)
{
    if (r != NULL)
        free(r);
}

double get_value(real* r)
{
    if (r != NULL)
        return r->value;
    return DBL_MAX;
}

void print_real(real* r)
{
    if (r != NULL)
        printf("%.9lf", r->value);
}

real* add_real(real* r1, real* r2)
{
    if (r1 != NULL && r2 != NULL)
    {
        real* r3 = alloc_real(r1->value + r2->value);
        if (r3 != NULL)
            return r3;
    }
    return NULL;
}

real* sub_real(real* r1, real* r2)
{
    if (r1 != NULL && r2 != NULL)
    {
        real* r3 = alloc_real(r1->value - r2->value);
        if (r3 != NULL)
            return r3;
    }
    return NULL;
}
real* mul_real(real* r1, real* r2)
{
    if (r1 != NULL && r2 != NULL)
    {
        real* r3 = alloc_real(r1->value * r2->value);
        if (r3 != NULL)
            return r3;
    }
    return NULL;
}

real* div_real(real* r1, real* r2)
{
    if (r1 != NULL && r2 != NULL)
    {
        real* r3 = alloc_real(r1->value / r2->value);
        if (r3 != NULL)
            return r3;
    }
    return NULL;
}

complex* to_complex(real* r)
{
    if (r != NULL)
    {
        complex* c = alloc_complex(r->value, 0);
        return c;
    }
    return NULL;
}

complex* alloc_complex(double real, double imaginary)
{
    complex* c = (complex*)calloc(1, sizeof(complex));
    if (c != NULL)
    {
        c->real = real;
        c->imaginary = imaginary;
        return c;
    }
    return NULL;
}

void free_complex(complex* c)
{
    if (c != NULL)
        free(c);
}

double get_real(complex* c)
{
    if (c != NULL)
        return c->real;
    return DBL_MAX;
}

double get_imaginary(complex* c)
{
    if (c != NULL)
        return c->imaginary;
    return DBL_MAX;
}

void print_complex(complex* c)
{
    if (c != NULL)
        printf("%.9lf %.9lfi", c->real, c->imaginary);
}

complex* add_complex(complex* c1, complex* c2)
{
    if (c1 != NULL && c2 != NULL)
    {
        complex* c3 = alloc_complex(c1->real + c2->real, c1->imaginary + c2->imaginary);
        if (c3 != NULL)
            return c3;
    }
    return NULL;
}

complex* sub_complex(complex* c1, complex* c2)
{
    if (c1 != NULL && c2 != NULL)
    {
        complex* c3 = alloc_complex(c1->real - c2->real, c1->imaginary - c2->imaginary);
        if (c3 != NULL)
            return c3;
    }
    return NULL;
}

complex* mul_complex(complex* c1, complex* c2)
{
    if (c1 != NULL && c2 != NULL)
    {
        complex* c3 = alloc_complex((c1->real * c2->real) - (c1->imaginary * c2->imaginary), (c1->real * c2->imaginary) - (c1->imaginary * c2->real));
        if (c3 != NULL)
            return c3;
    }
    return NULL;
}

complex* div_complex(complex* c1, complex* c2)
{
    if (c1 != NULL && c2 != NULL)
    {
        complex* conj = conjugate(c2);
        complex* c3 = mul_complex(c2, conj);
        double ratio = c3->real + c3->imaginary;
        complex* c4 = alloc_complex(c1->real / ratio, c1->imaginary / ratio);
        if (c4 != NULL)
            return c4;
        free_complex(conj);
        free_complex(c3);
    }
    return NULL;
}

complex* conjugate(complex* c)
{
    if (c != NULL)
    {
        complex* c1 = alloc_complex(c->real, (-1) * c->imaginary);
        if (c1 != NULL)
            return c1;
    }
    return NULL;
}