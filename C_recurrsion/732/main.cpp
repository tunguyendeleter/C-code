/*
S(n) = 1 + 1/2 + 1/3 + 1/4 +...+ 1/n
S(n) = S(n-1) + 1/n
S(3) = S(2) + 1/3
S(2) = S(1) + 1/2
S(1) = 1
*/

#include <stdio.h>
#include <conio.h>

double TinhDeQuy(int n)
{
    // dieu kien dung
    if (n == 1)
    {
        return 1;
    }
    // de quy
    return (double)1 / n + TinhDeQuy(n - 1);
}

double KhuDeQuy(int n)
{
    double tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += (double)1 / i;
    }
    return tong;
}

double TinhDeQuyDuoi(int n, double x = 1)
{
    // dieu kien de quy
    if (n == 1)
    {
        return x;
    }
    // de quy
    return TinhDeQuyDuoi(n - 1, (double)1 / n + x);
}

int main()
{
    printf("\nDe quy S(n) = %lf", TinhDeQuy(6));
    printf("\nKhu de quy S(n) = %lf", KhuDeQuy(6));
    printf("\nDe quy duoi S(n) = %lf", TinhDeQuyDuoi(6));
    return 0;
}