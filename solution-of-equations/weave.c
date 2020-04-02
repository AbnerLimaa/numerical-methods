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

void print_method_result(method_data* data)
{
    if (data != NULL)
    {
        char* name = get_name(data);
        double result = get_result(data);
        double ellapsed_time = get_ellapsed_time(data);
        int iterations = get_iterations(data);
        strcat(name, "\n");
        printf("%s", name);
        printf("Result: %lf\n", result);
        printf("Ellapsed Time: %lf\n", ellapsed_time);
        printf("Iterations: %d\n", iterations);
        printf("\n");
    }
}

void run_methods(function* f)
{
    method_data* data_1 = bissection(f);
    print_method_result(data_1);

    method_data* data_2 = fixed_point(f);
    print_method_result(data_2);

    method_data* data_3 = newton_method(f);
    print_method_result(data_3);

    method_data* data_4 = secant_method(f);
    print_method_result(data_4);

    method_data* data_5 = false_position(f);
    print_method_result(data_5);

    method_data* data_6 = steffensen_method(f);
    print_method_result(data_6);

    method_data* data_7 = horner_method(f);
    print_method_result(data_7);

    method_data* data_8 = muller_method(f);
    print_method_result(data_8);

    free_method_data(data_1);
    free_method_data(data_2);
    free_method_data(data_3);
    free_method_data(data_4);
    free_method_data(data_5);
    free_method_data(data_6);
    free_method_data(data_7);
    free_method_data(data_8);
}

void option_0()
{
    int n = 0;
    int i = 0;
    double* v = NULL;
    function* f = NULL;

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

    run_methods(f);
    free_function(f);
}