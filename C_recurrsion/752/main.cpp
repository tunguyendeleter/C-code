#include <stdio.h>
#include <conio.h>
#include <math.h>
// hãy đếm số lượng chữ số của số nguyên dương n
/*
n = 210
210/10 = 21 => 1
21/10 = 1 => 2
2/10 = 0 => 3
*/

int DemSoLuongChuSo_DeQuy(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1 + DemSoLuongChuSo_DeQuy(n / 10);
}

int DemSoLuongChuSo_DeQuyDuoi(int n, int x = 0)
{
    if (n == 0)
    {
        return x;
    }
    DemSoLuongChuSo_DeQuyDuoi(n / 10, x + 1);
}

int DemSoLuongChuSo_HuyDeQuy(int n)
{
    int dem = 0;
    int num = n;
    while (num > 0)
    {
        num /= 10;
        dem++;
    }
    return dem;
}

int DemSoLuongChuSo_HuyDeQuy2(int n)
{
    return log10(n) + 1;
}

int main()
{
    int num = 123456789;
    printf("\nSo luong chu so %d = %d", num, DemSoLuongChuSo_DeQuy(num));
    printf("\nSo luong chu so %d = %d", num, DemSoLuongChuSo_DeQuyDuoi(num));
    printf("\nSo luong chu so %d = %d", num, DemSoLuongChuSo_HuyDeQuy(num));
    printf("\nSo luong chu so %d = %d", num, DemSoLuongChuSo_HuyDeQuy2(num));
    return 0;
}