/*
S(n) = 1 + 1*2 + 1*2*3 +...+ 1*2*3*...*n
S(n) = S(n-1) + 1*2*3*...*n
S(3) = S(2) + 1*2*3
S(2) = S(1) + 1*2
S(1) = S(0) + 1
S(0) = 0
*/

#include <stdio.h>
#include <conio.h>

int TinhDeQuyPhiTuyen(int n)
{
    // dieu kien dung
    if (n == 0)
    {
        return 0;
    }
    // de quy phi tuyen
    int tich = 1;
    for (int i = 1; i <= n; i++)
    {
        tich *= i;
    }
    return TinhDeQuyPhiTuyen(n - 1) + tich;
}

int LuyThua(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return LuyThua(n - 1) * n;
}
int TinhDeQuy(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return TinhDeQuy(n - 1) + LuyThua(n);
}

int KhuDeQuy(int n)
{
    int tong = 0;
    int tich = 1;
    for (int i = 1; i <= n; i++)
    {
        tich = 1;
        for (int j = 1; j <= i; j++)
        {
            tich *= j;
        }
        tong += tich;
    }
    return tong;
}

int TinhDeQuyDuoi(int n, int x = 0)
{
    // dieu kien de quy
    if (n == 0)
    {
        return x;
    }
    // de quy
    return TinhDeQuyDuoi(n - 1, x + LuyThua(n));
}

int main()
{
    printf("\nDe quy phi tuyen S(n) = %d", TinhDeQuyPhiTuyen(4));
    printf("\nDe quy S(n) = %d", TinhDeQuy(4));
    printf("\nKhu de quy S(n) = %d", KhuDeQuy(4));
    printf("\nDe quy duoi S(n) = %d", TinhDeQuyDuoi(4));
    return 0;
}