#include "function.h"

double bissection(function* f);

double fixed_point(function* f_fixed, function* f_diff);

double newton_method(function* f_diff);

double secant_method(function* f);

double false_position(function* f);

double steffensen_method(function* f);

double horner_method(function* f);

double muller_method(function* f);