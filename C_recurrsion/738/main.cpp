/*
T(n) = 1x2x3x...xn
T(n) = T(n-1)*n
T(3) = T(2)*3
T(2) = T(1)*2
T(1) = T(0)*1
T(0) = 1
*/

#include <stdio.h>
#include <conio.h>

long TinhDeQuy(int n)
{
    // dieu kien dung
    if (n == 0)
    {
        return 1;
    }
    // de quy
    return TinhDeQuy(n - 1) * n;
}

long KhuDeQuy(int n)
{
    long tong = 1;
    for (int i = 1; i <= n; i++)
    {
        tong *= i;
    }
    return tong;
}

long TinhDeQuyDuoi(int n, int x = 1)
{
    // dieu kien de quy
    if (n == 0)
    {
        return x;
    }
    // de quy
    return TinhDeQuyDuoi(n - 1, n * x);
}

int main()
{
    printf("\nDe quy S(n) = %ld", TinhDeQuy(4));
    printf("\nKhu de quy S(n) = %ld", KhuDeQuy(4));
    printf("\nDe quy duoi S(n) = %ld", TinhDeQuyDuoi(4));
    return 0;
}