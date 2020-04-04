#ifndef METHODS_H
#define METHODS_H

#include "function.h"

typedef struct method_data method_data;

void free_method_data(method_data* data);

char* get_name(method_data* data);

double get_result(method_data* data);

double get_ellapsed_time(method_data* data);

int get_iterations(method_data* data);

method_data* bissection(function* f);

method_data* fixed_point(function* f);

method_data* newton_method(function* f);

method_data* secant_method(function* f);

method_data* false_position(function* f);

method_data* steffensen_method(function* f);

method_data* horner_method(function* f);

method_data* muller_method(function* f);

#endif