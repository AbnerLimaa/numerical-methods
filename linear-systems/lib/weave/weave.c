#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <string.h>
#include <methods.h>
#include <matrix.h>
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
        double* result = get_result(data);
        double ellapsed_time = get_ellapsed_time(data);
        int iterations = get_iterations(data);
        int result_size = get_result_size(data);
        strcat(name, "\n");
        printf("%s", name);
        printf("Result:\n");
        for (int i = 0; i < result_size; i++)
            printf("x%d = %lf, ", i, result[i]);
        printf("\nEllapsed Time: %lf s\n", ellapsed_time);
        printf("Iterations: %d\n", iterations);
        printf("\n");
    }
}

void run_methods(matrix* m)
{
    method_data* data_1 = gauss(m);
    print_method_result(data_1);

    method_data* data_2 = gauss_partial(m);
    print_method_result(data_2);

    method_data* data_3 = gauss_scaled(m);
    print_method_result(data_3);

    method_data* data_4 = jacobi(m);
    print_method_result(data_4);

    free_method_data(data_1);
    free_method_data(data_2);
    free_method_data(data_3);
    free_method_data(data_4);
}

void option_0()
{
    char op = 'y';
    int hermite = 0;
    int n = 0;
    int i = 0;
    double x = 0;
    matrix* m = NULL;

    while(n < 2)
    {
        printf("How many linear systems will you provide\n");
        scanf("%d", &n);
    }

    m = alloc_matrix(n + 1, n);

    printf("Enter the linear systems\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d:\n", i);
        for (int j = 0; j < n + 1; j++)
        {
            if (j != n)
                printf("x%d = ", j);
            else
                printf("b%d = ", i);
            scanf("%lf", &x);
            set(m, i, j, x);
        }
    }

    run_methods(m);

    free_matrix(m);
}