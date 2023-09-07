#include <stdio.h>
#include <math.h>

/*
S(n) = sqrt(1+sqrt(2+sqrt(3+...sqrt(n-1+sqrt(n)))))
có n dấu căn: sqrt()
*/

double TinhDeQuy(int n, int x = 1)
{
    if (x == n)
    {
        return sqrt(n);
    }
    double pre = TinhDeQuy(n, x + 1);
    return sqrt(x + pre);
}

double HuyDeQuy(int n)
{
    double ketqua = n;
    for (int i = n; i > 1; i--)
    {
        ketqua = i - 1 + sqrt(ketqua);
    }
    return sqrt(ketqua);
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(5));
    printf("\nHuy de quy S(n) = %f", HuyDeQuy(5));
    return 0;
}