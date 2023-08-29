#include <stdio.h>

/*
S(n) = x^2 + x^4 + x^(n*2)
*/

float DeQuyMu(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return DeQuyMu(x, n + 1) / x;
    }
    return DeQuyMu(x, n - 1) * x;
}

float TinhDeQuy(int x, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return TinhDeQuy(x, n + 1) + DeQuyMu(x, n * 2);
    }
    return TinhDeQuy(x, n - 1) + DeQuyMu(x, n * 2);
}

float TinhDeQuyPhiTuyen(int x, int n)
{
    if (n == 0)
    {
        return 0;
    }
    float tich = 1;
    if (n < 0)
    {
        int len = -n * 2;
        for (int i = 0; i < len; i++)
        {
            tich /= x;
        }
        return TinhDeQuyPhiTuyen(x, n + 1) + tich;
    }
    for (int i = 0; i < n * 2; i++)
    {
        tich *= x;
    }
    return TinhDeQuyPhiTuyen(x, n - 1) + tich;
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(2, -4));
    printf("\nDe quy phi tuyen S(n) = %f", TinhDeQuyPhiTuyen(2, -4));
    return 0;
}