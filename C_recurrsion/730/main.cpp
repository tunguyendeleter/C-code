/*
Tinh S(n) = 1+2+3+4+...+n
S(n) = S(n - 1) + n
S(3) = S(2) + 3
S(2) = S(1) + 2
S(1) = 1
*/
#include <stdio.h>
#include <conio.h>

int TinhDeQuy(int n)
{
    // dieu kien de quy
    if (n == 1)
    {
        return 1;
    }
    // de quy
    return TinhDeQuy(n - 1) + n;
}

int KhuDeQuy(int n)
{
    int tong = 0;
    for (int i = 0; i <= n; i++)
    {
        tong += i;
    }
    return tong;
}

int TinhDeQuyDuoi(int n, int x = 1)
{
    // dieu kien de quy
    if (n == 1)
    {
        return x;
    }
    // de quy
    return TinhDeQuyDuoi(n - 1, n + x);
}

int main()
{
    printf("\nDe quy S(n) = %d", TinhDeQuy(6));
    printf("\nKhu de quy S(n) = %d", KhuDeQuy(6));
    printf("\nDe quy duoi S(n) = %d", TinhDeQuyDuoi(6));
    return 0;
}