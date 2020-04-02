#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <string.h>
#include "weave.h"
#include "methods.h"
#include "equations.h"
#include "function.h"

void option_0();

void (*fun_array[])() = { option_0 };

struct object
{
    void (*function)();
};

object* alloc_object(void (*fun)())
{
    object* o = calloc(1, sizeof(object));
    if (o != NULL)
        o->function = fun;
    return o;
}

void free_object(object* o)
{
    free(o);
}

object* get_object(int request)
{
    void (*fun)() = fun_array[request];
    object* o = alloc_object(fun);
    return o;
}

void execute(object* o)
{
    system("clear");
    o->function();
}

void print_method_result(char* text, double result)
{
    char dest[50];
    strcpy(dest, text);
    if (result != DBL_MAX)
    {
        strcat(dest, ": %lf\n");
        printf(dest, result);
    }
    else
    {
        strcat(dest, ": fail\n");
        printf("%s", dest);
    }
}

void run_methods(function* f, function* f_diff, function* f_fixed)
{
    double result_1 = bissection(f);
    print_method_result("Bissection method", result_1);

    double result_2 = fixed_point(f_fixed, f_diff);
    print_method_result("Fixed Point method", result_2);

    double result_3 = newton_method(f_diff);
    print_method_result("Newton method", result_3);

    double result_4 = secant_method(f);
    print_method_result("Secant method", result_4);

    double result_5 = false_position(f);
    print_method_result("False Position method", result_5);

    double result_6 = steffensen_method(f);
    print_method_result("Steffensen method", result_6);

    double result_7 = horner_method(f);
    print_method_result("Horner method", result_7);

    double result_8 = muller_method(f);
    print_method_result("Muller method", result_8);
}

void option_0()
{
    int n = 0;
    int i = 0;
    double* v = NULL;
    function* f = NULL;
    function* f_diff = NULL;
    function* f_fixed = NULL;

    while(n <= 0)
    {
        printf("Set the polynomial degree\n");
        scanf("%d", &n);
    }

    f = alloc_function(polynomial, n + 1);
    v = get_values(get_config(f));

    printf("Enter the polynomial coefficients\n");
    while(i < n + 1)
    {
        scanf("%lf", &v[i]);
        i++;
    }

    run_methods(f, f_diff, f_fixed);
    free_function(f);
    free_function(f_diff);
    free_function(f_fixed);
}