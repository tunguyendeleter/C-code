#include <stdio.h>
#include <conio.h>

int main()
{
    int a, b;
    do
    {
        printf("\nNhap a: ");
        scanf("%d", &a);
    } while (a < 0);
    do
    {
        printf("\nNhap b: ");
        scanf("%d", &b);
    } while (b < 0);

    int len = a > b ? a : b;
    for (int i = 1; i <= len; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            printf("\n%d", i);
        }
    }
    getch();
    return 0;
}