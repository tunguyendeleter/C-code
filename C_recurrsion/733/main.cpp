/*
S(n) = 1/2 + 1/4 + 1/6 +...+ 1/2n
S(n) = S(n-1) + 1/2n
S(3) = S(2) + 1/6
S(2) = S(1) + 1/4
S(1) = S(0) + 1/2
S(0) = 0
*/

#include <stdio.h>
#include <conio.h>

double TinhDeQuy(int n)
{
    // dieu kien dung
    if (n == 0)
    {
        return 0;
    }
    // de quy
    return (double)1 / (2 * n) + TinhDeQuy(n - 1);
}

double KhuDeQuy(int n)
{
    double tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += (double)1 / (2 * i);
    }
    return tong;
}

double TinhDeQuyDuoi(int n, double x = 0)
{
    // dieu kien de quy
    if (n == 0)
    {
        return x;
    }
    // de quy
    return TinhDeQuyDuoi(n - 1, (double)1 / (2 * n) + x);
}

int main()
{
    printf("\nDe quy S(n) = %lf", TinhDeQuy(2));
    printf("\nKhu de quy S(n) = %lf", KhuDeQuy(2));
    printf("\nDe quy duoi S(n) = %lf", TinhDeQuyDuoi(2));
    return 0;
}