#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int *a;
    int n;
    printf("\nNhap n: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", a + i);
    }
    realloc(a, 4 * sizeof(int));
    for (int i = 0; i < 6; i++)
    {
        printf("%4d", a[i]);
    }

    return 0;
}