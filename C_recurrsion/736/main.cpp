/*
S(n) = 1/2 + 2/3 + 3/4 +...+ n/(n+1)
S(n) = S(n-1) + n/(n+1)
S(3) = S(2) + 3/5
S(2) = S(1) + 2/3
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
    return (double)n / (n + 1) + TinhDeQuy(n - 1);
}

double KhuDeQuy(int n)
{
    double tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += (double)i / (1 + i);
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
    return TinhDeQuyDuoi(n - 1, (double)n / (1 + n) + x);
}

int main()
{
    printf("\nDe quy S(n) = %lf", TinhDeQuy(3));
    printf("\nKhu de quy S(n) = %lf", KhuDeQuy(3));
    printf("\nDe quy duoi S(n) = %lf", TinhDeQuyDuoi(3));
    return 0;
}