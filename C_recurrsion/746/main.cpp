#include <stdio.h>

/*
S(n) = 1 + (x^2)/(2!) + (x^4)/(4!) +...+ (x^2n)/(2n!)
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
    if (n == 0)
    {
        return 1;
    }
    return TinhDeQuy(x, n - 1) + TinhMu(x, 2 * n) / TinhLuyThua(2 * n);
}

float TinhDeQuyPhiTuyen(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    float tuso = 1;
    for (int i = 0; i < 2 * n; i++)
    {
        tuso *= x;
    }
    float mauso = 1;
    for (int i = 2; i <= 2 * n; i++)
    {
        mauso *= i;
    }
    return TinhDeQuy(x, n - 1) + tuso / mauso;
}

float TinhDeQuyDuoi(int x, int n, float d = 0)
{
    if (n == 0)
    {
        return d + 1;
    }
    d += TinhMu(x, 2 * n) / TinhLuyThua(2 * n);
    return TinhDeQuyDuoi(x, n - 1, d);
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(2, 5));
    printf("\nDe quy phi tuyen S(n) = %f", TinhDeQuyPhiTuyen(2, 5));
    printf("\nDe quy duoi S(n) = %f", TinhDeQuyDuoi(2, 5));
    return 0;
}