#include "function.h"

double bissection(double (*fun)(double, parameters*), parameters* p);

double fixed_point(double (*fun)(double, parameters*), parameters* p);

double secant_method(double (*fun)(double, parameters*), parameters* p);

double false_position(double (*fun)(double, parameters*), parameters* p);

double steffensen_method(double (*fun)(double, parameters*), parameters* p);

double horner_method(double (*fun)(double, parameters*), parameters* p);

double muller_method(double (*fun)(double, parameters*), parameters* p);