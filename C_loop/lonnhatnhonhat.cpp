#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n;
    do
    {
        printf("\nNhap n(n>=0):");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nGia tri n khong hop le");
        }
    } while (n < 0);
    int sochu;
    // if (n == 0)
    // {
    //     sochu = 1;
    // }
    // else
    // {
    //     sochu = (int)log10((float)n) + 1;
    // }
    int max, min;
    max = min = n % 10;
    while (n > 0)
    {
        sochu = n % 10;
        n /= 10;
        if (max < sochu)
        {
            max = sochu;
        }
        if (min > sochu)
        {
            min = sochu;
        }
    }

    printf("\nMin la :%d", min);
    printf("\nMax la :%d", max);
    getch();
    return 0;
}