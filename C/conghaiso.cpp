#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int main()
{
    int *a = (int *)malloc(2 * sizeof(int));
    if (a == NULL)
    {
        printf("\nFail to malloc");
    }
    else
    {
        do
        {
            printf("\nNhap so 1st: ");
            scanf("%d", &a[0]);
        } while (a[0] < 0);
        do
        {
            printf("\nNhap so 2nd: ");
            scanf("%d", &a[1]);
        } while (a[1] < 0);
    }
    printf("\nPrint tong: %d", a[0] + a[1]);
    

    getch();
    return 0;
}