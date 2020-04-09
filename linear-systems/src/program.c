#include <stdio.h>
#include <stdlib.h>
#include <weave.h>

int main(void)
{
    int first_option = 0;
    int last_option = 0;
    int option = 0;
    system("clear");
    object* o = get_object(option);
    execute(o);
    free_object(o);
    return 0;
}