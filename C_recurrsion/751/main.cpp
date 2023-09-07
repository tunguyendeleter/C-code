#include <stdio.h>
#include <math.h>

/*
S(n) = 
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
có n phân số: sqrt()
*/

double TinhDeQuy(int n)
{
    if (n == 1)
    {
        return 1;
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