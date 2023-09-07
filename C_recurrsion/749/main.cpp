#include <stdio.h>
#include <math.h>

/*
S(n) = sqrt(n+sqrt(n-1+sqrt(n-2+...sqrt(2+sqrt(1)))))
có n dấu căn: sqrt()
*/

double TinhDeQuy(int n)
{
    if (n == 1)
    {
        return 1;
    }
    double pre = TinhDeQuy(n - 1);
    return sqrt(n + pre);
}

double HuyDeQuy(int n)
{
    double ketqua = 1;
    for (int i = 1; i < n; i++)
    {
        ketqua = i + 1 + sqrt(ketqua);
    }
    return sqrt(ketqua);
}

int main()
{
    printf("\nDe quy S(n) = %f", TinhDeQuy(3));
    printf("\nHuy de quy S(n) = %f", HuyDeQuy(3));
    return 0;
}