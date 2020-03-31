typedef struct parameters parameters;

parameters* alloc_parameters();

void free_parameters(parameters* p);

double* get_coefficients(parameters* p);

int get_length(parameters* p);