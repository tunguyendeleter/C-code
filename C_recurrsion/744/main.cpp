#include <stdio.h>

/*
S(n) = 1 + 1/(1+2) + 1/(1+2+3) + ... + 1/(1+2+3+...+n)
*/

int TinhMauSo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return TinhMauSo(n - 1) + n;
}

float TinhDeQuy(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return TinhDeQuy(n - 1) + 1.0 / TinhMauSo(n);
}

float TinhDeQuyPhiTuyen(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += i;
    }
    return TinhDeQuy(n - 1) + 1.0 / tong;
}
float TinhDeQuyDuoi(int n, float x = 0)
{
    if (n == 0)
    {
        return x;
    }
    x += 1.0 / TinhMauSo(n);
    return TinhDeQuyDuoi(n - 1, x);
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(4));
    printf("\nDe quy phi tuyen S(n) = %f", TinhDeQuyPhiTuyen(4));
    printf("\nDe quy duoi S(n) = %f", TinhDeQuyDuoi(4));
    return 0;
}