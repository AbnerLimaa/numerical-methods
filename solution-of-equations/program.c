#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include "equations.h"
#include "function.h"

void execute_function(double (*fun)(double, parameters*), parameters* p)
{
    double result_1 = bissection(fun, p);
    printf("Bissection method result: %lf\n", result_1);
}

void choice_function(int option)
{
    double (*fun)(double, parameters*);
    int n; 
    if (option == 1)
    {
        int degree;
        fun = polinomial;
        printf("Set function degree\n");
        scanf("%d", &degree);
        n = degree + 1;
    }
    else
    {
        printf("error\n");
        return;
    }
    parameters* p = alloc_parameters(n);
    double* c = get_coefficients(p);
    printf("Set function coefficients\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &c[i]);
    execute_function(fun, p);
    free_parameters(p);
}

int main(void)
{
    int option = 0;
    while (option != 1)
    {
        system("clear");
        printf("Choose the kind of equation you want to solve\n");
        printf("1 - polinomial\n");
        scanf("%d", &option);
    }
    choice_function(option);
    return 0;
}