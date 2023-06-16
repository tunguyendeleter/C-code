#include <stdio.h>
#include <conio.h>
#include <math.h>

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
    } while (b < 0 || a >= b);
    for (int i = a; i < b; i++)
    {
        
    }

    return 0;
}