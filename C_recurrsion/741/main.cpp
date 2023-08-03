/*
S(n) = x + x^2 + x^3 +...+ x^(n)
*/

#include <stdio.h>
#include <conio.h>

float TinhDeQuyPhiTuyen(int x, int n)
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
        tich *= x;
    }
    return TinhDeQuyPhiTuyen(x, n - 1) + tich;
}

float Mu(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    else if (n == -1)
    {
        return 1.0 / x;
    }

    if (n < 0)
    {
        return Mu(x, n + 1) * (1.0 / x);
    }
    return Mu(x, n - 1) * x;
}
float TinhDeQuy(int x, int n)
{
    if (n == 0)
    {
        return 0;
    }
    return TinhDeQuy(x, n - 1) + Mu(x, n);
}

float KhuDeQuy(int x, int n)
{
    float tong = 0;
    float tich = 1;
    for (int i = 1; i <= n; i++)
    {
        tich = 1;
        for (int j = 1; j <= i; j++)
        {
            tich *= x;
        }
        tong += tich;
    }
    return tong;
}

float TinhDeQuyDuoi(int y, int n, int x = 0)
{
    // dieu kien de quy
    if (n == 0)
    {
        return x;
    }
    // de quy
    return TinhDeQuyDuoi(y, n - 1, x + Mu(y, n));
}

int main()
{
    printf("\nDe quy phi tuyen S(n) = %f", TinhDeQuyPhiTuyen(2, 5));
    printf("\nDe quy S(n) = %f", TinhDeQuy(2, 5));
    printf("\nKhu de quy S(n) = %f", KhuDeQuy(2, 5));
    printf("\nDe quy duoi S(n) = %f", TinhDeQuyDuoi(2, 5));
    return 0;
}