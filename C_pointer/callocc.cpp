#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int *a;
    // a = (int *)malloc(5 * sizeof(int));
    // a = (int *)calloc(5, sizeof(int));
    a = (int *)realloc(NULL, 5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        printf("\n%d", a[i]);
    }

    realloc(a, 8 * sizeof(int));

    for (int i = 0; i < 9; i++)
    {
        printf("\n%d", a[i]);
    }
    free(a);
    getch();
    return 0;
}