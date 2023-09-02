#include <stdio.h>

/*
tìm ước số lẻ lớn nhất của số nguyên dương n.
ví dụ: n=100 ước lẻ lớn nhất của 100 là 25
*/

int UocLeLonNhat_DeQuy(int n, int x)
{
    if (n % x == 0 && x % 2 != 0)
    {
        return x;
    }
    return UocLeLonNhat_DeQuy(n, x - 1);
}

int UocLeLonNhat_HuyDeQuy(int n)
{
    for (int i = n / 3; i > 0; i--)
    {
        if (n % i == 0)
        {
            if (i % 2 != 0)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    do
    {
        printf("\nNhap so nguyen duong: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nkhong hop le");
        }
    } while (n < 0);
    printf("\nUoc le lon nhat cua %d la: %d", n, UocLeLonNhat_HuyDeQuy(n));
    printf("\nUoc le lon nhat cua %d la: %d", n, UocLeLonNhat_DeQuy(n, n / 3));
    return 0;
}