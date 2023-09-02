#include <stdio.h>
#include <math.h>

/*
S(n) = sqrt(2+sqrt(2+sqrt(2+...sqrt(2))))
có n dấu căn: sqrt()
*/

double TinhDeQuy(int n)
{
    if (n == 1)
    {
        return sqrt(2);
    }
    if (n == 0)
    {
        return 2;
    }
    double pre = TinhDeQuy(n - 1);
    return sqrt(2 + pre);
}

double HuyDeQuy(int n)
{
    double tong = sqrt(2);
    if (n == 1)
    {
        return tong;
    }
    if (n == 0)
    {
        return 2;
    }
    for (int i = 1; i < n; i++)
    {
        tong = sqrt(2 + tong);
    }
    return tong;
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(3));
    printf("\nHuy de quy S(n) = %f", HuyDeQuy(3));
    return 0;
}