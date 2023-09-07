#include <stdio.h>

/*
S(n) = 1/(1+1/(1+1/(1+1)))
    1
-------
1 + 1
   -----
   1 + 1
      -----
      1 + 1
         -----
      ....  1
           -----
           1 + 1
             -----
             1 + 1
có n phân số:
*/

double TinhDeQuy(int n)
{
    if (n == 1)
    {
        return 1.0 / 2;
    }
    double pre = 1 + TinhDeQuy(n - 1); // pre = 1 + Tinhdequy(n - 1)
    return 1.0 / pre;                  // 1/(pre)
}

double HuyDeQuy(int n)
{
    double ketqua = 1.0 / 2;
    for (int i = n; i > 1; i--)
    {
        ketqua = 1.0 / (1 + ketqua);
    }
    return ketqua;
}

int main()
{
    printf("\nDe quy S(n) = %lf", TinhDeQuy(13));
    printf("\nHuy de quy S(n) = %f", HuyDeQuy(13));
    return 0;
}