#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clear_arr_2x(char **a)
{
    int i;

    i = -1;
    while (a[++i])
        free(a[i]);
    free(a);
}

void        check(char **array)
{
    array[0] = strdup("aizhan");
}

int         main()
{
    char    **array;
    int     i;
    array = (char **) malloc(sizeof (char *) * 3);
    array[0] = strdup("hello");
    array[1] = strdup("hi");
    array[2] = NULL;
    printf("%s\n", array[0]);
    printf("%s\n", array[1]);
    check(array);
    printf("%s\n", array[0]);
    clear_arr_2x(array);
    printf("%s\n", array[0]);
    printf("%s\n", array[1]);
    free(array[0]);
}