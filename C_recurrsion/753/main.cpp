#include <stdio.h>
#include <conio.h>

/*
hãy tính tổng các chữ số của số nguyên dương n
n = 123
123%10 = 3
123/10 = 12

12%10 = 2
12/10 =  1

1&10 = 1
1/10 = 0
*/

int DemTongCacChuSo_DeQuy(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + DemTongCacChuSo_DeQuy(n / 10);
}

int DemTongCacChuSo_DeQuyDuoi(int n, int x = 0)
{
    if (n == 0)
    {
        return x;
    }
    DemTongCacChuSo_DeQuyDuoi(n / 10, x + n % 10);
}

int DemTongCacChuSo_HuyDeQuy(int n)
{
    int num = n;
    int tong = 0;
    while (num > 0)
    {
        tong += num % 10;
        num /= 10;
    }
    return tong;
}

int main()
{
    int num = 123456789;
    printf("\nTong cac chu so cua %d = %d", num, DemTongCacChuSo_DeQuy(num));
    printf("\nTong cac chu so cua %d = %d", num, DemTongCacChuSo_DeQuyDuoi(num));
    printf("\nTong cac chu so cua %d = %d", num, DemTongCacChuSo_HuyDeQuy(num));
    return 0;
}