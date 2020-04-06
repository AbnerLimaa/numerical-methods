#ifndef TABLE_H
#define TABLE_H

typedef struct table table;

table* alloc_table(int length);

void free_table(table* t);

int get_length(table* t);

double get_x(table* t, int i);

void set_x(table* t, int i, double value);

double get_y(table* t, int i);

void set_y(table* t, int i, double value);

#endif