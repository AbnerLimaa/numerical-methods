#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct function function;

typedef struct fconfig fconfig;

typedef double (*formula)(double, fconfig*);

typedef enum
{
    NONE,
    POLYNOMIAL
} ftype;

function* alloc_function(ftype t, formula f, int config_length);

void free_function(function* fun);

formula get_formula(function* fun);

fconfig* get_config(function* fun);

ftype get_type(function* fun);

double eval(function* fun, double x);

double eval_diff(function* fun, double p, int n);

double eval_fixed(function* fun, double x);

double* get_values(fconfig* c);

int get_values_length(fconfig* c);

#endif