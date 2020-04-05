#ifndef NUMBER_H
#define NUMBER_H

typedef struct real real;

typedef struct complex complex;

real* alloc_real(double value);

void free_real(real* r);

double get_value(real* r);

void print_real(real* r);

real* add_real(real* r1, real* r2);

real* sub_real(real* r1, real* r2);

real* mul_real(real* r1, real* r2);

real* div_real(real* r1, real* r2);

complex* to_complex(real* r);

complex* alloc_complex(double real, double imaginary);

void free_complex(complex* c);

double get_real(complex* c);

double get_imaginary(complex* c);

void print_complex(complex* c);

complex* add_complex(complex* c1, complex* c2);

complex* sub_complex(complex* c1, complex* c2);

complex* mul_complex(complex* c1, complex* c2);

complex* div_complex(complex* c1, complex* c2);

complex* conjugate(complex* c);

#endif