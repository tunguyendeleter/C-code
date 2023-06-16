#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n;
    int max = 0;
    int min = 10;
    do
    {
        printf("\nNhap so nguyen duong : ");
        scanf("%d", &n);
    } while (n < 0 || ((int)log10((float)n) + 1 != 6));
    while (n > 0)
    {
        int temp = n % 10;
        n /= 10;
        if (max < temp)
            max = temp;
        if (min > temp)
            min = temp;
    }
    printf("\nMax = %d", max);
    printf("\nMin = %d", min);

    return 0;
}