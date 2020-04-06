#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <string.h>
#include <methods.h>
#include <table.h>
#include "weave.h"

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
        printf("Ellapsed Time: %lf s\n", ellapsed_time);
        printf("Iterations: %d\n", iterations);
        printf("\n");
    }
}

void run_methods(table* t, double x)
{
    method_data* data_1 = lagrange(t, x);
    print_method_result(data_1);

    method_data* data_2 = neville(t, x);
    print_method_result(data_2);

    method_data* data_3 = divided_differences(t, x);
    print_method_result(data_3);

    method_data* data_4 = hermite(t, x);
    print_method_result(data_4);

    method_data* data_5 = natural_cubic_spline(t, x);
    print_method_result(data_5);

    method_data* data_6 = clamped_cubic_spline(t, x);
    print_method_result(data_6);

    free_method_data(data_1);
    free_method_data(data_2);
    free_method_data(data_3);
    free_method_data(data_4);
    free_method_data(data_5);
    free_method_data(data_6);
}

void option_0()
{
    char op = 'y';
    int n = 0;
    int i = 0;
    double x = 0;
    table* t = NULL;

    while(n <= 0)
    {
        printf("How many points will you provide\n");
        scanf("%d", &n);
    }

    t = alloc_table(n);

    printf("Enter the points coordinates\n");
    while(i < n)
    {
        double xi = 0;
        double yi = 0;
        printf("x%d: \n", i);
        scanf("%lf", &xi);
        printf("f(x%d): \n", i);
        scanf("%lf", &yi);
        set_x(t, i, xi);
        set_y(t, i, yi);
        i++;
    }

    while(1)
    {
        printf("Evaluate function on which x coordinate\n");
        scanf("%lf", &x);
        run_methods(t, x);
        
        printf("Continue(y/n)");
        scanf(" %c", &op);
        if (op == 'n')
            break;
    }   
    
    free_table(t);
}