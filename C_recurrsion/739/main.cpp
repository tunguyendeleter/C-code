/*
n > 0 => T(x,n) = x^n
n < 0 => T(x,n) = x^(1/n)

T(x,n) = x^n => x*x^(n-1) = T(x, n-1)*x
T(2,3) = T(2,2)*2
T(2,2) = T(2,1)*2
T(2,1) = T(2,0)*2
T(2,0) = 1
*/

#include <stdio.h>
#include <conio.h>

double TinhDeQuy(int x, int n)
{
    // dieu kien dung
    if (n == 1)
    {
        return x;
    }
    else if (n == -1)
    {
        return 1.0 / x;
    }
    else if (n == 0)
    {
        return 1;
    }

    // de quy
    if (n < 0)
    {
        return TinhDeQuy(x, n + 1) * (1.0 / x);
    }

    return TinhDeQuy(x, n - 1) * x;
}

double KhuDeQuy(int x, int n)
{
    double tong = 1;
    int check = 0;
    if (n < 0)
    {
        check = 1;
        n *= -1;
    }
    for (int i = 1; i <= n; i++)
    {
        tong *= x;
    }
    if (check == 1)
    {
        return 1.0 / tong;
    }

    return tong;
}

double TinhDeQuyDuoi(double x, int n, double y = 1)
{
    // dieu kien de quy
    if (n == 0)
    {
        return y;
    }

    // de quy
    if (n < 0)
    {
        return TinhDeQuyDuoi(x, n + 1, y * 1.0 / x);
    }
    return TinhDeQuyDuoi(x, n - 1, y * x);
}

int main()
{
    printf("\nDe quy T(x,n) = %lf", TinhDeQuy(2, -3));
    printf("\nKhu de quy T(x,n) = %lf", KhuDeQuy(2, -3));
    printf("\nDe quy duoi T(x,n) = %lf", TinhDeQuyDuoi(2, -3));
    return 0;
}