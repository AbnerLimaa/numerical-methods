#include <stdio.h>
#include <stdlib.h>
#include <weave.h>

int main(void)
{
    int first_option = 0;
    int last_option = 0;
    int option = -1;
    while (option < first_option || option > last_option)
    {
        system("clear");
        printf("Choose the kind of equation you want to solve\n");
        printf("0 - polynomial\n");
        scanf("%d", &option);
    }
    object* o = get_object(option);
    execute(o);
    free_object(o);
    return 0;
}