#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix matrix;

matrix* alloc_matrix(int width, int heigth);

void free_matrix(matrix* m);

int get_width(matrix* m);

int get_heigth(matrix* m);

double get(matrix* m, int i, int j);

void set(matrix* m, int i, int j, double x);

void switch_lines(matrix* m, int i, int j);

void multiply_line(matrix* m, int i, double k);

void eliminate(matrix* m, int i, int j, double k);

#endif