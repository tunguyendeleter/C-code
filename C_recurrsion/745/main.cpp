#include <stdio.h>

/*
S(n) = x + (x^2)/(2!) + (x^3)/(3!) +...+ (x^n)/(n!)
*/

float TinhLuyThua(int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    return TinhLuyThua(n - 1) * n;
}

float TinhMu(int a, int b)
{
    if (b == 0)
    {
        return 1.0;
    }
    return TinhMu(a, b - 1) * a;
}

float TinhDeQuy(int x, int n)
{
    if (n == 1)
    {
        return x;
    }
    return TinhDeQuy(x, n - 1) + TinhMu(x, n) / TinhLuyThua(n);
}

float TinhDeQuyPhiTuyen(int x, int n)
{
    if (n == 1)
    {
        return x;
    }
    float tuso = 1;
    for (int i = 0; i < n; i++)
    {
        tuso *= x;
    }
    float mauso = 1;
    for (int i = 2; i <= n; i++)
    {
        mauso *= i;
    }
    return TinhDeQuy(x, n - 1) + tuso / mauso;
}

float TinhDeQuyDuoi(int x, int n, float d = 0)
{
    if (n == 1)
    {
        return d + x;
    }
    d += TinhMu(x, n) / TinhLuyThua(n);
    return TinhDeQuyDuoi(x, n - 1, d);
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(2, 3));
    printf("\nDe quy phi tuyen S(n) = %f", TinhDeQuyPhiTuyen(2, 3));
    printf("\nDe quy duoi S(n) = %f", TinhDeQuyDuoi(2, 3));
    return 0;
}