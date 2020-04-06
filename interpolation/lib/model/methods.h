#ifndef METHODS_H
#define METHODS_H

#include "table.h"

typedef struct method_data method_data;

void free_method_data(method_data* data);

char* get_name(method_data* data);

double get_result(method_data* data);

double get_ellapsed_time(method_data* data);

int get_iterations(method_data* data);

method_data* lagrange(table* t);

method_data* neville(table* t);

method_data* divided_differences(table* t);

method_data* hermite(table* t);

method_data* natural_cubic_spline(table* t);

method_data* clamped_cubic_spline(table* t);

#endif