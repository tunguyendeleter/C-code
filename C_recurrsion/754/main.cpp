#include <stdio.h>
#include <conio.h>

/*
hãy tính tích các chữ số của số nguyên dương n
n = 123
tich = 1
123%10 = 3*tich
123/10 = 12

12%10 = 2*tich
12/10 =  1

1&10 = 1*tich
1/10 = 0
*/

int TinhTichCacChuSo_DeQuy(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n % 10 * TinhTichCacChuSo_DeQuy(n / 10);
}

int TinhTichCacChuSo_DeQuyDuoi(int n, int x = 1)
{
    if (n == 0)
    {
        return x;
    }
    TinhTichCacChuSo_DeQuyDuoi(n / 10, x * (n % 10));
}

int TinhTichCacChuSo_HuyDeQuy(int n)
{
    int num = n;
    int tich = 1;
    while (num > 0)
    {
        tich *= num % 10;
        num /= 10;
    }
    return tich;
}

int main()
{
    int num = 123456789;
    printf("\nTich cac chu so cua %d = %d", num, TinhTichCacChuSo_DeQuy(num));
    printf("\nTich cac chu so cua %d = %d", num, TinhTichCacChuSo_DeQuyDuoi(num));
    printf("\nTich cac chu so cua %d = %d", num, TinhTichCacChuSo_HuyDeQuy(num));
    return 0;
}