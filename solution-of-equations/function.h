typedef struct function function;

typedef struct fconfig fconfig;

typedef double (*formula)(double, fconfig*);

function* alloc_function(formula f, int config_length);

void free_function(function* fun);

formula get_formula(function* fun);

fconfig* get_config(function* fun);

double eval(function* fun, double x);

double eval_diff(function* fun, double p, int n);

double eval_fixed(function* fun, double x);

double* get_values(fconfig* c);

int get_values_length(fconfig* c);