typedef struct object object;

void free_object(object* o);

void execute(object* o);

object* get_object(int request);