#include <stdio.h>
#include <conio.h>

/*
hãy đếm số lượng chữ số lẻ của số nguyên dương n
n = 123
123%10 = 3 => 1
123/10 = 12
12%10 = 2 => nope
12/10 = 1
1%10 = 1 => 2
1/10 = 0
*/

int DemSoLuongChuSoLe_DeQuy(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n % 2 != 0)
    {
        return 1 + DemSoLuongChuSoLe_DeQuy(n / 10);
    }
    else
    {
        return DemSoLuongChuSoLe_DeQuy(n / 10);
    }
}

int DemSoLuongChuSoLe_DeQuyDuoi(int n, int x = 0)
{
    if (n == 0)
    {
        return x;
    }
    if (n % 2 != 0)
    {
        DemSoLuongChuSoLe_DeQuyDuoi(n / 10, x + 1);
    }
    else
    {
        DemSoLuongChuSoLe_DeQuyDuoi(n / 10, x);
    }
}

int DemSoLuongChuSoLe_HuyDeQuy(int n, int x = 0)
{
    int num = n;
    int tong = 0;
    while (num > 0)
    {
        if (num % 10 % 2 != 0)
        {
            tong++;
        }
        num = num / 10;
    }
    return tong;
}

int main()
{
    int num = 123456789;
    printf("\nTong cac chu so le cua %d = %d", num, DemSoLuongChuSoLe_DeQuy(num));
    printf("\nTong cac chu so le cua %d = %d", num, DemSoLuongChuSoLe_DeQuyDuoi(num));
    printf("\nTong cac chu so le cua %d = %d", num, DemSoLuongChuSoLe_HuyDeQuy(num));
    return 0;
}