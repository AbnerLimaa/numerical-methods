#ifndef METHODS_H
#define METHODS_H

#include "matrix.h"

typedef struct method_data method_data;

void free_method_data(method_data* data);

char* get_name(method_data* data);

double* get_result(method_data* data);

double get_ellapsed_time(method_data* data);

int get_iterations(method_data* data);

int get_result_size(method_data* data);

method_data* gauss(matrix* m);

method_data* gauss_partial(matrix* m);

method_data* gauss_scaled(matrix* m);

method_data* jacobi(matrix* m);

method_data* gauss_seidel(matrix* m);

#endif