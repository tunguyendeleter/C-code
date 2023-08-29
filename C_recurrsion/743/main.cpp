#include <stdio.h>

/*
S(n) = x^1 + x^3 + x^5 +...+ x^(n*2 + 1)
*/

float Mu(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return Mu(x, n + 1) / x;
    }
    return Mu(x, n - 1) * x;
}

float TinhDeQuy(int x, int n)
{
    if (n == 0)
    {
        return x;
    }
    if (n < 0)
    {
        return TinhDeQuy(x, n + 1) + Mu(x, n * 2 + 1);
    }
    return TinhDeQuy(x, n - 1) + Mu(x, n * 2 + 1);
}

float TinhDeQuyPhiTuyen(int x, int n)
{
    if (n == 0)
    {
        return x;
    }
    float tich = 1;
    int len;
    if (n < 0)
    {
        len = -n * 2 + 1;
        for (int i = 0; i < len; i++)
        {
            tich /= x;
        }
        return TinhDeQuyPhiTuyen(x, n + 1) + tich;
    }
    len = n * 2 + 1;
    for (int i = 0; i < len; i++)
    {
        tich *= x;
    }
    return TinhDeQuyPhiTuyen(x, n - 1) + tich;
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(2, 2));
    printf("\nDe quy phi tuyen S(n) = %f", TinhDeQuyPhiTuyen(2, 2));
    return 0;
}