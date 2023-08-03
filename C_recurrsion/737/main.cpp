/*
S(n) = 1/2 + 3/4 + 5/6 +...+ (2*n + 1)/(2*n + 2)
S(n) = S(n-1) + (2*n + 1)/(2*n + 2)
S(3) = S(2) + (2*3 + 1)/(2*3 + 2) = S(2) + 6/7
S(2) = S(1) + 5/6
S(1) = S(0) + 3/4
S(0) = 1/2
*/

#include <stdio.h>
#include <conio.h>

double TinhDeQuy(int n)
{
    // dieu kien dung
    if (n == 0)
    {
        return (double)1 / 2;
    }
    // de quy
    return (double)(2 * n + 1) / (2 * n + 2) + TinhDeQuy(n - 1);
}

double KhuDeQuy(int n)
{
    double tong = 0;
    for (int i = 0; i <= n; i++)
    {
        tong += (double)(2*i + 1)/(2*i + 2);
    }
    return tong;
}

double TinhDeQuyDuoi(int n, double x = 0.5)
{
    // dieu kien de quy
    if (n == 0)
    {
        return x;
    }
    // de quy
    return TinhDeQuyDuoi(n - 1, (double)(2*n + 1)/(2*n + 2) + x);
}

int main()
{
    printf("\nDe quy S(n) = %lf", TinhDeQuy(4));
    printf("\nKhu de quy S(n) = %lf", KhuDeQuy(4));
    printf("\nDe quy duoi S(n) = %lf", TinhDeQuyDuoi(4));
    return 0;
}